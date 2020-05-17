//
// Created by facu on 15/5/20.
//

#ifndef SQUARECRAFT_MAPA_H
#define SQUARECRAFT_MAPA_H
#include <string>
#include <raylib.h>
#include "../../Libraries/tileson.hpp"

//mapa = new Mapa("../resources/Mapa/entitledMap.json"); //cuando creemos player, la posicion iniial es la dada por Vector2 player_init_pos;
class Mapa {
    tson::Map map;
    Texture2D map_tex;
    tson::Tileset *map_tileset;

public:
    Vector2 player_init_pos; //cuando creemos player, la posicion inicial es esta
    Mapa(std::string file);

    void dibujar();
};


Mapa::Mapa(std::string file) {
    tson::Tileson parser;
    map = parser.parse("../resources/Mapa/entitledMap.json");

    if(map.getStatus() == tson::ParseStatus::OK) {
        for (auto &tileset : map.getTilesets()){
            map_tex = LoadTexture("../resources/Mapa/totatilly-not-minecraft-textures.png");
            //map_tex = LoadTexture(fs::path("resources/Mapa/" + tileset.getImage().string()).c_str());
            map_tileset = &tileset;
        }

        auto objs = map.getLayer("Capa de Objetos 1"); //obtengo la capa de suelo
        tson::Object *player = objs->firstObj("Player"); //obtengo los datos del jugador
        //player_init_pos.x = player->getPosition().x;
        //player_init_pos.y = player->getPosition().y;

        std::cout<<"posicion x: " << player->getPosition().x;
        std::cout<<"posicion y: " << player->getPosition().y;

        for(auto &obj : objs->getObjects()){
            //revisa todos los objetos
            std::cout<<"Nombre: " << obj.getName() << std::endl;
        }

    }
}

void Mapa::dibujar() {
    Rectangle tile_rec;
    tile_rec.x = 0.0f;
    tile_rec.y = 0.0f;
    tile_rec.width = map.getTileSize().x;
    tile_rec.height = map.getTileSize().y;

    int firstId = map_tileset->getFirstgid(); //First tile id of the tileset
    int columns = map_tileset->getColumns(); //For the demo map it is 8.
    int margin = map_tileset->getMargin();
    int space = map_tileset->getSpacing();

    auto &c = map.getBackgroundColor();
    ClearBackground({c.r ,c.g, c.b, c.a}); // limpio la pantalla con el color de fondo del mapa

    for (auto nombre: {"Floor"}){ //nombre que yo le doy a las capas y las dibuja en el orden escrito
        auto *layer = map.getLayer("Floor");
        //std::cout<<"F*ck \n";
        for (auto&[pos, tile] : layer->getTileData()){ // loops through all existing tiles
            if(tile != nullptr) {
                tson::Vector2f position = { (float) std::get<0>(pos) * map.getTileSize().x,
                                            (float) std::get<1>(pos) * map.getTileSize().y};

                int baseTilePositon = (tile->getId() - firstId);
                std::cout<<"F*ck \n";
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
#endif //SQUARECRAFT_MAPA_H