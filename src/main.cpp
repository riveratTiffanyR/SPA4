/*
 * Course: CSC 2210 - Procedural and OO C++
 * Section: 001
 * Assignment: SPA4
 * Names: Tiffany Rivera, Eleanor Certalic, Madison Betz
 * Date Due: 02/21/2025
 */

#include <iostream>
#include <string>
#include "Character/Player.h"
#include "Character/Entity.h"
#include "Map.h"
#include "Messages.h"

using namespace std;

string YNQ = "yYnNqQ"; //Yes No Quit
string AEQ = "aAeEqQ"; //Attack Escape Quit
string FBLRHQ = "fFbBlLrRhHqQ"; //Forward Backward Left Right Help Quit
bool playerDead = false;
bool clownDead = false;
bool ghostDead = false;
bool gameQuit = false;
bool gameWinGhostDead = false;
bool gameWinEscape = false;
bool gameLose = false;
bool healthBonus = false;

int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void escapeHouse(char response, Player* player, Map* map) {
    Messages messages;
    if (response == 'y' || response == 'Y') { //Escape and Game Over
        gameWinEscape = true;
    } else if (response == 'n' || response == 'N') { //Stay and Gain 100 Health
        if (!healthBonus) {
            player->setHealth(player->getHealth() + 100);
            messages.gain100Health(player->getHealth());
            healthBonus = true;
        } else {
            messages.alreadyGained100Health();
        }

    } else { //Quit the game
        gameQuit = true;
    }
}

void pickupHealth(char response, Player* player, Map* map) {
Messages messages;
    if (response == 'y' || response == 'Y') { //Pick it up
        player->pickupHealth();
        map->emptyTheRoom(player->getX(), player->getY());
        messages.pickupHealth(getRandomNumber(1, 3), player->getHealth());
    } else if (response == 'n' || response == 'N') { //Leave it there
        messages.leaveItem();
    } else { //Quit the game
        gameQuit = true;
    }
}

void pickupWeapon(char response, Player* player, Map* map) {
    Messages messages;
    if (response == 'y' || response == 'Y') { //Pick it up
        player->pickupWeapon();
        map->emptyTheRoom(player->getX(), player->getY());
        messages.pickupWeapon(getRandomNumber(1, 3), player->getAttackDamage());
    } else if (response == 'n' || response == 'N') { //Leave it there
        messages.leaveItem();
    } else { //Quit the game
        gameQuit = true;
    }
}

int playerAttack(Player* player) {
    Messages messages;
    int chance = getRandomNumber(1, 10);
    messages.playerAttack();
    if (chance <= 2) { //20% Attack Failure
        messages.playerAttackFail();
        return 0;
    } else { //80% Attack Success
        int damage = player->getAttackDamage();
        messages.playerAttackSuccess(damage);
        return damage;
    }
}

int clownAttack(Clown* clown) {
    Messages messages;
    int chance = getRandomNumber(1, 10);
    messages.clownAttack();
    if (chance <= 2) { //20% Attack Failure
        messages.clownAttackFail();
        return 0;
    } else { //80% Attack Success
        int damage = clown->getAttackDamage();
        messages.clownAttackSuccess(damage);
        return damage;
    }
}

int ghostAttack(Ghost* ghost) {
    Messages messages;
    int chance = getRandomNumber(1, 10);
    messages.ghostAttack();
    if (chance <= 2) { //20% Attack Failure
        messages.ghostAttackFail();
        return 0;
    } else { //80% Attack Success
        int damage = ghost->getAttackDamage();
        messages.ghostAttackSuccess(damage);
        return damage;
    }
}

void combatClown(char response, Player* player, Map* map) {
    if (response == 'q' || response == 'Q') { //Quit
        gameQuit = true;
    } else {
        Messages messages;
        Clown* clown = map->getClown(player->getX(), player->getY());
        if (response == 'a' || response == 'A') { //Attack
            //Player Attacks
            int damageToClown = playerAttack(player);
            clown->takeDamage(damageToClown);
        } else if (response == 'e' || response == 'E') { //Escape
            int chance = getRandomNumber(1, 50);
            if (chance == 1) {
                messages.playerEscapeSuccess();
            } else {
                messages.playerEscapeFail();
            }
        }
        //Check Clown Health
        int clownHealth = clown->getHealth();
        if (clownHealth <= 0) { //Clown Dies and Combat Over
            clownDead = true;
        } else {
            //Clown Attacks
            int damageToPlayer = clownAttack(clown);
            player->takeDamage(damageToPlayer);

            //Check Player Health
            int playerHealth = player->getHealth();
            if (playerHealth <= 0) { //Player Dies and Game Over
                gameLose = true;
                playerDead = true;
            } else {
                //Display Health Status
                messages.displayHealthStatus(playerHealth, clownHealth, true);
            }
        }
    }
}

