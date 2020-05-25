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
    static Vector2 size;
    Rectangle cage;
    int Gid = 12;
public:
    explicit Block(Vector2 xCoordinates);

    ~Block() { std::cout << "me rompi ahre" << '\n'; };

    virtual Vector2 getPos() { return {cage.x,cage.y}; }

    virtual  Rectangle getCage() { return cage; }

    static Vector2 getSize() { return size; }

    virtual Color getColor() { return texture; }

    int getGid(){ return Gid;}
};

#endif //RAYLIBTEMPLATE_BLOCK_H
