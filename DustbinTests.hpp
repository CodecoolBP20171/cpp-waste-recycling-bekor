//
// Created by Joe Bekor on 19/10/2017.
//

#ifndef CPP_WASTE_RECYCLING_BEKOR_DUSTBINTESTS_H
#define CPP_WASTE_RECYCLING_BEKOR_DUSTBINTESTS_H

#include "Dustbin.h"
#include "Dustbin9000.h"

class DustbinTests {
public:
    void run(){
        std::cout << "Test Started ..." << std::endl;

        testCounter = 0;
        failedTests = 0;

        TestOneGarbage();
        TestSqueezedPaperGarbage();
        TestNonSqueezedPaperGarbage();
        TestCleanedPlasticGarbage();
        TestNonCleanedPlasticGarbage();
        TestMetalGarbage();
        TestBlueBottleCapGarbage();
        TestFullDustBin();
        TestEmptyingABin();
        TestEmptyingABin9000();

        evaluateTestOutcomes();
        std::cout << "Test Ended! " << std::endl;
    }

private:

    int testCounter;

    int failedTests;

    void TestOneGarbage(){
        std::string color = "red";
        Dustbin d(color, 5, 5, 5);
        d.throwOutGarbage(Garbage("simple"));
        checkResult(4, d.spaceLeftGarbage());
    }

    void TestSqueezedPaperGarbage() {
        std::string color = "red";
        Dustbin d(color, 10, 10, 10);
        size_t isException = 0;
        try {
            PaperGarbage p = PaperGarbage("simple");
            p.squeeze();
            d.throwOutPaperGarbage(p);
        } catch (DustbinContentError& e){
            isException = 1;
            std::cout << "Received exception: " << e.what() << std::endl;
        }
        checkResult(0, isException);
    }
    void TestNonSqueezedPaperGarbage() {
        std::string color = "white";
        Dustbin d(color, 10, 10, 10);
        size_t isException = 0;
        try {
            PaperGarbage p = PaperGarbage("big paper");
            d.throwOutPaperGarbage(p);
        } catch (DustbinContentError& e){
            isException = 1;
            std::cout << "Received exception: " << e.what() << std::endl;
        }
        checkResult(1, isException);
    }

    void TestCleanedPlasticGarbage() {
        std::string color = "blue";
        Dustbin d(color, 5);
        size_t isException = 0;
        try {
            PlasticGarbage p = PlasticGarbage("plastic simple");
            p.clean();
            d.throwOutPlasticGarbage(p);
        } catch (DustbinContentError& e){
            isException = 1;
            std::cout << "Received exception: " << e.what() << std::endl;
        }
        checkResult(0, isException);
    }

    void TestNonCleanedPlasticGarbage() {
        std::string color = "white";
        Dustbin d(color, 10, 10, 10);
        size_t isException = 0;
        try {
            PlasticGarbage p = PlasticGarbage("dirty plastic");
            d.throwOutPlasticGarbage(p);
        } catch (DustbinContentError& e){
            isException = 1;
            std::cout << "Received exception: " << e.what() << std::endl;
        }
        checkResult(1, isException);
    }

    void TestMetalGarbage() {
        std::string color = "white";
        Dustbin9000 d(color, 5, 5, 5, 5, 5);
        d.throwOutGarbage(Garbage("simple"));
        d.throwOutMetalGarbage(MetalGarbage("heavy metal"));
        checkResult(8, d.spaceLeftGarbage() + d.spaceLeftMetal());
    }

    void TestBlueBottleCapGarbage() {
        std::string color = "white";
        Dustbin9000 d(color, 1, 1, 1, 1, 5);
        size_t isException = 0;
        try {
            BottleCupGarbage b = BottleCupGarbage("cap", "blue");
            d.throwOutBottleCupGarbage(b);
        } catch (BottleCapException& e){
            isException = 1;
            std::cout << "Received exception: " << e.what() << std::endl;
        }
        checkResult(1, isException);
    }

    void TestFullDustBin() {
        std::string color = "white";
        Dustbin d(color, 5, 5, 5);
        size_t isException = 0;
        try {
            for(int i = 0; i <= 5; ++i){
                d.throwOutGarbage(Garbage("simple"));
            }
        } catch (DustbinContentError& e){
            isException = 1;
            std::cout << "Received exception: " << e.what() << std::endl;
        }
        checkResult(1, isException);
    }

    void TestEmptyingABin() {
        std::string color = "white";
        Dustbin d(color, 5, 5, 5);
        size_t isException = 0;
        try {
            for(int i = 0; i < 5; ++i){
                d.throwOutGarbage(Garbage("simple"));
            }
            d.emptyContents();
        } catch (DustbinContentError& e){
            isException = 1;
            std::cout << "Received exception: " << e.what() << std::endl;
        }
        if(isException){
            checkResult(0, 1);
        } else{
            checkResult(5, d.spaceLeftGarbage());
        }
    }

    void TestEmptyingABin9000() {
        std::string color = "white";
        Dustbin9000 d(color, 5, 5, 5);
        size_t isException = 0;
        try {
            for(int i = 0; i < 5; ++i){
                d.throwOutMetalGarbage(MetalGarbage("metal"));
                d.throwOutBottleCupGarbage(BottleCupGarbage("cup", "purple"));
            }
            d.emptyContents();
        } catch (DustbinContentError& e){
            isException = 1;
            std::cout << "Received exception: " << e.what() << std::endl;
        }
        if(isException){
            checkResult(0, 1);
        } else{
            checkResult(5, d.spaceLeftGarbage());
        }
    }

    void checkResult(const int expected, const size_t actual)
    {
        ++testCounter;
        if( actual == (size_t)expected )
        {
            std::cout << "Test ran OK." << std::endl;
        }else{
            std::cout << "Invalid result! Expected: " << expected << " actual: " << actual << std::endl;
            ++failedTests;
        }
    }

    void evaluateTestOutcomes()
    {
        std::cout << testCounter << " test started." << std::endl;
        if(0 != failedTests){
            std::cout << failedTests << " tests failed." << std::endl;
        }else{
            std::cout << "All tests passed!" << std::endl;
        }
    }
};


#endif //CPP_WASTE_RECYCLING_BEKOR_DUSTBINTESTS_H
