
#ifndef RAYLIBTEMPLATE_TOOL_H
#define RAYLIBTEMPLATE_TOOL_H

#include <raylib.h>
#include <string>

class Tool{

protected:
    int damage{};
public:
   //virtual void draw() const = 0;
   virtual int getdamage() = 0;
};

#endif //RAYLIBTEMPLATE_TOOL_H
