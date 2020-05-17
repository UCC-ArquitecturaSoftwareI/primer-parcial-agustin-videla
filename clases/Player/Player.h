//
// Created by Agus on 16/5/2020.
//

#ifndef SQUARECRAFT_PLAYER_H
#define SQUARECRAFT_PLAYER_H

#include <raylib.h>

class Player {
    Player() { cage.height = size.x; cage.width = size.y; }
    static Vector2 size;
public:
    Rectangle cage { }; //colision rectangle //todo debuggear colisiones
    static Player& getInstance(){
        static Player player;
        return player;
    }
//    static Vector2 getSize() { return size; }
};


#endif //SQUARECRAFT_PLAYER_H
