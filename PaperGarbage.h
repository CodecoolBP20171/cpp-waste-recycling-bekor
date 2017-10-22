//
// Created by Joe Bekor on 19/10/2017.

#ifndef CPP_WASTE_RECYCLING_BEKOR_PAPERGARBAGE_H
#define CPP_WASTE_RECYCLING_BEKOR_PAPERGARBAGE_H

// This is the class containing the business logic of a garbage made of paper. PaperGarbage class inherits from the Garbage class.

#include "Garbage.h"

class PaperGarbage: public Garbage {
public:
    PaperGarbage(const std::string &name = "defaultPaper") : Garbage(name){
        type = 2;
        isSqueezed = false;
    }
    void squeeze(){isSqueezed = true;}
    bool isPaperSqueezed(){ return isSqueezed; }

private:
    bool isSqueezed;
};


#endif //CPP_WASTE_RECYCLING_BEKOR_PAPERGARBAGE_H
