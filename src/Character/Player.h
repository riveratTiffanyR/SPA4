#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player : public Entity {
public:
    Player(int x, int y);
    void pickupWeapon();
    void pickupHealth();
};

#endif