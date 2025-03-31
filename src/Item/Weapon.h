/*
* Course: CSC 2210 - Procedural and OO C++
 * Section: 001
 * Assignment: SPA4
 * Names: Tiffany Rivera, Eleanor Certalic, Madison Betz
 * Date Due: 02/21/2025
 */

#ifndef WEAPON_H
#define WEAPON_H
#include "Pickup.h"

class Weapon : public Pickup {
public:
    Weapon(int x, int y);
};

#endif //WEAPON_H