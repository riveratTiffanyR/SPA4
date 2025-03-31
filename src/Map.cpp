#include "Map.h"

#include <iostream>
#include <stdlib.h>
#include <ctime>

#include "Character/Player.h"
#include "Character/Ghost.h"
#include "Character/Clown.h"



Map::Map(Player* p) : player(p) {
    //This keeps the map from generating the same map each time
    //Relies on time as the seed
    srand(time(NULL));
    //Create Empty Map
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            grid[i][j] = RoomType::EMPTY;

    generateRandomRooms();
}

void Map::generateRandomRooms() {
    //Does not let the enemies spawn within the 5x5 starting area
    auto isRestrictedEnemyArea = [](int x, int y) {
        return (x < 5 && y < 5); // Exclude (0,0) to (4,4)
    };
    //Does not let the pickup items spawn within the player starting area
    auto isRestrictedPickupArea = [](int x, int y) {
        return (x == 0 && y == 0); // Exclude (0,0)
    };
    //Does not let the escape room spawn within the 10x10 starting area
    auto isRestrictedEscapeArea = [](int x, int y) {
        return (x < 10 && y < 10); // Exclude (0,0) to (9,9)
    };

    //Generate Ghost
    int ghostX, ghostY;
    do {
        ghostX = rand() % SIZE;
        ghostY = rand() % SIZE;
    } while (isRestrictedEnemyArea(ghostX, ghostY)); // Ensuring the Ghost is outside the 5x5 area
    ghost = new Ghost(ghostX, ghostY);
    grid[ghostX][ghostY] = RoomType::GHOST;

    //Generate 8 Clowns
    for (int i = 0; i < 8; i++) {
        int x, y;
        do {
            x = rand() % SIZE;
            y = rand() % SIZE;
        } while (grid[x][y] != RoomType::EMPTY || isRestrictedEnemyArea(x, y)); // Ensures no overlap

        clowns.push_back(Clown(x, y));
        grid[x][y] = RoomType::CLOWN;
    }

    //Generate Escape Room
    int x, y;
    do {
        x = rand() % SIZE;
        y = rand() % SIZE;
    } while (grid[x][y] != RoomType::EMPTY  || isRestrictedEscapeArea(x,y));
    grid[x][y] = RoomType::ESCAPE;

    //Generate 10 Weapons
    for (int i = 0; i < 10; i++) {
        int x, y;
        do {
            x = rand() % SIZE;
            y = rand() % SIZE;
        } while (grid[x][y] != RoomType::EMPTY || isRestrictedPickupArea(x,y));
        grid[x][y] = RoomType::WEAPON;
    }

    //Generate 20 Health Items
    for (int i = 0; i < 20; i++) {
        int x, y;
        do {
            x = rand() % SIZE;
            y = rand() % SIZE;
        } while (grid[x][y] != RoomType::EMPTY  || isRestrictedPickupArea(x,y));
        grid[x][y] = RoomType::HEALTH;
    }
}

void Map::displayMap() {
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl
         << "| Map Key: (P) Player  (-) Empty Room  |" << endl
         << "|          (G) Ghost   (E) Escape Room |" << endl
         << "|          (C) Clown   (H) Health Item |" << endl
         << "|          (W) Weapon                  |" << endl
         << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (player->getX() == i && player->getY() == j)
                cout << "P "; //Player
            else if (grid[i][j] == RoomType::ESCAPE)
                cout << "E ";  //Escape Room
            else if (grid[i][j] == RoomType::CLOWN)
                cout << "C "; //Clown
            else if (grid[i][j] == RoomType::GHOST)
                cout << "G "; //Ghost
            else if (grid[i][j] == RoomType::WEAPON)
                cout << "W "; //Weapon
            else if (grid[i][j] == RoomType::HEALTH)
                cout << "H "; //Health Item
            else
                cout << "- "; //Empty room
        }
        cout << endl;
    }
}

bool Map::movePlayer(char direction) {
    int newX = player->getX();
    int newY = player->getY();

    switch (direction) {
        case 'f': newY++; break;
        case 'b': newY--; break;
        case 'l': newX--; break;
        case 'r': newX++; break;
        default: cout << "That is not a valid direction" << endl; return false;
    }

    //Boundary Check
    if (newX < 0 || newX >= SIZE || newY < 0 || newY >= SIZE) {
        cout << "You cannot move there. Try a different direction" << endl;
        return false;
    }

    player->setX(newX);
    player->setY(newY);

    return true;
}

RoomType Map::getRoomContents(int x, int y) {
    return grid[x][y];
}

void Map::emptyTheRoom(int x, int y) {
    grid[x][y] = RoomType::EMPTY;
}

// ReSharper disable once CppNotAllPathsReturnValue
Clown* Map::getClown(int x, int y) {
    for (Clown& clown : clowns) {
        if (clown.getX() == x && clown.getY() == y) {
            return &clown;
        }
    }
}

Ghost* Map::getGhost() const {
    return ghost;
}
