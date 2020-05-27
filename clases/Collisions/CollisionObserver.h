//
// Created by Agus on 16/5/2020.
//

#ifndef SQUARECRAFT_COLLISIONDETECTOR_H
#define SQUARECRAFT_COLLISIONDETECTOR_H

#include "../Vector2Functions/HashFacade.h"
#include "../Player/Player.h"
#include <raylib.h>


class CollisionObserver {
public:
    CollisionObserver() = default;

    bool colides;

    void checkCollision();
};

#endif //SQUARECRAFT_COLLISIONDETECTOR_H
