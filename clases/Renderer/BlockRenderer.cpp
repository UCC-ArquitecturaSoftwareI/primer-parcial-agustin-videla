//
// Created by Agus on 23/4/2020.
//

#include "BlockRenderer.h"

void BlockRenderer::render(Block *block) {
    DrawRectangleV(block->getCoordinates(), block->getSize(), block->getColor());
}
