#ifndef ENTITY_H
#define ENTITY_H
class Entity {
protected:
    int x;
    int y;
    int health;
    int attackDamage;
    static int getRandomNumber(int min, int max);


public:
    Entity(int x, int y, int health, int attackDamage);

    bool attackAttempt();
    int dealDamage();
    void takeDamage(int damageToTake);

    int getX() const;
    int getY() const;
    void setX(int newX);
    void setY(int newY);
    int getHealth() const;
    void setHealth(int addHealth);
    int getAttackDamage() const;
    void setAttackDamage(int addDamage);
};
#endif