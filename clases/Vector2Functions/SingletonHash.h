//
// Created by Agus on 15/5/2020.
//

#ifndef SQUARECRAFT_SINGLETONHASH_H
#define SQUARECRAFT_SINGLETONHASH_H

#include <unordered_map>
#include "../Blocks/Block.h"
#include "Vector2Hash.h"

/**
 * Genera una instancia única del hash para guardar bloques.
 */
class   SingletonHash {
private:
    std::unordered_map<Vector2Adaptor,Block*,Vector2Hash> table;
    SingletonHash(){};
public:
    static SingletonHash& getInstance(){
        static SingletonHash hash;
        return hash;
    }
    std::unordered_map<Vector2Adaptor,Block*,Vector2Hash>& hash(){
        return table;
    }
};


#endif //SQUARECRAFT_SINGLETONHASH_H
