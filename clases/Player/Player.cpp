//
// Created by Agus on 16/5/2020.
//

#include "Player.h"


Player::Player() {
    cage.height = size.x;
    cage.width = size.y;
}

//x es la altura e y el ancho para ser consistente con los parámetros de cage
Vector2 Player::size = { 80, 40};

/**
 * Devuelve una instancia única de player
 * @return
 */
Player &Player::getInstance() {
    static Player player;
    return player;
}

/**
 * Devuelve el tamaño de player
 * @return
 */
Vector2 Player::getSize() {
    return {size.x,size.y};
}

/**
 * Devuelve la posición de player
 * @return
 */
Vector2 Player::getPos() {
    return {cage.x,cage.y};
}



