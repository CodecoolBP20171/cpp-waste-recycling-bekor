//
// Created by Joe Bekor on 21/10/2017.
//

#ifndef CPP_WASTE_RECYCLING_BEKOR_METALGARBAGE_H
#define CPP_WASTE_RECYCLING_BEKOR_METALGARBAGE_H

#include "Garbage.h"

class MetalGarbage: public Garbage {
public:
    MetalGarbage(const std::string &name = "defaultGarbage"): name(name){
        type = 3;
    };
protected:
    std::string name;
};


#endif //CPP_WASTE_RECYCLING_BEKOR_METALGARBAGE_H
