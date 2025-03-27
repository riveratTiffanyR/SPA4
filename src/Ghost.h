#ifndef GHOST_H
#define GHOST_H
#include "Enemy.h"
class Ghost : public Enemy {
public:
    Ghost(int x, int y);
    void attack(Player* player) override;
};
#endif