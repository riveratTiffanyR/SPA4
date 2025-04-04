/*
* Course: CSC 2210 - Procedural and OO C++
 * Section: 001
 * Assignment: SPA4
 * Names: Tiffany Rivera, Eleanor Certalic, Madison Betz
 * Date Due: 02/21/2025
 */

#ifndef MESSAGES_H
#define MESSAGES_H
#include "Character/Player.h"

class Messages {
public:
    static void displayIntro();
    static void displayExtraStory();

    static void displayHelpRoom();
    static void displayHelpMove();
    static void displayHelpInGame();

    static void displayPlayer(const Player &player);
    static void displayMovePrompt();
    static void displayHealthStatus(int playerHealth, int enemyHealth, bool isClown);

    static void roomEscape();
    static void gain100Health(int playerHealth);
    static void alreadyGained100Health();

    static void roomHealth();
    static void roomWeapon();
    static void leaveItem();
    static void pickupHealth(int choice, int health);
    static void pickupWeapon(int choice, int attackDamage);

    static void combatChoice();
    static void playerAttack();
    static void playerAttackSuccess(int damage);
    static void playerAttackFail();
    static void playerEscapeSuccess();
    static void playerEscapeFail();
    static void clownAttack();
    static void clownAttackSuccess(int damage);
    static void clownAttackFail();
    static void ghostAttack();
    static void ghostAttackSuccess(int damage);
    static void ghostAttackFail();

    static void clownDead();
    static void ghostDead();
    static void quitGame();
    static void gameWinGhostDead();
    static void gameWinEscape();
    static void gameLose();
};

#endif //MESSAGES_H
