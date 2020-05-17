//
// Created by Agus on 16/5/2020.
//

#include "PlayerRenderer.h"

void PlayerRenderer::render(Player *player) {
    DrawRectangleV(player->pos, player->size, RED);
}
