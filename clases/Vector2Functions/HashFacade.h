//
// Created by Agus on 15/5/2020.
//

#ifndef SQUARECRAFT_HASHFACADE_H
#define SQUARECRAFT_HASHFACADE_H

#include "SingletonHash.h"
#include "../Blocks/Block.h"
#include "VectorTransform.h"

/**
 * Simplifica el uso de la tabla de hash
 */
class Hash {
public:
    SingletonHash &table = SingletonHash::getInstance();

    bool put(Vector2 key, Block* block);

    bool remove(Vector2 key);

    Block* get(Vector2 key);

    bool exists(Vector2 key);

};


#endif //SQUARECRAFT_HASHFACADE_H
