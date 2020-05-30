
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
    if(hash.exists(toGrid(player.getPos()))){
        hash.get(toGrid(player.getPos()))->setGid();

//        std::cout<< player.getPos().x << player.getPos().y << "\n";
        if(CheckCollisionRecs(player.cage,hash.get(toGrid(player.getPos()))->getCage())){
            std::cout << "me choqué \n";
            check = true;

    }
        std::cout<<"fuck \n";
    }

    colides = check;
}