void combatGhost(char response, Player* player, Map* map) {
    if (response == 'q' || response == 'Q') { //Quit
        gameQuit = true;
    } else {
        Messages messages;
        Ghost* ghost = map->getGhost();
        if (response == 'a' || response == 'A') { //Attack
            //Player Attacks
            int damageToGhost = playerAttack(player);
            ghost->takeDamage(damageToGhost);
        } else if (response == 'e' || response == 'E') { //Escape
            int chance = getRandomNumber(1, 50);
            if (chance == 1) {
                messages.playerEscapeSuccess();
            } else {
                messages.playerEscapeFail();
            }
        }
        //Check Ghost Health
        int ghostHealth = ghost->getHealth();
        if (ghostHealth <= 0) { //Ghost Dies and Game Over
            ghostDead = true;
            gameWinGhostDead = true;
        } else {
            //Ghost Attacks
            int damageToPlayer = ghostAttack(ghost);
            player->takeDamage(damageToPlayer);

            //Check Player Health
            int playerHealth = player->getHealth();
            if (playerHealth <= 0) { //Player Dies and Game Over
                gameLose = true;
                playerDead = true;
            } else {
                //Display Health Status
                messages.displayHealthStatus(playerHealth, ghostHealth, false);
            }
        }
    }
}

void roomAction(RoomType contents, Player* player, Map* map) {
    Messages messages;
    char response;
    switch (contents) {
        case RoomType::EMPTY:
            cout << "This room is empty." << endl;
            break;
        case RoomType::ESCAPE:
            cout << "You found the exit!" << endl;
            do {
                messages.roomEscape();
                cin >> response;
            } while (YNQ.find(response) == std::string::npos);
            escapeHouse(response, player, map);
            break;
        case RoomType::HEALTH:
            cout << "You have discovered a health item!" << endl;
            do {
                messages.roomHealth();
                cin >> response;
            } while (YNQ.find(response) == std::string::npos);
            pickupHealth(response, player, map);
            break;
        case RoomType::WEAPON:
            cout << "You have discovered a weapon!" << endl;
            do {
                messages.roomWeapon();
                cin >> response;
            } while (YNQ.find(response) == std::string::npos);
            pickupWeapon(response, player, map);
            break;
        case RoomType::CLOWN:
            clownDead = false;
            cout << "A psychotic clown is in here!" << endl;
            do {
                do {
                    messages.combatChoice();
                    cin >> response;
                } while (AEQ.find(response) == std::string::npos);
                combatClown(response, player, map);
            } while (!gameQuit && !clownDead && !playerDead);
            if (clownDead) {
                messages.clownDead();
            }
            break;
        case RoomType::GHOST:
            ghostDead = false;
            cout << "The angry ghost is in here!" << endl;
            do {
                do {
                    messages.combatChoice();
                    cin >> response;
                } while (AEQ.find(response) == std::string::npos);
                combatGhost(response, player, map);
            } while (!gameQuit && !ghostDead && !playerDead);
            if (ghostDead) {
                messages.ghostDead();
            }
            break;
    }
}

void playGame() {
    //Setup Game
    Messages messages;
    Player player(0,0);
    Map map(&player);
    char response;

    //Start Game
    while (!gameQuit && !gameLose && !gameWinGhostDead && !gameWinEscape) {
        messages.displayPlayer(player);
        bool valid = true;
        //Move Player
        do {

            //Input Validation
            do {
                messages.displayMovePrompt();
                cin >> response;
            } while (FBLRHQ.find(response) == std::string::npos);

            if (response == 'h' || response == 'H') {

                //Input Validation
                do {
                    messages.displayHelpInGame();
                    cin >> response;
                } while (YNQ.find(response) == std::string::npos);
                if (response == 'y' || response == 'Y') {map.displayMap();}
                else if (response == 'q' || response == 'Q') {gameQuit = true;}
            } else if (response == 'q' || response == 'Q') {
                gameQuit = true;
            } else {
                valid = map.movePlayer(response);
            }
        } while (!valid &&!gameQuit);
        //Check Room
        RoomType contents = map.getRoomContents(player.getX(), player.getY());
        //Room Action
        roomAction(contents, &player, &map);
    }
}

int main() {
    char response;
    Messages messages;

    //Input Validation
    do {
        messages.displayIntro();
        cin >> response;
    } while (YNQ.find(response) == std::string::npos);

    do {
        if (response == 'y' || response == 'Y') { //Play Game
            playGame();
        } else if (response == 'n' || response == 'N') { //Display Extra Story

            //Input Validation
            do {
                messages.displayExtraStory();
                cin >> response;
            } while (YNQ.find(response) == std::string::npos);

            if (response == 'n' || response == 'N') {
                cout << "That's too bad. Start running!" << endl;
                playGame();
            }
            if (response == 'y' || response == 'Y') {
                playGame();
            } else {
                gameQuit = true;
            }
        } else if (response == 'q' || response == 'Q') { //Quit Game
            gameQuit = true;
        }
    } while (!gameQuit && !gameWinEscape && !gameWinGhostDead && !gameLose);

    //Ending Win by Killing Ghost
    if (gameWinGhostDead) {
        messages.gameWinGhostDead();
    //Ending Win by Escape
    } else if (gameWinEscape) {
        messages.gameWinEscape();
    //Ending Lose
    } else if (gameLose) {
        messages.gameLose();
    } else {
        messages.quitGame();
    }
    return 0;
}