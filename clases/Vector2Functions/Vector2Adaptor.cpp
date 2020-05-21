//
// Created by Agus on 21/5/2020.
//

#include "Vector2Adaptor.h"

/**
 * Contruye un Vector2Adaptor con los mismos datos del vector v
 * @param v
 */
Vector2Adaptor::Vector2Adaptor(Vector2 v) {
    vector.x = v.x;
    vector.y = v.y;
}

/**
 * Chequea si dos vectores son iguales
 * @param v
 * @return
 */
bool Vector2Adaptor::operator==(const Vector2Adaptor &v) const {
    return vector.x == v.vector.x && vector.y == v.vector.y;
}

