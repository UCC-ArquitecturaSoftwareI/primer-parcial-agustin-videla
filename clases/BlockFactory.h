//
// Created by Agus on 17/4/2020.
//

#ifndef RAYLIBTEMPLATE_BLOCKFACTORY_H
#define RAYLIBTEMPLATE_BLOCKFACTORY_H


#include "Block_Dirt.h"

class BlockFactory {
public:
    BlockFactory() = default;
    Block_Dirt createBlock(int type, Vector2 xCoordinates);
};


#endif //RAYLIBTEMPLATE_BLOCKFACTORY_H
