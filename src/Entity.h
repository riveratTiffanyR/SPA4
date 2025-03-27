#ifndef ENTITY_H
#define ENTITY_H
#include <QGraphicsRectItem>
class Entity : public QGraphicsRectItem {
protected:
    int health;
public:
    Entity(int h, int x, int y, int size);
    virtual void takeDamage(int amount);
};
#endif