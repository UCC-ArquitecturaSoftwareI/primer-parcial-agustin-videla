//
// Created by Agus on 16/5/2020.
//

#include "VectorTransform.h"

/**
 * Modifica la posición del mouse para que quede en relación a Player en lugar de estar en relación a la ventana
 * @param v
 * @return
 */
Vector2 mouseTransform(Vector2 v) {
    Player &player = Player::getInstance();
    //coloco el vector en relación al player
    v = {player.getPos().x + v.x - GetScreenWidth()/2 + player.getSize().x/2,
         player.getPos().y + v.y - GetScreenHeight()/2 + player.getSize().y/2};
    return toGrid(v);
}

/**
 * Toma un vector y lo modifica para que sus componentes sean divisibles por el tamaño de los bloques
 * Se utiliza para simular que todos los bloques del programa están en una grilla
 * @param v
 * @return
 */
Vector2 toGrid(Vector2 v) {
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