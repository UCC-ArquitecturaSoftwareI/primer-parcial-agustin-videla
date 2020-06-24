//
// Created by ribet on 18/4/2020.
//

#ifndef RAYLIBTEMPLATE_BLOCK_IRON_H
#define RAYLIBTEMPLATE_BLOCK_IRON_H

#include <iostream>
#include "Block.h"

class Block_Iron : public Block {
public:
    Block_Iron(Vector2 xCoordinates, std::string type) : Block(xCoordinates, type) {
        if(type == "0") Gid = 253;
        if(type == "1") Gid = 12;}
};

#endif //RAYLIBTEMPLATE_BLOCK_IRON_H