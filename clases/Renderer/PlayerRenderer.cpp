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
    //tex = LoadTexture("../resources/caracteres/steve_right.png");
    Rectangle rec;
    rec.height = 16;
    rec.width = 14;
    rec.y = 0;
    rec.x = 1;

    if(player->right){
        tex = LoadTexture("../resources/caracteres/steve_right.png");
        rec.x = 1;
    }
    if(!player->right){
        tex = LoadTexture("../resources/caracteres/steve_left.png");
        rec.x = 65;
    }

    DrawTextureRec(tex, rec , {player->cage.x, player->cage.y}, WHITE);
    //DrawRectangleRec(player->cage, RED);
}