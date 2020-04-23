//
// Created by Agus on 23/4/2020.
//

#ifndef RAYLIBTEMPLATE_BLOCKRENDERER_H
#define RAYLIBTEMPLATE_BLOCKRENDERER_H


#include "Renderer.h"
#include "../Blocks/Block.h"


class BlockRenderer : public Renderer{
public:
    void render(Block* block);
};


#endif //RAYLIBTEMPLATE_BLOCKRENDERER_H
