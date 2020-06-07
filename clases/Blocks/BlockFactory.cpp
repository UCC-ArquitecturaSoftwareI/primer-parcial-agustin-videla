//
// Created by Agus on 17/4/2020.
//

#include "BlockFactory.h"
#include "../Vector2Functions/VectorTransform.h"

/**
 *
 * @param element
 * @param type
 * @param xCoordinates
 * @return
 */
 Block* BlockFactory::create(std::string element, int type, Vector2 xCoordinates) {
     if(element == "Tierra")
         return new Block_Dirt(xCoordinates);

     if(element == "iron")
         return new Block_Iron(xCoordinates);
}