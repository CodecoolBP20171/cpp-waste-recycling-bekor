//
// Created by Joe Bekor on 19/10/2017.
//

#ifndef CPP_WASTE_RECYCLING_BEKOR_DUSTBIN_H
#define CPP_WASTE_RECYCLING_BEKOR_DUSTBIN_H

#import "Garbage.h"
#import "PaperGarbage.h"
#import "PlasticGarbage.h"


class Dustbin {
public:
    void throwOutGarbage(Garbage garbage);
    void throwOutPaperGarbage(PaperGarbage paperGarbage);
    void throwOutPlasticGarbage(PlasticGarbage plasticGarbage);
    void emptyContents();

private:
    std::string color;
    PaperGarbage paperContent[10];
    PlasticGarbage plasticContent[10];
    Garbage houseWasteContent[10];

};


#endif //CPP_WASTE_RECYCLING_BEKOR_DUSTBIN_H
