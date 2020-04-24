//
// Created by ribet on 21/4/2020.
//

#ifndef RAYLIBTEMPLATE_TOOL_PICKAXE_H
#define RAYLIBTEMPLATE_TOOL_PICKAXE_H

#include <iostream>
#include "Tool.h"

class Pickaxe : public Tool {

public:
    Pickaxe(){
        damage = 10; 
    } //constructor
    int getdamage();
};

#endif //RAYLIBTEMPLATE_TOOL_PICKAXE_H
