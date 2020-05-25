//
// Created by Agus on 16/5/2020.
//

#ifndef SQUARECRAFT_COLLISIONDETECTOR_H
#define SQUARECRAFT_COLLISIONDETECTOR_H

#include "../Vector2Functions/HashFacade.h"
#include "../Player/Player.h"
#include <raylib.h>


class CollisionObserver {
public:
    CollisionObserver() = default;
    bool colides;
    void checkCollision() {
        bool check = false;
        Player &player = Player::getInstance();
        Hash hash;
        //arriba
        if(hash.exists({player.cage.x,player.cage.y-1})){

            if(CheckCollisionRecs(player.cage,hash.get({player.cage.x,player.cage.y-1})->getCage()))
                std::cout << "me choqué";
        }
        colides = check;
    };
};

#endif //SQUARECRAFT_COLLISIONDETECTOR_H
