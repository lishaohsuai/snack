#ifndef __SNACK_H__
#define __SNACK_H__

#include <iostream>

typedef enum DIRECTION
{ SNACK_UP,SNACK_DOWN,SNACK_LEFT,SNACK_RIGHT };

class Snack
{
public:
    Snack();
    ~Snack();
    bool _Run(DIRECTION dir);
private:
    int length;
    int speed;
    int direction;
    bool alive;
}

#endif




