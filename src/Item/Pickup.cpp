#include "Pickup.h"

Pickup::Pickup(int x, int y, int action) {
    this->x = x;
    this->y = y;
    this->action = action;
}

int Pickup::getX() const {return x;}
int Pickup::getY() const {return y;}
int Pickup::getAction() const {return action;}

void Pickup::setX(const int newX) {x=newX;}
void Pickup::setY(const int newY) {y=newY;}