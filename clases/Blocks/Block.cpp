//
// Created by Agus on 16/5/2020.
//

#include "Block.h"

Vector2 Block::size = {16,16};

Block::Block(Vector2 xCoordinates) {
    cage = {xCoordinates.x, xCoordinates.y, size.x, size.y};
}

Block::~Block() {
    std::cout << "me rompi ahre" << '\n';
}

Rectangle Block::getCage(){
    return cage;
}

Vector2 Block::getSize()  {
    return size;
}

Color Block::getColor()  {
    return texture;
}

int Block::getGid() {
    return Gid;
}

Vector2 Block::getCoordinates() {
    return {cage.x, cage. y};
}
