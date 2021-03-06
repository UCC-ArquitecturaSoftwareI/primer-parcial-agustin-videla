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
    static Vector2 size;
    Rectangle cage;
    int Gid = 12;
public:
    explicit Block(Vector2 xCoordinates, std::string type);

    ~Block();

    virtual  Rectangle getCage();

    static Vector2 getSize();

    int getGid();
};

#endif //RAYLIBTEMPLATE_BLOCK_H
