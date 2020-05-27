//
// Created by Agus on 23/4/2020.
//

#include "BlockRenderer.h"
#include "../../resources/Mapa/SingletonMapa.h"
void BlockRenderer::render(Block *block) {
    SingletonMapa &mapa = SingletonMapa::getInstance("../resources/Mapa/EntitledMap1.json");
    Vector2 position = {block->getCage().x,block->getCage().y}; //posicion donde se dibujará el bloque
    DrawTextureRec(mapa.getTexture(), mapa.getRec(block->getGid()), position, WHITE);  // Draw part of the texture //mapa.getRec nos daría la posicion de la textura a recortar
}