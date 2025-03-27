#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"
#include <QKeyEvent>
class Player : public Entity {
public:
    Player(int x, int y);
    void keyPressEvent(QKeyEvent *event) override;
};
#endif