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
        std::cout<<"se creo el pico, ahora puedes picotear \n";
    } //constructor
    int getdamage() { std::cout<<"el daño causado es 10 \n";
                        return 0;
    };

};

#endif //RAYLIBTEMPLATE_TOOL_PICKAXE_H
