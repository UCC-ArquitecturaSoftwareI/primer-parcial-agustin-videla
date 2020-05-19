//
// Created by Agus on 16/5/2020.
//

#include "VectorTransform.h"

Vector2 vectorTransform(Vector2 v) {
    Player &player = Player::getInstance();
    v = {player.cage.x + v.x - GetScreenWidth()/2 + player.cage.width/2,
         player.cage.y + v.y - GetScreenHeight()/2 + player.cage.height/2};
    if(v.x >= 0)
        v.x -= (int)v.x%(int)Block::getSize().x;
    else
        v.x -= Block::getSize().x + (int)v.x%(int)Block::getSize().x;
    if(v.y >= 0)
        v.y -= (int)v.y%(int)Block::getSize().y;
    else
        v.y -= Block::getSize().y + (int)v.y%(int)Block::getSize().y;
    return v;
}