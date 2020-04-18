//
// Created by ribet on 18/4/2020.
//

#ifndef RAYLIBTEMPLATE_BLOCK_IRON_H
#define RAYLIBTEMPLATE_BLOCK_IRON_H

#include <iostream>
#include "Block.h"

class Block_Iron : public Block {
public:
    Block_Iron(Vector2 xCoordinates) : Block(xCoordinates) { texture = "hierro ah"; std::cout<<"estoy re duro lol"<<'\n';}
    void draw() {
        DrawRectangleV(coordinates, size, GRAY);
    }
};

#endif //RAYLIBTEMPLATE_BLOCK_IRON_H