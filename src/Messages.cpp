/*
* Course: CSC 2210 - Procedural and OO C++
 * Section: 001
 * Assignment: SPA4
 * Names: Tiffany Rivera, Eleanor Certalic, Madison Betz
 * Date Due: 02/21/2025
 */

#include "Messages.h"
#include "Character/Player.h"
#include <iostream>
using namespace std;

void Messages::displayIntro() {
    cout << "Welcome to our Haunted House! You wake up in an empty room, trapped inside" << endl
         << "of an unfamiliar house with no memories. Looking around the dark gloomy room," << endl
         << "all you see is a working flashlight at your feet. Feeling a dark presence, your" << endl
         << "body fills with fear as you pick up your only defense and all you can think of" << endl
         << "is the desperate need to run." << endl << endl;
    cout << "Are you ready to run?" << endl;
    cout << "     (y) Yes, I am ready" << endl;
    cout << "     (n) No, I want to know what lies ahead first" << endl;
    cout << "     (q) Quit the game" << endl;
}

void Messages::displayHelpRoom() {
    cout << "As you travel through the rooms, you may either:" << endl;
    cout << "Find a weapon to use to attack the threats (or leave it there for later)" << endl;
    cout << "Find an item to regain your health (or leave it there for later)" << endl;
    cout << "Encounter an enemy to fight (or try to flee)" << endl << endl;
}

void Messages::displayHelpMove() {
    cout << "Note: Only you can move. The Ghost and the Clowns will not move." << endl
         << "All items and enemies will be randomly assigned new locations for" << endl
         << "every game, and will not leave their respective room." << endl << endl;
}

void Messages::displayExtraStory() {
    cout << "You are currently trapped inside of a 20x20-room single-floor haunted house," << endl
         << "along with 8 psychotic clowns and a powerful angry ghost that wants you gone" << endl
         << "by any means necessary. You can either find the exit and escape this place, or" << endl
         << "you can fight your way into keeping this house for yourself (a few small" << endl
         << "renovations and you got yourself a dream home, right?)." << endl << endl;
    displayHelpRoom();
    displayHelpMove();
    cout << "Are you ready to run?" << endl;
    cout << "     (y) Yes, I am better prepared and feel ready now" << endl;
    cout << "     (n) No, I am not ready" << endl;
    cout << "     (q) Quit the game" << endl;
}

void Messages::quitGame() {
    cout << "You have decided to cry and hide instead of escaping or fighting. Quitting the game..." << endl;
}

void Messages::displayHelpInGame() {
    displayHelpRoom();
    displayHelpMove();
    cout << "Would you like to view the full map?" << endl;
    cout << "     (y) Yes, I need the help!" << endl;
    cout << "     (n) No, I got this!" << endl;
    cout << "     (q) Quit Game" << endl;
}

void Messages::displayPlayer(const Player &player) {
    cout << "Player Health: " << player.getHealth() << endl;
    cout << "Player Position (x, y): (" <<
        player.getX() << ", " << player.getY() << ")" << endl;
}

void Messages::displayMovePrompt() {
    cout << "Where would you like to go?" << endl;
    cout << "     (f) Forward" << endl;
    cout << "     (b) Backward" << endl;
    cout << "     (l) Left" << endl;
    cout << "     (r) Right" << endl;
    cout << "     (h) Help" << endl;
    cout << "     (q) Quit" << endl;
}

void Messages::roomEscape() {
    cout << "Would you like to escape?" << endl;
    cout << "     (y) Yes, I need to escape this terrifying place!" << endl;
    cout << "     (n) No, I want to take this house for myself! (Gain 100 Health)" << endl;
    cout << "     (q) Quit Game" << endl;
}

void Messages::gain100Health(int playerHealth) {
    cout << "You decide to face your fears and embrace your courage!" << endl
         << "Current Player Health: " << playerHealth << endl << endl;
}

