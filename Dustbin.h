//
// Created by Joe Bekor on 19/10/2017.
//

#ifndef CPP_WASTE_RECYCLING_BEKOR_DUSTBIN_H
#define CPP_WASTE_RECYCLING_BEKOR_DUSTBIN_H

#include <memory>

#include "Garbage.h"
#include "PaperGarbage.h"
#include "PlasticGarbage.h"
#include "DustbinContentError.hpp"

class Dustbin {
public:
    Dustbin(std::string &color, const unsigned sizeGarb = 10, const unsigned sizePaper = 10, const unsigned sizePlastic = 10);
    virtual ~Dustbin();
    size_t sizeGarbage() const { return garbageEndPointer - garbage; }
    size_t spaceLeftGarbage() const { return garbageEndPointer - garbagePointer; }

    size_t sizePaperGarbage() const { return paperGarbageEndPointer - paperGarbage; }
    size_t spaceLeftPaper() const { return garbageEndPointer - garbagePointer; }

    size_t sizePlasticGarbage() const { return plasticGarbageEndPointer - plasticGarbage; }
    size_t spaceLeftPlastic() const { return garbageEndPointer - garbagePointer; }

    void throwOutGarbage(Garbage garbage);
    void throwOutPaperGarbage(PaperGarbage paperGarbage);
    void throwOutPlasticGarbage(PlasticGarbage plasticGarbage);

    void emptyContents();

private:
    std::string color;
    Garbage* garbage;
    Garbage* garbagePointer;
    Garbage* garbageEndPointer;

    PaperGarbage* paperGarbage;
    PaperGarbage* paperGarbagePointer;
    PaperGarbage* paperGarbageEndPointer;

    PlasticGarbage* plasticGarbage;
    PlasticGarbage* plasticGarbagePointer;
    PlasticGarbage* plasticGarbageEndPointer;
};


#endif //CPP_WASTE_RECYCLING_BEKOR_DUSTBIN_H
