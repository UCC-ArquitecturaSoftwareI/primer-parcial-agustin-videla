
//
// Created by Agus on 16/5/2020.
//

#include "CollisionObserver.h"

/**
 * Se fija en los bloques próximos a player para determinar si hay o no colisiones
 */
void CollisionObserver::checkCollision() {
    bool check = false;
    Hash hash;
    Player &player = Player::getInstance();
    Vector2 position;
    //arriba-izquierda
    position = toGrid({player.getPos().x-1, player.getPos().y-1});
    if(hash.exists(position)) {
        if (CheckCollisionRecs(player.cage, hash.get(position)->getCage())) {
            std::cout << "arriba-izquierda";
            check = true;
        }
    }
    //arriba
    position = toGrid({player.getPos().x, player.getPos().y-1});
    if(hash.exists(position)) {
        if (CheckCollisionRecs(player.cage, hash.get(position)->getCage())) {
            std::cout << "arriba";
            check = true;
        }
    }
    //arriba-derecha
    position = toGrid({player.getPos().x+player.getSize().x+1, player.getPos().y-1});
    if(hash.exists(position)){
        if(CheckCollisionRecs(player.cage,hash.get(position)->getCage())){
            std::cout << "arriba-derecha";
            check = true;
        }
    }
    //cabeza-derecha
    position = toGrid({player.getPos().x+player.getSize().x+1, player.getPos().y});
    if(hash.exists(position)) {
        if (CheckCollisionRecs(player.cage, hash.get(position)->getCage())) {
            std::cout << "cabeza-derecha";
            check = true;
        }
    }
    //pies-derecha
    position = toGrid({player.getPos().x+player.getSize().x+1, player.getPos().y+player.getSize().y/2});
    if(hash.exists(position)) {
        if (CheckCollisionRecs(player.cage, hash.get(position)->getCage())) {
            std::cout << "pies-derecha";
            check = true;
        }
    }
    //abajo-derecha
    position = toGrid({player.getPos().x+player.getSize().x+1, player.getPos().y+player.getSize().y+1});
    if(hash.exists(position)) {
        if (CheckCollisionRecs(player.cage, hash.get(position)->getCage())) {
            std::cout << "abajo-derecha";
            check = true;
        }
    }
    //abajo
    position = toGrid({player.getPos().x, player.getPos().y+player.getSize().y+1});
    if(hash.exists(position)) {
        if (CheckCollisionRecs(player.cage, hash.get(position)->getCage())) {
            std::cout << "abajo";
            check = true;
        }
    }
    //abajo-izquierda
    position = toGrid({player.getPos().x-1, player.getPos().y+player.getSize().y/2+1});
    if(hash.exists(position)) {
        if (CheckCollisionRecs(player.cage, hash.get(position)->getCage())) {
            std::cout << "abajo-izquierda";
            check = true;
        }
    }
    //pies-izquierda
    position = toGrid({player.getPos().x-1, player.getPos().y+player.getSize().y/2});
    if(hash.exists(position)) {
        if (CheckCollisionRecs(player.cage, hash.get(position)->getCage())) {
            std::cout << "pies-izquierda";
            check = true;
        }
    }
    //cabeza-izquierda
    position = toGrid({player.getPos().x-1, player.getPos().y});
    if(hash.exists(position)) {
        if (CheckCollisionRecs(player.cage, hash.get(position)->getCage())) {
            std::cout << "cabeza-izquierda";
            check = true;
        }
    }

    colides = check;
}