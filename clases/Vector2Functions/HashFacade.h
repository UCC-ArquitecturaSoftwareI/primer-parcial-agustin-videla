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
    bool put(Vector2 key, Block* block) {
        key = vectorTransform(key);
        if (table.all().find(Vector2Adaptor(key)) == table.all().end()) {
            table.all()[Vector2Adaptor(key)] = block;
            return true;
        }
        return false;
    }

    bool remove(Vector2 key) {
        key = vectorTransform(key);
        if (table.all().find(Vector2Adaptor(key)) != table.all().end()) {
            table.all()[Vector2Adaptor(key)]->~Block();
            table.all().erase(Vector2Adaptor(key));
            return true;
        }
        return false;
    }

    bool exists(Vector2 key) {
        key = vectorTransform(key);
        return table.all().find(Vector2Adaptor(key)) != table.all().end();
    }

};


#endif //SQUARECRAFT_HASHFACADE_H
