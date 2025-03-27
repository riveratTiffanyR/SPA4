#include "Clown.h"
Clown::Clown(int x, int y) : Enemy(x, y) {}
void Clown::attack(Player* player) {
    player->takeDamage(5);
}
