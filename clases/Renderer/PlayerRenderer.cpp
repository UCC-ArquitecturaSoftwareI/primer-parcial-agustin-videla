//
// Created by Agus on 16/5/2020.
//

#include "PlayerRenderer.h"

/**
 * Dibuja a player
 * @param player
 */
void PlayerRenderer::render(Player *player) {
    Texture2D tex;
    tex = LoadTexture("../resources/caracteres/steve.png");
    Rectangle rec;
    rec.height = 16;
    rec.width = 14;
    rec.x = 1;
    rec.y = 0;
    DrawTextureRec(tex, rec , {player->cage.x, player->cage.y}, WHITE);
    //DrawRectangleRec(player->cage, RED);
}