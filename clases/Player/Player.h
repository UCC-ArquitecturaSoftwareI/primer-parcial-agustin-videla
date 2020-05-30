//
// Created by Agus on 16/5/2020.
//

#ifndef SQUARECRAFT_PLAYER_H
#define SQUARECRAFT_PLAYER_H

#include <raylib.h>

class Player {
    Player();
    static Vector2 size;
public:
    Rectangle cage { };

    static Player& getInstance();

    Vector2 getSize();

    Vector2 getPos();

    Vector2 setPos(int x, int y);
};


#endif //SQUARECRAFT_PLAYER_H
