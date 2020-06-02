//
// Created by Agus on 30/5/2020.
//

#ifndef SQUARECRAFT_COLLISIONHANDLER_H
#define SQUARECRAFT_COLLISIONHANDLER_H

#include <vector>
#include "../Vector2Functions/VectorTransform.h"

class CollisionHandler {
public:
    CollisionHandler() { };

    bool colides;

    void handle(const std::vector<int>& c);
};


#endif //SQUARECRAFT_COLLISIONHANDLER_H
