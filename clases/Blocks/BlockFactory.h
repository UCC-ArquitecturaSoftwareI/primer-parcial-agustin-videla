//
// Created by Agus on 17/4/2020.
//

#ifndef RAYLIBTEMPLATE_BLOCKFACTORY_H
#define RAYLIBTEMPLATE_BLOCKFACTORY_H

#include "Block_Dirt.h"
#include "Block_Iron.h"
#include "string"

/**
 * here we are using the factory method, implemented with parameters
 * the parameter that determines the end result is element
 */
class BlockFactory {
public:
    BlockFactory() = default;

    Block* create(std::string element, int type, Vector2 xCoordinates);
};

#endif //RAYLIBTEMPLATE_BLOCKFACTORY_H