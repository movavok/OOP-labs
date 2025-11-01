#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Гра впіймай таргана!");

    srand(time(nullptr));
    ui->l_score->setStyleSheet("font-weight: bold; font-size: 16pt;");

    roach = new Roach(this);
    roach->setPixmaps(
        loadRoach("up"),
        loadRoach("down"),
        loadRoach("left"),
        loadRoach("right"),
        loadRoach("dead")
        );

    roach->setPosition(100, 100);
    roach->show();

    ui->l_message->setStyleSheet("font-weight: bold; font-size: 16pt; qproperty-alignment: 'AlignCenter';");
    ui->l_message->setGeometry(0, 0, width(), height());
    ui->l_message->hide();

    QPixmap esc(":/escape.png");
    ui->l_escape->setPixmap(esc.scaled(200, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->l_escape->setGeometry(300, -15, 200, 100);
    ui->l_escape->hide();

    roachTimer = new QTimer(this);
    connect(roachTimer, &QTimer::timeout, roach, &Roach::move);
    roachTimer->start(10);
}

MainWindow::~MainWindow()
{
    if (roachTimer) roachTimer->stop();
    delete ui;
}

QPixmap MainWindow::loadRoach(const QString &direction) {
    return QPixmap(":/roach_" + direction + ".png")
        .scaled(80, 80, Qt::KeepAspectRatio, Qt::SmoothTransformation);
}

void MainWindow::updateRoach() {
    if (roach) roach->move();
    checkEscape();
}

void MainWindow::checkEscape() {
    if (roach && ui->l_escape->isVisible() &&
        ui->l_escape->geometry().contains(roach->getCollision().center()) && !roach->caught)
    {
        roach->caught = true;
        ui->l_message->setText("Тарган втік! \nНатисніть, щоб продовжити!");
        ui->l_message->show();

        if (score > 5) score -= 1;
        ui->l_score->setText("Рівень " + QString::number(level) + ". Впіймано " + QString::number(score) + " р.");
    }
}

bool MainWindow::event(QEvent *event)
{
    if (roach && roach->caught && event->type() == QEvent::MouseButtonPress) {
        roach->caught = false;
        if (ui && ui->l_message) ui->l_message->hide();

        if (ui->l_escape->isVisible()) {
            int maxX = ui->centralwidget->width() - roach->sprite->width();
            int maxY = ui->centralwidget->height() - roach->sprite->height();
            int x = rand() % maxX;
            int y = rand() % maxY;
            roach->setPosition(x,y);
        }

        if (score >= 10) close();
    }
    if (event->type() == QEvent::MouseButtonPress) {
        drawing = true;
        polygon.clear();
        polygon << static_cast<QMouseEvent*>(event)->pos();
        return true;
    }
    if (event->type() == QEvent::MouseMove && drawing) {
        polygon << static_cast<QMouseEvent*>(event)->pos();
        update();
        return true;
    }
    if (event->type() == QEvent::MouseButtonRelease && drawing) {
        drawing = false;

        if (roach && polygon.containsPoint(roach->getCollision().center(), Qt::OddEvenFill)){
            score++;
            ui->l_score->setText("Рівень " + QString::number(level) + ". Впіймано " + QString::number(score) + " р.");
            qDebug() << "Тарган спійманий" << score << "раз!";

            if (level == 1 && score >= 5) {
                level = 2;
                qDebug() << "Рівень 2!";

                ui->l_escape->show();

                QPoint oldPos;

                if (roach) {
                    oldPos = roach->getCollision().topLeft();
                    disconnect(roachTimer, nullptr, roach, nullptr);
                    roach->hide();
                    roach->deleteLater();
                    roach = nullptr;
                }

                roach = new RoachL2(this);
                roach->setPixmaps(
                    loadRoach("up"),
                    loadRoach("down"),
                    loadRoach("left"),
                    loadRoach("right"),
                    loadRoach("dead")
                    );
                roach->setPosition(oldPos.x(), oldPos.y());
                roach->setSpeed(1,1);
                roach->show();

                connect(roachTimer, &QTimer::timeout, this, &MainWindow::updateRoach);
            }

            if (score >= 10) {
                roach->caught = true;
                roach->setDeadPixmap();
                ui->l_message->setText("Перемога! \nНатисніть, щоб вийти!");
                ui->l_message->show();
                return true;
            }

            roach->caught = true;
            roach->setDeadPixmap();
            ui->l_message->setText("Натисніть, щоб продовжити!");
            ui->l_message->show();
        }

        polygon.clear();
        update();
        return true;
    }

    return QMainWindow::event(event);
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QMainWindow::paintEvent(event);
    QPainter painter(this);
    QPixmap bg(":/floor.jpeg");
    painter.drawPixmap(0, 0, width(), height(), bg);
    ui->scoreWidget->setGeometry(0, 0, ui->centralwidget->width(), ui->centralwidget->height());

    if (!polygon.isEmpty()) {
        painter.setPen(QPen(Qt::red, 2));
        painter.drawPolyline(polygon);
    }
}
