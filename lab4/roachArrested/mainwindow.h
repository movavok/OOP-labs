#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QMouseEvent>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    bool event(QEvent*) override;
    void paintEvent(QPaintEvent*) override;

private:
    Ui::MainWindow *ui;
    int roachSize;
    int roachX, roachY;
    int speedX, speedY;
    int score = 0;

    QTimer *roachTimer;
    QPixmap roachUp, roachDown, roachLeft, roachRight, roachDead;
    QPixmap loadRoach(const QString&);

    bool drawing = false;
    bool roachCaught = false;
    QPolygon polygon;

private slots:
    void moveRoach();
};
#endif // MAINWINDOW_H
