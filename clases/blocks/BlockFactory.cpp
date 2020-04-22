//
// Created by Agus on 17/4/2020.
//

#include "BlockFactory.h"

 Block* BlockFactory::create(std::string element, int type, Vector2 xCoordinates) {
     if(element == "dirt"){
         if(type == 1)  return new Block_Dirt(xCoordinates);
     }
     if(element == "iron")  return new Block_Iron(xCoordinates);
}


