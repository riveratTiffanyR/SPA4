#include "Entity.h"
Entity::Entity(int h, int x, int y, int size) : health(h) {
    setRect(x, y, size, size);
}
void Entity::takeDamage(int amount) {
    health -= amount;
    if (health <= 0) delete this;
}