//
// Created by ribet on 21/4/2020.
//

#include "ToolFactory.h"

Tool *ToolFactory::create(std::string name) {
    if(name == "pickaxe")
        return new Pickaxe();
}