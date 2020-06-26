//
// Created by Agus on 16/5/2020.
//

#ifndef SQUARECRAFT_PLAYER_H
#define SQUARECRAFT_PLAYER_H

#include <raylib.h>
#include "../Blocks/Block.h"

class Player {
    Player();
    static Vector2 size;
    Vector2 speed;
    Vector2 back;
    int Gravity;
    bool falling;

public:
    Rectangle cage { };
    bool up;
    bool right;

    static Player& getInstance();

    Vector2 getSize();

    Vector2 getPos();

    Vector2 getBack();

    Vector2 getSpeed();

    void setPos(Vector2 pos);

    void setBack();

    void setSpeed(Vector2 v);

    void updatePosition(char where);

    void gravity();

    void setGravity();
};


#endif //SQUARECRAFT_PLAYER_H
