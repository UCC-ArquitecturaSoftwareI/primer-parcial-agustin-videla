//
// Created by facu on 15/5/20.
//

#ifndef SQUARECRAFT_MAPA_H
#define SQUARECRAFT_MAPA_H
#include <string>
#include <raylib.h>
#include "../../Libraries/tileson.hpp"


class Mapa {
    tson::Map map;
    Texture2D map_tex;
    tson::Tileset *map_tileset;

public:
    Vector2 player_init_pos; //cuando creemos player, la posicion inicial es esta
    Mapa(std::string file);

    void dibujar();
};

//
// Created by facu on 15/5/20.
//

Mapa::Mapa(std::string file) {
    tson::Tileson parser;
    map = parser.parse("../resources/Mapa/entitledMap.json");

    std::cout<<"fuck \n";

    if(map.getStatus() == tson::ParseStatus::OK) {

        std::cout<<"fuck \n";

        for (auto &tileset : map.getTilesets()){
            std::cout<<"fuck3 \n";
            map_tex = LoadTexture(fs::path("../resources/Mapa/" + tileset.getImage().string()).c_str());
            std::cout<<"fuck4 \n";
            map_tileset = &tileset;
        }
        std::cout<<"fuck5 \n";

        auto objs = map.getLayer("Floor"); //obtengo la capa de suelo
        tson::Object *player = objs->firstObj("Player"); //obtengo los datos del jugador
        //player_init_pos.x = player->getPosition().x;
        //player_init_pos.y = player->getPosition().y;


        for(auto &obj : objs->getObjects()){
            //revisa todos los objetos
            std::cout<<"Nombre: " << obj.getName() << std::endl;
        }

    }

}

void Mapa::dibujar() {
    std::cout<<"hola \n";
}

#endif //SQUARECRAFT_MAPA_H
