
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
    colides = false;
    arriba = false;     //0,1,2
    abajo = false;      //5,6,7
    izquierda = false;  //8,9
    derecha = false;    //3,4
    /*               0   1   2
     *               9  ***  3
     *               8  ***  4
     *               7   6   5
     */


    //arriba-izquierda
    position = toGrid({player.getPos().x-1, player.getPos().y-1});
    if(hash.exists(position)) {
        if (CheckCollisionRecs(player.cage, hash.get(position)->getCage())) {
            std::cout << "arriba-izquierda \n";
            colisiones.push_back(0);
            arriba = true;
            izquierda = true;
            colides = true;
        }
    }
    //arriba
    position = toGrid({player.getPos().x, player.getPos().y-1});
    if(hash.exists(position)) {
        if (CheckCollisionRecs(player.cage, hash.get(position)->getCage())) {
            std::cout << "arriba\n";
            colisiones.push_back(1);
            arriba = true;
            colides = true;
        }
    }
    //arriba-derecha
    position = toGrid({player.getPos().x+player.getSize().x+1, player.getPos().y-1});
    if(hash.exists(position)){
        if(CheckCollisionRecs(player.cage,hash.get(position)->getCage())){
            std::cout << "arriba-derecha\n";
            colisiones.push_back(2);
            arriba = true;
            derecha = true;
            colides = true;
        }
    }
    //cabeza-derecha
    position = toGrid({player.getPos().x+player.getSize().x+1, player.getPos().y});
    if(hash.exists(position)) {
        if (CheckCollisionRecs(player.cage, hash.get(position)->getCage())) {
            std::cout << "cabeza-derecha";
            colisiones.push_back(3);
            derecha = true;
            colides = true;
        }
    }
    //pies-derecha
    position = toGrid({player.getPos().x+player.getSize().x+1, player.getPos().y+player.getSize().y/2});
    if(hash.exists(position)) {
        if (CheckCollisionRecs(player.cage, hash.get(position)->getCage())) {
            std::cout << "pies-derecha";
            colisiones.push_back(4);
            derecha = true;
            colides = true;
        }
    }
    //abajo-derecha
    position = toGrid({player.getPos().x+player.getSize().x+1, player.getPos().y+player.getSize().y+1});
    if(hash.exists(position)) {
        if (CheckCollisionRecs(player.cage, hash.get(position)->getCage())) {
            std::cout << "abajo-derecha";
            colisiones.push_back(5);
            abajo = true;
            derecha = true;
            colides = true;
        }
    }
    //abajo
    position = toGrid({player.getPos().x, player.getPos().y+player.getSize().y+1});
    if(hash.exists(position)) {
        if (CheckCollisionRecs(player.cage, hash.get(position)->getCage())) {
            std::cout << "abajo";
            colisiones.push_back(6);
            abajo = true;
            colides = true;
        }
    }
    //abajo-izquierda
    position = toGrid({player.getPos().x-1, player.getPos().y+player.getSize().y/2+1});
    if(hash.exists(position)) {
        if (CheckCollisionRecs(player.cage, hash.get(position)->getCage())) {
            std::cout << "abajo-izquierda";
            colisiones.push_back(7);
            abajo = true;
            izquierda = true;
            colides = true;
        }
    }
    //pies-izquierda
    position = toGrid({player.getPos().x-1, player.getPos().y+player.getSize().y/2});
    if(hash.exists(position)) {
        if (CheckCollisionRecs(player.cage, hash.get(position)->getCage())) {
            std::cout << "pies-izquierda";
            colisiones.push_back(8);
            izquierda = true;
            colides = true;
        }
    }
    //cabeza-izquierda
    position = toGrid({player.getPos().x-1, player.getPos().y});
    if(hash.exists(position)) {
        if (CheckCollisionRecs(player.cage, hash.get(position)->getCage())) {
            std::cout << "cabeza-izquierda";
            colisiones.push_back(9);
            izquierda = true;
            colides = true;
        }
    }
    handler.handle(colisiones);
}