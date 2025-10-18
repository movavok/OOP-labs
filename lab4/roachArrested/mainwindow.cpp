#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    roachSize = 80;
    roachX = roachY = 100;
    speedX = speedY = 2;

    std::srand(std::time(nullptr));
    ui->l_score->setStyleSheet("font-weight: bold; font-size: 16pt;");

    roachUp = loadRoach("up");
    roachDown = loadRoach("down");
    roachLeft = loadRoach("left");
    roachRight = loadRoach("right");
    roachDead = loadRoach("dead");

    ui->l_roach->setPixmap(roachUp);
    ui->l_roach->setGeometry(roachX, roachY, roachSize, roachSize);

    ui->l_message->setStyleSheet("font-weight: bold; font-size: 16pt;");
    ui->l_message->setGeometry(0, 0, width(), height());
    ui->l_message->hide();

    roachTimer = new QTimer(this);
    connect(roachTimer, &QTimer::timeout, this, &MainWindow::moveRoach);
    roachTimer->start(5);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QPixmap MainWindow::loadRoach(const QString &direction) {
    return QPixmap(":/roach_" + direction + ".png")
        .scaled(80, 80, Qt::KeepAspectRatio, Qt::SmoothTransformation);
}

void MainWindow::moveRoach()
{
    if (roachCaught) return;

    if (rand() % 30 == 0) {
        speedX = (rand() % 7) - 3;
        speedY = (rand() % 7) - 3;
    }

    speedX = qBound(-10, speedX, 10);
    speedY = qBound(-10, speedY, 10);

    roachX += speedX;
    roachY += speedY;

    if (roachX <= 0 || roachX >= width() - ui->l_roach->width()) speedX = -speedX;
    if (roachY <= 0 || roachY >= height() - ui->l_roach->height()) speedY = -speedY;

    if (abs(speedX) > abs(speedY)) {
        if (speedX > 0) ui->l_roach->setPixmap(roachRight);
        else ui->l_roach->setPixmap(roachLeft);
    } else {
        if (speedY > 0) ui->l_roach->setPixmap(roachDown);
        else ui->l_roach->setPixmap(roachUp);
    }

    ui->l_roach->move(roachX, roachY);
}

bool MainWindow::event(QEvent *e)
{
    if (roachCaught && e->type() == QEvent::MouseButtonPress) {
        roachCaught = false;
        ui->l_message->hide();
        ui->l_roach->setPixmap(roachUp);
    }
    if (e->type() == QEvent::MouseButtonPress) {
        drawing = true;
        polygon.clear();
        polygon << static_cast<QMouseEvent*>(e)->pos();
        return true;
    }
    if (e->type() == QEvent::MouseMove && drawing) {
        polygon << static_cast<QMouseEvent*>(e)->pos();
        update();
        return true;
    }
    if (e->type() == QEvent::MouseButtonRelease && drawing) {
        drawing = false;

        QPoint center(roachX + roachSize/2, roachY + roachSize/2);
        if (polygon.containsPoint(center, Qt::OddEvenFill)){
            score++;
            ui->l_score->setText("Впіймано " + QString::number(score) + " р.");
            qDebug() << "Таракан спійманий" << score << "раз!";

            roachCaught = true;
            ui->l_roach->setPixmap(roachDead);
            ui->l_message->show();
        }

        polygon.clear();
        update();
        return true;
    }

    return QMainWindow::event(e);
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QMainWindow::paintEvent(event);
    QPainter p(this);
    QPixmap bg(":/floor.jpeg");
    p.drawPixmap(0, 0, width(), height(), bg);
    ui->scoreWidget->setGeometry(0, 0, ui->centralwidget->width(), ui->centralwidget->height());

    if (!polygon.isEmpty()) {
        QPainter p(this);
        p.setPen(QPen(Qt::red, 2));
        p.drawPolyline(polygon);
    }
}


