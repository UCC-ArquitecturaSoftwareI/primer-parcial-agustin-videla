//
// Created by Agus on 13/5/2020.
//

#ifndef SQUARECRAFT_VECTOR2HASH_H
#define SQUARECRAFT_VECTOR2HASH_H

#include <raylib.h>
#include <string>
#include "Vector2Adaptor.h"

/**
 * Función de Hash para vectores
 */
class Vector2Hash {
public:
    int operator()(const Vector2Adaptor v) const
    {
        return ((v.vector.x + v.vector.y)*(v.vector.x+v.vector.y+1))/2+v.vector.y;
    }
};


#endif //SQUARECRAFT_VECTOR2HASH_H
