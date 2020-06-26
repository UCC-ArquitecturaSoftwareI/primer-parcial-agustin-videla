//
// Created by ribetti on 24/6/2020.
//

#ifndef SQUARECRAFT_COMMAND_H
#define SQUARECRAFT_COMMAND_H

class command {
public:
    virtual ~command() {
    }
    virtual void  execute() const = 0;
};


#endif //SQUARECRAFT_COMMAND_H
