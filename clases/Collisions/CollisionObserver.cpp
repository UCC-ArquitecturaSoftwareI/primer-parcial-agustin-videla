
//
// Created by Agus on 16/5/2020.
//

#include "CollisionObserver.h"
#include <vector>
#include "CollisionHandler.h"

/**
 * Se fija en los bloques próximos a player para determinar si hay o no colisiones
 */
void CollisionObserver::checkCollision() {
    Hash hash;
    CollisionHandler handler;
    Player &player = Player::getInstance();
    Vector2 position;
    std::vector<int> colisiones;
    //arriba-izquierda
    position = toGrid({player.getPos().x-1, player.getPos().y-1});
    if(hash.exists(position)) {
        if (CheckCollisionRecs(player.cage, hash.get(position)->getCage())) {
            std::cout << "arriba-izquierda";
            colisiones.push_back(0);
        }
    }
    //arriba
    position = toGrid({player.getPos().x, player.getPos().y-1});
    if(hash.exists(position)) {
        if (CheckCollisionRecs(player.cage, hash.get(position)->getCage())) {
            std::cout << "arriba";
            colisiones.push_back(1);
        }
    }
    //arriba-derecha
    position = toGrid({player.getPos().x+player.getSize().x+1, player.getPos().y-1});
    if(hash.exists(position)){
        if(CheckCollisionRecs(player.cage,hash.get(position)->getCage())){
            std::cout << "arriba-derecha";
            colisiones.push_back(2);
        }
    }
    //cabeza-derecha
    position = toGrid({player.getPos().x+player.getSize().x+1, player.getPos().y});
    if(hash.exists(position)) {
        if (CheckCollisionRecs(player.cage, hash.get(position)->getCage())) {
            std::cout << "cabeza-derecha";
            colisiones.push_back(3);
        }
    }
    //pies-derecha
    position = toGrid({player.getPos().x+player.getSize().x+1, player.getPos().y+player.getSize().y/2});
    if(hash.exists(position)) {
        if (CheckCollisionRecs(player.cage, hash.get(position)->getCage())) {
            std::cout << "pies-derecha";
            colisiones.push_back(4);
        }
    }
    //abajo-derecha
    position = toGrid({player.getPos().x+player.getSize().x+1, player.getPos().y+player.getSize().y+1});
    if(hash.exists(position)) {
        if (CheckCollisionRecs(player.cage, hash.get(position)->getCage())) {
            std::cout << "abajo-derecha";
            colisiones.push_back(5);
        }
    }
    //abajo
    position = toGrid({player.getPos().x, player.getPos().y+player.getSize().y+1});
    if(hash.exists(position)) {
        if (CheckCollisionRecs(player.cage, hash.get(position)->getCage())) {
            std::cout << "abajo";
            colisiones.push_back(6);
        }
    }
    //abajo-izquierda
    position = toGrid({player.getPos().x-1, player.getPos().y+player.getSize().y/2+1});
    if(hash.exists(position)) {
        if (CheckCollisionRecs(player.cage, hash.get(position)->getCage())) {
            std::cout << "abajo-izquierda";
            colisiones.push_back(7);
        }
    }
    //pies-izquierda
    position = toGrid({player.getPos().x-1, player.getPos().y+player.getSize().y/2});
    if(hash.exists(position)) {
        if (CheckCollisionRecs(player.cage, hash.get(position)->getCage())) {
            std::cout << "pies-izquierda";
            colisiones.push_back(8);
        }
    }
    //cabeza-izquierda
    position = toGrid({player.getPos().x-1, player.getPos().y});
    if(hash.exists(position)) {
        if (CheckCollisionRecs(player.cage, hash.get(position)->getCage())) {
            std::cout << "cabeza-izquierda";
            colisiones.push_back(9);
        }
    }
    handler.handle(colisiones);
}