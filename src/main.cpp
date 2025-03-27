#include <iostream>
#include <QApplication>
#include <QGraphicsScene>
#include <QRandomGenerator>
#include <QGraphicsView>
#include "Player.h"
#include "Ghost.h"
#include "Clown.h"

int clownCount = 0;

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    int sceneWidth = 400;
    int sceneHeight = 400;

    QGraphicsScene scene(0, 0, sceneWidth, sceneHeight);  // Define a 400x400 scene


    Player* player = new Player(50, 50);
    scene.addItem(player);
    player->setBrush(Qt::red);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    auto getRandomPosition = [&sceneWidth, &sceneHeight]() -> QPointF {
        qreal x = QRandomGenerator::global()->bounded(50, 320);
        qreal y = QRandomGenerator::global()->bounded(50, 320);
        return QPointF(x, y);
    };

    QPointF ghostPos = getRandomPosition();
    Enemy* ghost = new Ghost(ghostPos.x(), ghostPos.y());
    scene.addItem(ghost);
    ghost->setBrush(Qt::blue);

    for (int i = 0; i < 5; i++) {
        QPointF clownPos = getRandomPosition();
        Enemy* clown = new Clown(clownPos.x(), clownPos.y());
        scene.addItem(clown);
        clown->setBrush(Qt::yellow);
        clownCount++;
    }

    // Add Black Border
    QGraphicsRectItem *border = new QGraphicsRectItem(0, 0, sceneWidth, sceneHeight);
    border->setPen(QPen(Qt::black, 5));  // Black border with thickness 5
    scene.addItem(border);

    QGraphicsView view(&scene);
    view.setScene(&scene);
    view.setFixedSize(sceneWidth + 10, sceneHeight + 10);  // Keep some padding for the border
    view.show();
    return app.exec();
}