//
// Created by Agus on 13/5/2020.
//

#ifndef SQUARECRAFT_VECTOR2HASH_H
#define SQUARECRAFT_VECTOR2HASH_H

#include <raylib.h>
#include <string>
#include "Vector2Adaptor.h"

class Vector2Hash {
public:
    /*
     * Concatena las coordenadas del Vector2Adaptor para formar una llave única
     */
    int operator()(const Vector2Adaptor v) const
    {
        std::string sX = std::to_string(v.vector.x);
        std::string sY = std::to_string(v.vector.y);
        std::string fV = sX + sY;
        return std::stoi(fV);
    }
};


#endif //SQUARECRAFT_VECTOR2HASH_H
