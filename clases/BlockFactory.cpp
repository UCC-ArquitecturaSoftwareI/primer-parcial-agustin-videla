//
// Created by Agus on 17/4/2020.
//

#include "BlockFactory.h"

Block_Dirt BlockFactory::createBlock(int type, Vector2 xCoordinates) {
    if(type == 1) {
        return(Block_Dirt(xCoordinates));
    }


    return Block_Dirt(Vector2());
}
