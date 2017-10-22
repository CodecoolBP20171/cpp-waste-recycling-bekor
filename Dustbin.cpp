//
// Created by Joe Bekor on 19/10/2017.
//

#include "Dustbin.h"

Dustbin::Dustbin(std::string &color, const unsigned int sizeGarb, const unsigned int sizePaper,
                 const unsigned int sizePlastic) : color(color){
    garbage = nullptr;
    try {
        garbage = new Garbage[sizeGarb];
        garbagePointer = garbage;
        garbageEndPointer = garbagePointer + sizeGarb;

    } catch (std::bad_alloc&){
        garbagePointer = nullptr;
        garbageEndPointer = nullptr;
    }

    paperGarbage = nullptr;
    try {
        paperGarbage = new PaperGarbage[sizePaper];
        paperGarbagePointer = paperGarbage;
        paperGarbageEndPointer = paperGarbagePointer + sizePaper;

    } catch (std::bad_alloc&){
        paperGarbagePointer = nullptr;
        paperGarbageEndPointer = nullptr;
    }

    plasticGarbage = nullptr;
    try {
        plasticGarbage = new PlasticGarbage[sizePlastic];
        plasticGarbagePointer = plasticGarbage;
        plasticGarbageEndPointer = plasticGarbage + sizePlastic;

    } catch (std::bad_alloc&){
        plasticGarbagePointer = nullptr;
        plasticGarbageEndPointer = nullptr;
    }
}

Dustbin::~Dustbin() {
    delete[] garbage;
    delete[] paperGarbage;
    delete[] plasticGarbage;
}

void Dustbin::throwOutGarbage(Garbage garbage) {
    if(garbagePointer < garbageEndPointer && garbage.getType() == 0) {
        *garbagePointer = garbage;
        ++garbagePointer;
        return;
    }
    throw DustbinContentError();
}

void Dustbin::throwOutPaperGarbage(PaperGarbage paperGarbage) {
    if(!paperGarbage.isPaperSqueezed() || paperGarbage.getType() != 1){
        throw DustbinContentError();
    }
    if(paperGarbagePointer < paperGarbageEndPointer) {
        *paperGarbagePointer = paperGarbage;
        ++paperGarbagePointer;
        return;
    }
    throw DustbinContentError();
}

void Dustbin::throwOutPlasticGarbage(PlasticGarbage plasticGarbage) {
    if(!plasticGarbage.isPlasticClean() || plasticGarbage.getType() != 2){
        throw DustbinContentError();
    }
    if(plasticGarbagePointer < plasticGarbageEndPointer) {
        *plasticGarbagePointer = plasticGarbage;
        ++plasticGarbagePointer;
        return;
    }
    throw DustbinContentError();
}

void Dustbin::emptyContents() {
    garbagePointer = garbage;
    paperGarbagePointer = paperGarbage;
    plasticGarbagePointer = plasticGarbage;
    std::cout << ">  Dustbin emptied, garbage size: " << sizeGarbage() << ", space left: " << spaceLeftGarbage() << std::endl;
    std::cout << ">  Dustbin emptied, paper size: " << sizePaperGarbage() << ", space left: " << spaceLeftPaper() << std::endl;
    std::cout << ">  Dustbin emptied, plastic size: " << sizePlasticGarbage() << ", space left: " << spaceLeftPlastic() << std::endl;
}
