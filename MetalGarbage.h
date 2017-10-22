//
// Created by Joe Bekor on 21/10/2017.
//

#ifndef CPP_WASTE_RECYCLING_BEKOR_METALGARBAGE_H
#define CPP_WASTE_RECYCLING_BEKOR_METALGARBAGE_H

#include "Garbage.h"

class MetalGarbage {
public:
    MetalGarbage(const std::string &name = "defaultGarbage"): name(name){
        type = 4;
    };
    int getType() { return  type; }
protected:
    int type;
    std::string name;
};


#endif //CPP_WASTE_RECYCLING_BEKOR_METALGARBAGE_H
