/*
* Course: CSC 2210 - Procedural and OO C++
 * Section: 001
 * Assignment: SPA4
 * Names: Tiffany Rivera, Eleanor Certalic, Madison Betz
 * Date Due: 02/21/2025
 */

#include "Player.h"
#include <iostream>
#include "../Map.h"

using namespace std;

Player::Player(int x, int y) : Entity(x, y, 100, 5) {}

void Player::pickupWeapon() {
    setAttackDamage(getAttackDamage() + 10);
}

void Player::pickupHealth() {
    setHealth(getHealth() + 10);
}