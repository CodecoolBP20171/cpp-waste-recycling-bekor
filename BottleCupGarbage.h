//
// Created by bekor on 10/22/17.
//

#ifndef CPP_WASTE_RECYCLING_BEKOR_BOTTLECUPGARBAGE_H
#define CPP_WASTE_RECYCLING_BEKOR_BOTTLECUPGARBAGE_H

#include "Garbage.h"

class BottleCupGarbage: public Garbage {
public:
    BottleCupGarbage(const std::string &name = "cup", const std::string &color = "purple")
            : Garbage(name), color(color){
        type = garbageType::BOTTLECUP;
    }
    bool isBottleCupPurple(){ return color == "purple"; }

private:
    std::string color;
};


#endif //CPP_WASTE_RECYCLING_BEKOR_BOTTLECUPGARBAGE_H
