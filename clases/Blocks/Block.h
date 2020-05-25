//
// Created by Agus on 17/4/2020.
//

#ifndef RAYLIBTEMPLATE_BLOCK_H
#define RAYLIBTEMPLATE_BLOCK_H

#include <raylib.h>
#include <iostream>
#include <string>

class Block {
protected:
    Color texture{};
    //Vector2 coordinates{};
    static Vector2 size;
    Rectangle cage; //todo debuggear colisiones
    int Gid = 12;
public:
    explicit Block(Vector2 xCoordinates);
    ~Block();
    //virtual void setCoordinates(Vector2 xCoordinates) { this->coordinates = xCoordinates; }
    //virtual Vector2 getCoordinates() { return coordinates; }
    virtual  Rectangle getCage();
    static Vector2 getSize();
    virtual Color getColor();
    int getGid();
};

#endif //RAYLIBTEMPLATE_BLOCK_H
