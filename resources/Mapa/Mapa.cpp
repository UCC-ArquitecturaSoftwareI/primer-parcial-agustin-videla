//
// Created by facu on 15/5/20.
//

#include "Mapa.h"
#include "Libraries/tileson.hpp"

Mapa::Mapa(std::string file) {
    tson::Tileson parser;
    map = parser.parse(fs::path(file));

    if(map.getStatus() == tson::ParseStatus::OK) {

        for (auto &tileset : map.getTilesets){
            map_tex = LoadTexture(fs::path("resources" + tileset.getImage().string()).c_str());
            map_tileset = &tileset;
        }

        auto objs = map.getLayer("Floor"); //obtengo la capa de suelo
        tson::Object *player = objs.firstObj("Player"); //obtengo los datos del jugador
        player_init_pos.x = player.getPositon().x;
        player_init_pos.y = player.getPositon().y;

        for(auto &objs : objs->getObjects()){
         //revisa todos los objetos
        }

    }

}

void Mapa::dibujar() {

}
