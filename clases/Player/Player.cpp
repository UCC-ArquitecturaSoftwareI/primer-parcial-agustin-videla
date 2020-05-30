//
// Created by Agus on 16/5/2020.
//

#include "Player.h"


Player::Player() {
    cage.height = size.y;
    cage.width = size.x;
    speed = {1,1};
}

/**
 * x = width, y = height
 */
Vector2 Player::size = {Block::getSize().x, Block::getSize().y*2};

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

Vector2  Player::setPos(int x, int y) {
    cage.x = x;
    cage.y = y;
}

Vector2 Player::getSpeed() {
    return speed;
}

void Player::setSpeed(Vector2 v) {
    speed = v;
}



