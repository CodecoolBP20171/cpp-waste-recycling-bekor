//
// Created by Joe Bekor on 21/10/2017.
//

#include "Dustbin9000.h"

Dustbin9000::Dustbin9000(std::string &color,
                         const unsigned int sizeGarb,
                         const unsigned int sizePaper,
                         const unsigned int sizePlastic,
                         const unsigned int sizeMetal,
                         const unsigned sizeBCup) : Dustbin(color, sizeGarb, sizePaper, sizePlastic)
{
    metalGarbage = nullptr;
    try {
        metalGarbage = new MetalGarbage[sizeMetal];
        metalGarbagePointer = metalGarbage;
        metalGarbageEndPointer = metalGarbagePointer + sizeMetal;

    } catch (std::bad_alloc&){
        metalGarbagePointer = nullptr;
        metalGarbageEndPointer = nullptr;
    }

    bottleCupGarbage = nullptr;
    try {
        bottleCupGarbage = new BottleCupGarbage[sizeBCup];
        bottleCupGarbagePointer = bottleCupGarbage;
        bottleCupGarbageEndPointer = bottleCupGarbagePointer + sizeBCup;

    } catch (std::bad_alloc&){
        bottleCupGarbagePointer = nullptr;
        bottleCupGarbageEndPointer = nullptr;
    }
}

Dustbin9000::~Dustbin9000() {
    delete[] metalGarbage;
    delete[] bottleCupGarbage;
}

void Dustbin9000::throwOutMetalGarbage(MetalGarbage metal) {
    if(metalGarbagePointer < metalGarbageEndPointer && metal.getType() == garbageType::METAL) {
        *metalGarbagePointer = metal;
        ++metalGarbagePointer;
        return;
    }
    throw DustbinContentError();
}

void Dustbin9000::throwOutBottleCupGarbage(BottleCupGarbage cupGarbage) {
    if(!cupGarbage.isBottleCupPurple() || cupGarbage.getType() != garbageType::BOTTLECUP){
        throw BottleCapException();
    }
    if(bottleCupGarbagePointer < bottleCupGarbageEndPointer) {
        *bottleCupGarbagePointer = cupGarbage;
        ++bottleCupGarbagePointer;
        return;
    }
    throw DustbinContentError();

}

void Dustbin9000::emptyContents() {
    Dustbin::emptyContents();
    metalGarbagePointer = metalGarbage;
    bottleCupGarbagePointer = bottleCupGarbage;
    std::cout << ">  Dustbin emptied, metal size: " << sizeMetalGarbage() << ", space left: " << spaceLeftMetal() << std::endl;
    std::cout << ">  Dustbin emptied, bottle cap size: " << sizeBottleCupGarbage() << ", space left: " << spaceLeftBottleCup() << std::endl;
}
