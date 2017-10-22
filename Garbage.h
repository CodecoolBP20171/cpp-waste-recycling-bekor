//
// Created by Joe Bekor on 19/10/2017.

#ifndef CPP_WASTE_RECYCLING_BEKOR_GARBAGE_H
#define CPP_WASTE_RECYCLING_BEKOR_GARBAGE_H

// This is the class containing a regular garbage's business logic.

#include <string>

class Garbage {
public:
    Garbage(const std::string &name = "defaultGarbage"): name(name){
        type = 1;
    };
    int getType() { return  type; }
protected:
    int type;
    std::string name;
};


#endif //CPP_WASTE_RECYCLING_BEKOR_GARBAGE_H
