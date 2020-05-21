//
// Created by Agus on 15/5/2020.
//

#ifndef SQUARECRAFT_VECTOR2ADAPTOR_H
#define SQUARECRAFT_VECTOR2ADAPTOR_H

#include <raylib.h>

/**
 * Adapta la insterfaz de Vector2 con el objetivo de usarlas como llave en SingletonHash
 * Agrega el operador ==
 */
class Vector2Adaptor {
public:
    Vector2Adaptor(Vector2 v);

    Vector2 vector{};

    bool operator==(const Vector2Adaptor& v) const;
};


#endif //SQUARECRAFT_VECTOR2ADAPTOR_H
