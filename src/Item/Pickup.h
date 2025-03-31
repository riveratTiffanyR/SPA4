/*
* Course: CSC 2210 - Procedural and OO C++
 * Section: 001
 * Assignment: SPA4
 * Names: Tiffany Rivera, Eleanor Certalic, Madison Betz
 * Date Due: 02/21/2025
 */

#ifndef PICKUP_H
#define PICKUP_H

class Pickup {
protected:
    int x;
    int y;
    int action;

public:
    Pickup(int x, int y, int action);

    int getX() const;
    int getY() const;
    void setX(int newX);
    void setY(int newY);
    int getAction() const;
};

#endif //PICKUP_H
