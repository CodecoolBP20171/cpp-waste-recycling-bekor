//
// Created by Joe Bekor on 19/10/2017.
//

#ifndef CPP_WASTE_RECYCLING_BEKOR_PLASTICGARBAGE_H
#define CPP_WASTE_RECYCLING_BEKOR_PLASTICGARBAGE_H

// This is the class containing the business logic of a garbage made of plastic. PlasticGarbage class inherits from the Garbage class.

#include "Garbage.h"

class PlasticGarbage: public Garbage {
public:
    PlasticGarbage(const std::string &name = "defaultPlastic"): Garbage(name){
        type = garbageType::PLASTIC;
        isClean = false;
    }
    void clean() {isClean = true;}
    bool isPlasticClean(){ return isClean; }

protected:
    bool isClean;
};


#endif //CPP_WASTE_RECYCLING_BEKOR_PLASTICGARBAGE_H
