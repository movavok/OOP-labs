#ifndef ROACHL2_H
#define ROACHL2_H

#include "roach.h"

class RoachL2 : public Roach
{
public:
    explicit RoachL2(QWidget *parent = nullptr);

    void move() override;
};

#endif // ROACHL2_H
