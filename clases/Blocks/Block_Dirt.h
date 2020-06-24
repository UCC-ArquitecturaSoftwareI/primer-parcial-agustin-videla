//
// Created by Agus on 17/4/2020.
//

#ifndef RAYLIBTEMPLATE_BLOCK_DIRT_H
#define RAYLIBTEMPLATE_BLOCK_DIRT_H

#include <iostream>
#include "Block.h"

class Block_Dirt : public Block {
public:
    Block_Dirt(Vector2 xCoordinates, std::string type) : Block(xCoordinates, type) {
        if(type == "0") Gid = 248;
        if(type == "1") Gid = 250;}
};

#endif //RAYLIBTEMPLATE_BLOCK_DIRT_H