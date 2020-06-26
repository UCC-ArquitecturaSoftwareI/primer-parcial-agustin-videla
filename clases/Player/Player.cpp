//
// Created by Agus on 16/5/2020.
//

#include "Player.h"

Player::Player() {
    up = true;
    right = true;
    cage.height = size.y;
    cage.width = size.x;
    speed = {1,1};
    falling = true;
}

/**
 * x = width, y = height
 */
Vector2 Player::size = {14, 16};

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
/**
 * Returns the previous position of player
 * @return
 */
Vector2 Player::getBack() {
    return back;
}
/**
 * set the position
 * @param pos
 */
void Player::setPos(Vector2 pos) {
    cage.x = pos.x;
    cage.y = pos.y;
}
/**
 * sets the previous position
 */
void Player::setBack() {
    back = getPos();
}

void Player::updatePosition(char where) {
    if(where == 'r'){ // right
        cage.x += 1*speed.x;
        right = true;
    }
    if(where == 'l'){ // left
        cage.x -= 1*speed.x;
        right = false;
    }
    if(where == 'u'){ // up
        cage.y -= 1*speed.y;
        up = true;
    }
    if(where == 'd'){ // down
        cage.y += 1*speed.y;
        up = false;
    }
}
