//
// Created by Joe Bekor on 21/10/2017.
//

#ifndef CPP_WASTE_RECYCLING_BEKOR_DUSTBIN9000_H
#define CPP_WASTE_RECYCLING_BEKOR_DUSTBIN9000_H

#include "Dustbin.h"
#include "MetalGarbage.h"
#include "BottleCupGarbage.h"
#include "BottleCapException.hpp"

class Dustbin9000: public Dustbin {
public:
    Dustbin9000(std::string &color,
                const unsigned sizeGarb = 10,
                const unsigned sizePaper = 10,
                const unsigned sizePlastic = 10,
                const unsigned sizeMetal = 10,
                const unsigned sizeBCup = 10);
    virtual ~Dustbin9000();
    size_t sizeMetalGarbage() const { return metalGarbageEndPointer - metalGarbage; }
    size_t spaceLeftMetal() const { return metalGarbageEndPointer - metalGarbagePointer; }

    size_t sizeBottleCupGarbage() const { return bottleCupGarbageEndPointer - bottleCupGarbage; }
    size_t spaceLeftBottleCup() const { return bottleCupGarbageEndPointer - bottleCupGarbagePointer; }

    void throwOutMetalGarbage(MetalGarbage metal);
    void throwOutBottleCupGarbage(BottleCupGarbage cupGarbage);

    void emptyContents();
private:
    MetalGarbage* metalGarbage;
    MetalGarbage* metalGarbagePointer;
    MetalGarbage* metalGarbageEndPointer;

    BottleCupGarbage* bottleCupGarbage;
    BottleCupGarbage* bottleCupGarbagePointer;
    BottleCupGarbage* bottleCupGarbageEndPointer;

};


#endif //CPP_WASTE_RECYCLING_BEKOR_DUSTBIN9000_H
