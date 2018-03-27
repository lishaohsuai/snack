#include "snack.h"

Snack::Snack():
    length(3),
    speed(1),
    direction(SNACK_LEFT),
    alive(true)
{}

Snack::~Snack()
{}

bool Snack::_Run(DIRECTION dir)
{
    //蛇运动的函数
}
