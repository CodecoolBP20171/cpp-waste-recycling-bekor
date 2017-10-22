//
// Created by Joe Bekor on 19/10/2017.
//

#ifndef CPP_WASTE_RECYCLING_BEKOR_DUSTBIN_H
#define CPP_WASTE_RECYCLING_BEKOR_DUSTBIN_H

#include <memory>
#include <iostream>

#include "Garbage.h"
#include "PaperGarbage.h"
#include "PlasticGarbage.h"
#include "DustbinContentError.hpp"

class Dustbin {
public:
    Dustbin(int type, std::string &color, const unsigned size = 10);
    virtual ~Dustbin();
    size_t sizeGarbage() const { return garbageEndPointer - garbage; }
    size_t spaceLeft() const { return garbageEndPointer - garbagePointer; }
//    size_t sizePaperGarbage() const { return paperGarbageEndPointer - paperGarbage; }
//    size_t sizePlasticGarbage() const { return plasticGarbageEndPointer - plasticGarbage; }
    void throwOutGarbage(Garbage garbage);
    void throwOutPaperGarbage(PaperGarbage paperGarbage);
    void throwOutPlasticGarbage(PlasticGarbage plasticGarbage);
    void emptyContents();
    std::string getColor() { return color; }

private:
    std::string color;
    Garbage* garbage;
    Garbage* garbagePointer;
    Garbage* garbageEndPointer;

//    PaperGarbage* paperGarbage;
//    PaperGarbage* paperGarbagePointer;
//    PaperGarbage* paperGarbageEndPointer;
//
//    PlasticGarbage* plasticGarbage;
//    PlasticGarbage* plasticGarbagePointer;
//    PlasticGarbage* plasticGarbageEndPointer;
};


#endif //CPP_WASTE_RECYCLING_BEKOR_DUSTBIN_H
