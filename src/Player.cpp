#include "Player.h"

#include <QGraphicsScene>

#include "Clown.h"
#include "Enemy.h"
#include "Ghost.h"

extern int clownCount;

Player::Player(int x, int y) : Entity(20, x, y, 30) {}

void Player::keyPressEvent(QKeyEvent *event) {
    int step = 10;
    qreal newX = x(), newY = y();

    if (event->key() == Qt::Key_Left) newX -= step;
    else if (event->key() == Qt::Key_Right) newX += step;
    else if (event->key() == Qt::Key_Up) newY -= step;
    else if (event->key() == Qt::Key_Down) newY += step;

    // Get scene boundaries
    if (scene()) {
        QRectF sceneBounds = scene()->sceneRect();
        qreal minX = -50;
        qreal minY = -50;
        qreal maxX = 320;
        qreal maxY = 320;

        // Clamp position within bounds
        newX = qMax(minX, qMin(newX, maxX));
        newY = qMax(minY, qMin(newY, maxY));

        setPos(newX, newY);
    }

    QList<QGraphicsItem *> collidingItemsList = collidingItems();
    for (QGraphicsItem *item : collidingItemsList) {
        if (dynamic_cast<Clown*>(item)) {
            // If colliding with a Clown
            scene()->removeItem(item);
            delete item;
            clownCount--; // Reduce clown count

            // Increase player size
            qreal newWidth = rect().width() + 5;
            qreal newHeight = rect().height() + 5;
            setRect(0, 0, newWidth, newHeight);
        } else if (dynamic_cast<Ghost*>(item)) {
            if (clownCount == 0) {
                // Player wins
                QGraphicsScene *currentScene = scene();
                currentScene->clear();  // Remove all items from scene

                // Display "You Win"
                QGraphicsTextItem *loseText = new QGraphicsTextItem("You Win");
                QFont font("Arial", 32, QFont::Bold);
                loseText->setFont(font);
                loseText->setDefaultTextColor(Qt::red);
                loseText->setPos(currentScene->width() / 2 - 80, currentScene->height() / 2 - 20);
                currentScene->addItem(loseText);
            } else {
                // Player loses
                QGraphicsScene *currentScene = scene();
                currentScene->clear();  // Remove all items from scene

                // Display "You Lose"
                QGraphicsTextItem *loseText = new QGraphicsTextItem("You Lose");
                QFont font("Arial", 32, QFont::Bold);
                loseText->setFont(font);
                loseText->setDefaultTextColor(Qt::blue);
                loseText->setPos(currentScene->width() / 2 - 80, currentScene->height() / 2 - 20);
                currentScene->addItem(loseText);

                return;
            }
        }
    }

}