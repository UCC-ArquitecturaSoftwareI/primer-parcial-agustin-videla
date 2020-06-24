//
// Created by Agus on 16/5/2020.
//

#include "Block.h"

Vector2 Block::size = {16,16};

Block::Block(Vector2 xCoordinates, std::string type) {
    cage = {xCoordinates.x, xCoordinates.y, size.x, size.y};
}

Block::~Block() {
}

Rectangle Block::getCage(){
    return cage;
}

Vector2 Block::getSize()  {
    return size;
}

int Block::getGid() {
    return Gid;
}
