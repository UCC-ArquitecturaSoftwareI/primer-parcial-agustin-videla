//
// Created by Agus on 16/5/2020.
//

#include "Block.h"

Vector2 Block::size = {40,40};

Block::Block(Vector2 xCoordinates) {
    cage = {xCoordinates.x, xCoordinates.y, size.x, size.y};
}
