#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QMouseEvent>
#include <QPainter>
#include "roachl2.h"
#include "roach.h"

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
    QPixmap loadRoach(const QString&);
    void checkEscape();
    int score = 0;
    int level = 1;

    bool drawing = false;
    QPolygon polygon;

    Roach *roach = nullptr;
    QTimer *roachTimer;

private slots:
    void updateRoach();
};

#endif // MAINWINDOW_H
