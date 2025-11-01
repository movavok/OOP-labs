#ifndef ROACH_H
#define ROACH_H

#include <QLabel>
#include <QPixmap>
#include <QObject>
#include <QWidget>
#include <QTimer>
#include <QRandomGenerator>

class Roach : public QObject
{
    Q_OBJECT
public:
    explicit Roach(QWidget *parent = nullptr);

    virtual void move();
    void setPosition(int, int);
    void setSpeed(int, int);

    void setPixmaps(const QPixmap &up, const QPixmap &down,
                    const QPixmap &left, const QPixmap &right,
                    const QPixmap &dead);
    void setDeadPixmap();

    void show();
    void hide();

    QRect getCollision() const;

    QLabel *sprite;
    int posX, posY;
    double speedX, speedY;
    bool caught = false;

protected:
    QPixmap roachUp, roachDown, roachLeft, roachRight, roachDead;
};

#endif // ROACH_H
