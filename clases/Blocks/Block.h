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
    Vector2 coordinates{};
    Vector2 size = {20, 20};
public:
    explicit Block(Vector2 xCoordinates) { this->coordinates = xCoordinates; }
    ~Block() { std::cout << "me rompi ahre" << '\n'; };
    virtual void setCoordinates(Vector2 xCoordinates) { this->coordinates = xCoordinates; }
    virtual Vector2 getCoordinates() { return coordinates; }
    virtual Vector2 getSize() { return size; }
    virtual Color getColor() { return texture; }
};


#endif //RAYLIBTEMPLATE_BLOCK_H
