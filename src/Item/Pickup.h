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
