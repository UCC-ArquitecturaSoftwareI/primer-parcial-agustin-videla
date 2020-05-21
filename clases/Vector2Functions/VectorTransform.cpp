//
// Created by Agus on 16/5/2020.
//

#include "VectorTransform.h"

/**
 * Toma un vector y lo modifica para que sus componentes sean divisibles por el tamaño de los bloques
 * Se utiliza para simular que todos los bloques del programa están en una grilla
 * @param v
 * @return
 */
Vector2 vectorTransform(Vector2 v) {
    Player &player = Player::getInstance();
    //coloco el vector en relación al player
    v = {player.cage.x + v.x - GetScreenWidth()/2 + player.cage.width/2,
         player.cage.y + v.y - GetScreenHeight()/2 + player.cage.height/2};
    //chequeo los módulos
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