void Messages::alreadyGained100Health() {
    cout << "Very sneaky. But you already got the bonus." << endl << endl;
}


void Messages::roomHealth() {
    cout << "Would you like to use it?" << endl;
    cout << "     (y) Yes, I would like to gain 10 health!" << endl;
    cout << "     (n) No, I would like to leave it here for later" << endl;
    cout << "     (q) Quit Game" << endl;
}

void Messages::roomWeapon() {
    cout << "Would you like to pick it up?" << endl;
    cout << "     (y) Yes, I would like to gain 10 attack damage!" << endl;
    cout << "     (n) No, I would like to leave it here for later" << endl;
    cout << "     (q) Quit Game" << endl;
}

void Messages::leaveItem() {
    cout << "You decide to leave it here for now." << endl << endl;
}

void Messages::pickupHealth(const int choice, const int health) {
    if (choice == 1) {
        cout << "You take the food and eat it." << endl;
    } else if (choice == 2) {
        cout << "You take the medicine and drink it." << endl;
    } else if (choice == 3) {
        cout << "You take the bandages and use them." << endl;
    }
    cout << "Current health: " << health << endl;
}

void Messages::pickupWeapon(const int choice, const int attackDamage) {
    if (choice == 1) {
        cout << "You take the sharp sword." << endl;
    } else if (choice == 2) {
        cout << "You take the knife." << endl;
    } else if (choice == 3) {
        cout << "You take the hammer." << endl;
    }
    cout << "Current attack damage: " << attackDamage << endl;
}

void Messages::combatChoice() {
    cout << "What do you want to do?" << endl;
    cout << "     (a) Attack!" << endl;
    cout << "     (e) Escape" << endl;
    cout << "     (q) Quit Game" << endl;
}

void Messages::clownDead() {
    cout << "The clown is dead." << endl;
}

void Messages::ghostDead() {
    cout << "The ghost is dead." << endl;
}

void Messages::playerAttack() {
    cout << "You prepare to attack" << endl;;
}

void Messages::playerAttackSuccess(int damage) {
    cout << " and strike your enemy for " << damage << " damage!" << endl << endl;
}

void Messages::playerAttackFail() {
    cout << " and miss your enemy!" << endl << endl;
}

void Messages::playerEscapeSuccess() {
    cout << "Your enemy is distracted and you can get away without them noticing!" << endl << endl;
}

void Messages::playerEscapeFail() {
    cout << "You try to escape, but your enemy charges at you!" << endl << endl;
}

void Messages::clownAttack() {
    cout << "The clown prepares to attack" << endl;
}

void Messages::clownAttackSuccess(int damage) {
    cout << " and strikes you for " << damage << " damage!" << endl << endl;
}

void Messages::clownAttackFail() {
    cout << " and you dodge it successfully!" << endl << endl;
}

void Messages::ghostAttack() {
    cout << "The ghost prepares to attack" << endl;
}

void Messages::ghostAttackSuccess(int damage) {
    cout << " and strikes you for " << damage << " damage!" << endl << endl;
}

void Messages::ghostAttackFail() {
    cout << " and you dodge it successfully!" << endl << endl;
}

void Messages::displayHealthStatus(int playerHealth, int enemyHealth, bool isClown) {
    cout << "Current Player Health: " << playerHealth << endl;
    if (isClown) {
        cout << "Current Clown Health: " << enemyHealth << endl << endl;;
    } else {
        cout << "Current Ghost Health: " << enemyHealth << endl << endl;;
    }
}

void Messages::gameWinEscape() {
    cout << "Congratulations, you escaped!" << endl;
}

void Messages::gameWinGhostDead() {
    cout << "Congratulations, you have defeated the angry ghost" << endl
         << "and the house is now yours!" << endl;
}

void Messages::gameLose() {
    cout << "You have been defeated. The house has claimed your" << endl
         << "soul to roam here for eternity." << endl;
}