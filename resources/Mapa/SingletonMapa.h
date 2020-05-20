//
// Created by ribet on 18/5/2020.
//

#ifndef SQUARECRAFT_SINGLETONMAPA_H
#define SQUARECRAFT_SINGLETONMAPA_H

#include <string>
#include <raylib.h>
#include "../../Libraries/tileson.hpp"

//SingletonMapa &mapa = SingletonMapa::getInstance("../resources/Mapa/EntitledMap1.json");

class SingletonMapa {
private:
    tson::Map map;
    Texture2D map_tex;
    tson::Tileset *map_tileset;
    SingletonMapa(const std::string file)
    {
        std::cout<<"Fuck \n";
        tson::Tileson parser;
        //tson::Map map = parser.parse(fs::path("../resources/Mapa/EntitledMap1.json"));
        map = parser.parse("../resources/Mapa/EntitledMap1.json");
        if(map.getStatus() == tson::ParseStatus::OK) {
            for (auto &tileset : map.getTilesets()){
                std::cout<<"Fuck \n";
                map_tex = LoadTexture("../resources/Mapa/totatilly-not-minecraft-textures.png");
                //map_tex = LoadTexture(fs::path("resources/Mapa/" + tileset.getImage().string()).c_str());
                map_tileset = &tileset;
            }

            auto objs = map.getLayer("Objetos"); //obtengo la capa objetos
            //tson::Object *player = objs->firstObj("Player"); //obtengo los datos del jugador
            //player_init_pos.x = player->getPosition().x;
            //player_init_pos.y = player->getPosition().y;

            //std::cout<<"posicion x: " << player->getPosition().x;
            //std::cout<<"posicion y: " << player->getPosition().y;

            for(auto &obj : objs->getObjects()){
                //revisa todos los objetos
            }
        }

    }
    int getCol (int a, int b){
        if(a < 17)
            return a;
        else
            getCol (a - 16, b + 1);
    }
    int getRow(int a, int b){
        if (a < 17)
            return b;
        else
            getRow(a - 16, b + 1);
    }
public:
    static SingletonMapa &getInstance(const std::string file){
        static SingletonMapa mapa(file);
        return mapa;
    }
    Texture2D getTexture(){
        return map_tex;
    }
    Rectangle getRec(int Gid){ //esta es la posicion y tamaño de la textura individual a dibujar
        Rectangle tile_rec;

        if(Gid < 16)
            tile_rec.x = (16.0f) * Gid;
        else
            tile_rec.x = (16.0f) * getCol(Gid, 0);

        if(Gid < 16)
            tile_rec.y = 0.0f;
        else
            tile_rec.y = (16.0f) * getRow(Gid, 0);

        tile_rec.width = map.getTileSize().x;
        tile_rec.height = map.getTileSize().y;
        return tile_rec;
    }
};


#endif //SQUARECRAFT_SINGLETONMAPA_H
