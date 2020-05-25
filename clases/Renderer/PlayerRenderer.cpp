//
// Created by Agus on 16/5/2020.
//

#include "PlayerRenderer.h"

/**
 * Dibuja a player
 * @param player
 */
void PlayerRenderer::render(Player *player) {
    DrawRectangleRec(player->cage, RED);
}
