//
// Created by Agus on 16/5/2020.
//

#ifndef SQUARECRAFT_PLAYERRENDERER_H
#define SQUARECRAFT_PLAYERRENDERER_H

#include "Renderer.h"
#include "../Player/Player.h"

class PlayerRenderer : public Renderer{
public:
    void render(Player* player);
};


#endif //SQUARECRAFT_PLAYERRENDERER_H
