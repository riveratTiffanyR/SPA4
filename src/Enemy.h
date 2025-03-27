#ifndef ENEMY_H
#define ENEMY_H
#include "Entity.h"
#include "Player.h"
class Enemy : public Entity {
public:
    Enemy(int x, int y);
    virtual void attack(Player* player) = 0;
};
#endif