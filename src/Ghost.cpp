#include "Ghost.h"
Ghost::Ghost(int x, int y) : Enemy(x, y) {}
void Ghost::attack(Player* player) {
    player->takeDamage(10);
}
