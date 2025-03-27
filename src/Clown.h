#ifndef CLOWN_H
#define CLOWN_H
#include "Enemy.h"
class Clown : public Enemy {
public:
    Clown(int x, int y);
    void attack(Player* player) override;
};
#endif