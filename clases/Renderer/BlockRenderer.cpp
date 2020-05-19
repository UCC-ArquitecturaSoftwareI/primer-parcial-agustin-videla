//
// Created by Agus on 23/4/2020.
//

#include "BlockRenderer.h"
#include "../../resources/Mapa/SingletonMapa.h"
void BlockRenderer::render(Block *block) {
    SingletonMapa &mapa = SingletonMapa::getInstance("../resources/Mapa/EntitledMap1.json");
    //DrawRectangleRec(block->getCage(), block->getColor());
    Vector2 position = {block->getCage().x,block->getCage().y}; //posicion donde se dibujará el bloque
    DrawTextureRec(mapa.getTexture(), mapa.getRec(block->getGid()), position, WHITE);  // Draw part of the texture //mapa.getRec nos daría la posicion de la textura a recortar
    //DrawTexture(mapa.getTexture(),block->getCage().x,block->getCage().y,WHITE);
}

/*

void Mapa::dibujar() {
    Rectangle tile_rec;
    tile_rec.x = 0.0f;
    tile_rec.y = 0.0f;
    tile_rec.width = map.getTileSize().x;
    tile_rec.height = map.getTileSize().y;

    //std::cout<<tile_rec.height<<std::endl;

    int firstId = map_tileset->getFirstgid(); //First tile id of the tileset
    int columns = map_tileset->getColumns(); //For the demo map it is 8.
    int margin = map_tileset->getMargin();
    int space = map_tileset->getSpacing();

    auto &c = map.getBackgroundColor();
    ClearBackground({c.r ,c.g, c.b, c.a}); // limpio la pantalla con el color de fondo del mapa

    for (auto nombre: {"cosas"}){ //nombre que yo le doy a las capas y las dibuja en el orden escrito
        auto *layer = map.getLayer(nombre);

        //std::cout<<layer->getName()<<std::endl;
        std::cout<<"Fuck1 \n"; ///hasta acá llega, para abajo se rompe
        for (auto &[id, tile] : layer->getTileData()){ // loops through all existing tiles
            std::cout<<"Fuck \n";
            //std::cout<< tile->getId() <<" fuck \n";

            if(tile != nullptr) { //todo porque me da que todos son nulos??????????????
                tson::Vector2f position = {(float) std::get<0>(id) * map.getTileSize().x,
                                           (float) std::get<1>(id) * map.getTileSize().y};

                std::cout<<"Fuck \n";
                int baseTilePositon = (tile->getId() - firstId);
                int tileModX = (baseTilePositon % columns);
                int currentRow = (baseTilePositon / columns);
                int offsetx = tileModX * (map.getTileSize().x + space) + margin;
                int offsetY = currentRow * (map.getTileSize().y + space) + margin;

                tile_rec.x = offsetx;
                tile_rec.y = offsetY;
                std::cout<<"Final F*ck \n";
                DrawTextureRec(map_tex, tile_rec, {position.x, position.y}, WHITE);
                std::cout<<"Final F*ck \n";
            }
        }
    }
}
*/