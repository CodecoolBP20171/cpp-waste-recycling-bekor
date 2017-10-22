//
// Created by Joe Bekor on 19/10/2017.
//

#include "Dustbin.h"

Dustbin::Dustbin(int type, std::string &color, const unsigned size)
{
    std::cout << "Garbage type: " << type << std::endl;
    color = color;
    garbage = nullptr;
    try {
        garbage = new Garbage[size];
        garbagePointer = garbage;
        garbageEndPointer = garbagePointer + size;

    } catch (std::bad_alloc&){
        garbagePointer = nullptr;
        garbageEndPointer = nullptr;
    }
//
//    paperGarbage = nullptr;
//    try {
//        paperGarbage = new PaperGarbage[sizePaperGarbage];
//        paperGarbagePointer = paperGarbage;
//        paperGarbageEndPointer = paperGarbagePointer + sizePaperGarbage;
//
//    } catch (std::bad_alloc&){
//        paperGarbagePointer = nullptr;
//        paperGarbageEndPointer = nullptr;
//    }
//
//    plasticGarbage = nullptr;
//    try {
//        plasticGarbage = new PlasticGarbage[sizeGarbage];
//        garbagePointer = plasticGarbage;
//        garbageEndPointer = garbagePointer + sizeGarbage;
//
//    } catch (std::bad_alloc&){
//        garbagePointer = nullptr;
//        garbageEndPointer = nullptr;
//    }
}

Dustbin::~Dustbin() {
    delete[] garbage;
    std::cout << ">  ~Dustbin called!" << std::endl;
}

void Dustbin::throwOutGarbage(Garbage garbage) {
    if(garbagePointer < garbageEndPointer && garbage.getType() == 1) {
        *garbagePointer = garbage;
        ++garbagePointer;
        return;
    }
    throw DustbinContentError();
}

void Dustbin::throwOutPaperGarbage(PaperGarbage paperGarbage) {
    if(!paperGarbage.isPaperSqueezed() || paperGarbage.getType() != 2){
        throw DustbinContentError();
    }
    if(garbagePointer < garbageEndPointer) {
        /*  In this example I do not have to bother with the extra parameter from PaperGarbage class
            If I want to extend the PaperGarbage then it is possible I have to modify this part too.
         */
        *garbagePointer = paperGarbage;
        ++garbagePointer;
        return;
    }
    throw DustbinContentError();
}

void Dustbin::throwOutPlasticGarbage(PlasticGarbage plasticGarbage) {
    if(!plasticGarbage.isPlasticClean() || plasticGarbage.getType() != 2){
        throw DustbinContentError();
    }
    if(garbagePointer < garbageEndPointer) {
        /*  In this example I do not have to bother with the extra parameter from PlasticGarbage class
            If I want to extend the PlasticGarbage then it is possible I have to modify this part too.
         */
        *garbagePointer = plasticGarbage;
        ++garbagePointer;
        return;
    }
    throw DustbinContentError();
}

void Dustbin::emptyContents() {
    while(garbagePointer > garbage){
        --garbagePointer;
    }
    std::cout << ">  Dustbin emptied, size: " << sizeGarbage() << ", space left: " << spaceLeft() << std::endl;
}
