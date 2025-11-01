#include "roach.h"

Roach::Roach(QWidget *parent)
    : QObject(parent)
{
    sprite = new QLabel(parent);
    sprite->setGeometry(100, 100, 80, 80);

    posX = posY = 100;
    speedX = speedY = 2;

    sprite->move(posX, posY);
    sprite->show();
}

void Roach::setPosition(int x, int y)
{
    posX = x;
    posY = y;
    sprite->move(posX, posY);
}

void Roach::setSpeed(int sx, int sy)
{
    speedX = sx;
    speedY = sy;
}

void Roach::setPixmaps(const QPixmap &up, const QPixmap &down,
                       const QPixmap &left, const QPixmap &right,
                       const QPixmap &dead)
{
    roachUp = up;
    roachDown = down;
    roachLeft = left;
    roachRight = right;
    roachDead = dead;

    sprite->setPixmap(roachUp);
}

void Roach::setDeadPixmap() { sprite->setPixmap(roachDead); }

void Roach::show() { sprite->show(); }
void Roach::hide() { sprite->hide(); }

QRect Roach::getCollision() const { return sprite->geometry(); }

void Roach::move() {
    if (caught) return;

    if (rand() % 30 == 0) {
        speedX = (rand() % 7) - 3;
        speedY = (rand() % 7) - 3;
    }

    speedX = qBound(-10.0, speedX, 10.0);
    speedY = qBound(-10.0, speedY, 10.0);

    posX += speedX;
    posY += speedY;

    if (posX <= 0 || posX >= sprite->parentWidget()->width() - sprite->width()) speedX = -speedX;
    if (posY <= 0 || posY >= sprite->parentWidget()->height() - sprite->height()) speedY = -speedY;

    if (abs(speedX) > abs(speedY)) {
        sprite->setPixmap(speedX > 0 ? roachRight : roachLeft);
    } else {
        sprite->setPixmap(speedY > 0 ? roachDown : roachUp);
    }

    sprite->move(posX, posY);
}
