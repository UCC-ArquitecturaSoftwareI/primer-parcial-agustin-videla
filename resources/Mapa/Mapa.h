//
// Created by facu on 15/5/20.
//

#ifndef SQUARECRAFT_MAPA_H
#define SQUARECRAFT_MAPA_H
#include <string>
#include <raylib.h>
#include "Libraries/tileson.hpp"


class Mapa {
    tson::Map map;
    Texture2D map_tex;
    tson::Tileset *map_tileset;

public:
    Vector2 player_init_pos; //cuando creemos player, la posicion inicial es esta
    Mapa(std::string file);

    void dibujar();
};


#endif //SQUARECRAFT_MAPA_H
