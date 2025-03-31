/*
* Course: CSC 2210 - Procedural and OO C++
 * Section: 001
 * Assignment: SPA4
 * Names: Tiffany Rivera, Eleanor Certalic, Madison Betz
 * Date Due: 02/21/2025
 */

#ifndef MAP_H
#define MAP_H

#include <vector>
#include "Character/Player.h"
#include "Character/Clown.h"
#include "Character/Ghost.h"

using namespace std;

enum class RoomType { EMPTY, WEAPON, HEALTH, CLOWN, GHOST, ESCAPE };

class Map {
private:
    static const int SIZE = 20;
    RoomType grid[SIZE][SIZE];
    Player* player;
    vector<Clown> clowns;
    Ghost* ghost;

    void generateRandomRooms();

public:
    Map(Player* p);

    void displayMap();
    bool movePlayer(char direction);
    RoomType getRoomContents(int x, int y);
    void emptyTheRoom(int x, int y);
    Clown* getClown(int x, int y);
    Ghost* getGhost() const;
};

#endif //MAP_H
