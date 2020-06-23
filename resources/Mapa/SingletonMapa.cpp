//
// Created by ribet on 25/5/2020.
//
#include "SingletonMapa.h"
#include "../../clases/Vector2Functions/VectorTransform.h"

/**
 * intialize all the data contained in the Json and load it into the correspondent place
 * @param file : direction of the Json file
 */
SingletonMapa::SingletonMapa(const std::string file){

    Player &Player = Player::getInstance();

    tson::Tileson parser;
    //tson::Map map = parser.parse(fs::path("../resources/Mapa/EntitledMap1.json"));
    map = parser.parse("../resources/Mapa/EntitledMap2.json");
    if(map.getStatus() == tson::ParseStatus::OK) {
        for (auto &tileset : map.getTilesets()){
            map_tex = LoadTexture("../resources/Mapa/totatilly-not-minecraft-textures.png");
            //map_tex = LoadTexture(fs::path("resources/Mapa/" + tileset.getImage().string()).c_str());
            map_tileset = &tileset;
        }

        auto objs = map.getLayer("Objetos"); //obtengo la capa Objetos

        for(auto &obj : objs->getObjects()){
            //revisa todos los objetos
            Vector2 position = mouseTransform({(float)obj.getPosition().x, (float)obj.getPosition().y});
            hash.put(position, factory->create(obj.getType(), obj.getName(), position));
        }
    }
}
/**
 * Returns the row or column in wich the texture would be
 * @param a : Gid of the block
 * @param b
 * @param c : to select between rows and columns
 * @return a: for rows, b: for columns
 */
int  SingletonMapa::getPos(int a, int b, char c) {
    if(a < 17) {
        if (c == 'x')
            return a - 1;
        if (c == 'y')
            return b;
        return 0;
        //debería de tirar una excepción? yo creo que no
    }
    else
        getPos (a - 16, b + 1, c);
}
/**
 *  return the only existing instance of the class
 * @param file
 * @return
 */
SingletonMapa& SingletonMapa::getInstance(const std::string file) {
    static SingletonMapa mapa(file);
    return mapa;
}

Texture2D SingletonMapa::getTexture() {
    return map_tex;
}
/**
 * return the rectangle of where the blocks is in the tileset
 * @param Gid: Gid of the block
 * @return
 */
Rectangle SingletonMapa::getRec(int Gid) { //esta es la posicion y tamaño de la textura individual a dibujar
    Rectangle tile_rec;

    if(Gid < 16)
        tile_rec.x = (16.0f) * Gid;
    else
        tile_rec.x = (16.0f) * getPos(Gid, 0, 'x');

    if(Gid < 16)
        tile_rec.y = 0.0f;
    else
        tile_rec.y = (16.0f) * getPos(Gid, 0, 'y');

    tile_rec.width = map.getTileSize().x;
    tile_rec.height = map.getTileSize().y;
    return tile_rec;
}

