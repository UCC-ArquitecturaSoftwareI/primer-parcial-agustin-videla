//
// Created by Agus on 17/4/2020.
//

#ifndef RAYLIBTEMPLATE_BLOCK_H
#define RAYLIBTEMPLATE_BLOCK_H

#include <raylib.h>
#include <string>

class Block {
protected:
    std::string texture;
    Vector2 coordinates{};
    Vector2 size = {20, 20};
public:
    Block(Vector2 xCoordinates) { this->coordinates = xCoordinates; }
    virtual void setCoordinates(Vector2 xCoordinates) { this->coordinates = xCoordinates; }
    virtual int getX() { return (int)coordinates.x; }
    virtual int getY() { return (int)coordinates.y; }
    virtual Vector2 getSize() { return size; }
};


#endif //RAYLIBTEMPLATE_BLOCK_H
