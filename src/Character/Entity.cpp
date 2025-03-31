#include "Entity.h"

#include <stdlib.h>

Entity::Entity(int x, int y, int health, int attackDamage) {
    this->x = x;
    this->y = y;
    this->health = health;
    this->attackDamage = attackDamage;
}

int Entity::getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

bool Entity::attackAttempt() {
    return getRandomNumber(1, 2) == 1;
}
int Entity::dealDamage() {
    return attackDamage;
}
void Entity::takeDamage(int damageToTake) {
    setHealth(health - damageToTake);
    if (health < 0) {
        setHealth(0);
    }
}

int Entity::getX() const {return x;}
int Entity::getY() const {return y;}
int Entity::getHealth() const {return health;}
int Entity::getAttackDamage() const {return attackDamage;}

void Entity::setX(const int newX) {x = newX;}
void Entity::setY(const int newY) {y = newY;}
void Entity::setHealth(int newHealth) {health = newHealth;}
void Entity::setAttackDamage(int newDamage) {attackDamage = newDamage;}