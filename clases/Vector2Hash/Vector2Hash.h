//
// Created by Agus on 13/5/2020.
//

#ifndef SQUARECRAFT_VECTOR2HASH_H
#define SQUARECRAFT_VECTOR2HASH_H

#include <raylib.h>
#include <string>

#include "../Blocks/Block.h"


class Vector2Hash {
public:
    /*
     * Concatena las coordenadas del Vector2 para formar una llave única
     */
    int operator()(const Vector2 v) const
    {
        std::string sX = std::to_string(v.x);
        std::string sY = std::to_string(v.y);
        std::string fV = sX + sY;
        return std::stoi(fV);
    }
};


#endif //SQUARECRAFT_VECTOR2HASH_H
