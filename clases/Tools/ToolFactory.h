//
// Created by ribet on 21/4/2020.
//

#ifndef RAYLIBTEMPLATE_TOOLFACTORY_H
#define RAYLIBTEMPLATE_TOOLFACTORY_H

#include <iostream>
#include "Tool.h"
#include "Tool_Pickaxe.h"
#include "string"

class ToolFactory{
public:
    static Tool *create(std::string name){
        //if(name == "pickaxe")
            return new Pickaxe();
    }
};

#endif //RAYLIBTEMPLATE_TOOLFACTORY_H
