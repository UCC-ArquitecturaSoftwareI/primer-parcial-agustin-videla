
//
// Created by Agus on 16/5/2020.
//

#include "CollisionObserver.h"

/**
 * Se fija en los bloques próximos a player para determinar si hay o no colisiones
 */
void CollisionObserver::checkCollision() {
    bool check = false;
    Player &player = Player::getInstance();
    Hash hash;
    //arriba
    if(hash.exists({player.cage.x,player.cage.y-1})){

        if(CheckCollisionRecs(player.cage,hash.get({player.cage.x,player.cage.y-1})->getCage()))
            std::cout << "me choqué";
    }
    colides = check;
}

