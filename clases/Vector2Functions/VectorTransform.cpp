//
// Created by Agus on 16/5/2020.
//

#include "VectorTransform.h"

Vector2 vectorTransform(Vector2 v) {

    Player &player = Player::getInstance();
    v = {player.pos.x + v.x - GetScreenWidth()/2,
         player.pos.y + v.y - GetScreenHeight()/2};
    if((int)v.x%20 != 0)
        v.x -= (int)v.x%20;
    if((int)v.y%20 != 0)
        v.y -= (int)v.y%20;
    return v;
}