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
 Block* BlockFactory::create(std::string element, std::string type, Vector2 xCoordinates) {
     if(element == "dirt"){
         return new Block_Dirt(xCoordinates, type);
     }
     if(element == "iron")
         return new Block_Iron(xCoordinates, "0");
    if(element == "END")
         return new Block_Iron(xCoordinates, "1");
    //debo de tirar una excepcion cuando no exista el bloque y no se pueda crear
}