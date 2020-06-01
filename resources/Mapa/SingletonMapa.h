//
// Created by ribet on 18/5/2020.
//

#ifndef SQUARECRAFT_SINGLETONMAPA_H
#define SQUARECRAFT_SINGLETONMAPA_H

#include <string>
#include <raylib.h>
#include "../../Libraries/tileson.hpp"
#include "../../clases/Vector2Functions/HashFacade.h"
#include "../../clases/Blocks/BlockFactory.h"


//SingletonMapa &mapa = SingletonMapa::getInstance("../resources/Mapa/EntitledMap1.json");
/**
 * Clase que contiene el mapa junto a todos sus datos y que es un singleton
 */
class SingletonMapa {
private:
    Hash hash;
    BlockFactory* factory;
    tson::Map map;
    Texture2D map_tex;
    tson::Tileset *map_tileset;
    SingletonMapa(const std::string file);
    int getPos (int a, int b, char c);
public:
    static SingletonMapa &getInstance(const std::string file);
    Texture2D getTexture();
    Rectangle getRec(int Gid);
};

#endif //SQUARECRAFT_SINGLETONMAPA_H
