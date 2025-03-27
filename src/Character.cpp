#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QTimer>
#include <QList>
#include <cstdlib>

// Base class for all characters
class Character : public QGraphicsPixmapItem {
public:
    int health;
    Character(int hp) : health(hp) {}
    virtual void attack() = 0; // Pure virtual function
};