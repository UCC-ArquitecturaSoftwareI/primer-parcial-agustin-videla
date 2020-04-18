//
// Created by Agus on 17/4/2020.
//

#ifndef RAYLIBTEMPLATE_BLOCK_DIRT_H
#define RAYLIBTEMPLATE_BLOCK_DIRT_H

#include <iostream>
#include "Block.h"

class Block_Dirt : public Block {
public:
    Block_Dirt(Vector2 xCoordinates) : Block(xCoordinates) { texture = "tierra ah"; std::cout<<"soy tierra lol"<<'\n';}
    void draw() {
        DrawRectangleV(coordinates, size, BLACK);
    }
};


#endif //RAYLIBTEMPLATE_BLOCK_DIRT_H
