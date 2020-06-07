
//
// Created by Agus on 16/5/2020.
//

#include "CollisionObserver.h"
#include <vector>

/**
 * Se fija en los bloques próximos a player para determinar si hay o no colisiones
 */
bool CollisionObserver::checkCollision() {
    Hash hash;
    Player &player = Player::getInstance();
    Vector2 position;
    std::vector<int> colisiones;
    colides = false;
    abajo = false;

    /*               0   1   2
     *               9  ***  3
     *               8  ***  4
     *               7   6   5
     */

    //arriba-izquierda
    position = toGrid({player.getPos().x-1, player.getPos().y-1});
    if(hash.exists(position)) {
        if (CheckCollisionRecs(player.cage, hash.get(position)->getCage())) {
            colides = true;
        }
    }
    //arriba
    position = toGrid({player.getPos().x, player.getPos().y-1});
    if(hash.exists(position)) {
        if (CheckCollisionRecs(player.cage, hash.get(position)->getCage())) {
            colides = true;
        }
    }
    //arriba-derecha
    position = toGrid({player.getPos().x+player.getSize().x+1, player.getPos().y-1});
    if(hash.exists(position)){
        if(CheckCollisionRecs(player.cage,hash.get(position)->getCage())){
            colides = true;
        }
    }
    //cabeza-derecha
    position = toGrid({player.getPos().x+player.getSize().x+1, player.getPos().y});
    if(hash.exists(position)) {
        if (CheckCollisionRecs(player.cage, hash.get(position)->getCage())) {
            colides = true;
        }
    }
    //pies-derecha
    position = toGrid({player.getPos().x+player.getSize().x+1, player.getPos().y+player.getSize().y/2});
    if(hash.exists(position)) {
        if (CheckCollisionRecs(player.cage, hash.get(position)->getCage())) {
            colides = true;
        }
    }
    //abajo-derecha
    position = toGrid({player.getPos().x+player.getSize().x+1, player.getPos().y+player.getSize().y+1});
    if(hash.exists(position)) {
        if (CheckCollisionRecs(player.cage, hash.get(position)->getCage())) {
            colides = true;
        }
    }
    //abajo
    position = toGrid({player.getPos().x, player.getPos().y+player.getSize().y+1});
    if(hash.exists(position)) {
        if (CheckCollisionRecs(player.cage, hash.get(position)->getCage())) {
            colides = true;
        }
    }
    //abajo - gravity
    position = toGrid({player.getPos().x, player.getPos().y+player.getSize().y+2});
    if(hash.exists(position)) {
            abajo = true;
    }
    //abajo-izquierda
    position = toGrid({player.getPos().x-1, player.getPos().y+player.getSize().y/2+1});
    if(hash.exists(position)) {
        if (CheckCollisionRecs(player.cage, hash.get(position)->getCage())) {
            colides = true;
        }
    }
    //pies-izquierda
    position = toGrid({player.getPos().x-1, player.getPos().y+player.getSize().y/2});
    if(hash.exists(position)) {
        if (CheckCollisionRecs(player.cage, hash.get(position)->getCage())) {
            colides = true;
        }
    }
    //cabeza-izquierda
    position = toGrid({player.getPos().x-1, player.getPos().y});
    if(hash.exists(position)) {
        if (CheckCollisionRecs(player.cage, hash.get(position)->getCage())) {
            colides = true;
        }
    }
    return colides;
}