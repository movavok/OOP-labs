#include "roachl2.h"

RoachL2::RoachL2(QWidget *parent) : Roach(parent) {}

void RoachL2::move() {
    if (caught) return;

    Roach::move();

    if (sprite && sprite->parentWidget()) {
        QLabel* escapeLabel = sprite->parentWidget()->findChild<QLabel*>("l_escape");

        if (!escapeLabel) return;

        QRect escCollision = escapeLabel->geometry();
        QPoint escCenter = escCollision.center();

        if (posX < escCenter.x()) speedX += 0.1;
        else speedX -= 0.1;

        if (posY < escCenter.y()) speedY += 0.1;
        else speedY -= 0.1;

        speedX = qBound(-5.0, speedX, 5.0);
        speedY = qBound(-5.0, speedY, 5.0);
    }
}
