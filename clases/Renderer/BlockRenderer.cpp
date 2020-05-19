//
// Created by Agus on 23/4/2020.
//

#include "BlockRenderer.h"
#include "../../resources/Mapa/SingletonMapa.h"
void BlockRenderer::render(Block *block) {
    SingletonMapa &mapa = SingletonMapa::getInstance("../resources/Mapa/EntitledMap1.json");

    //DrawRectangleRec(block->getCage(), block->getColor());
    DrawTexture(mapa.getTexture(),block->getCage().x,block->getCage().y,WHITE);
}
