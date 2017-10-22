//
// Created by Joe Bekor on 19/10/2017.
//

#ifndef CPP_WASTE_RECYCLING_BEKOR_DUSTBINTESTS_H
#define CPP_WASTE_RECYCLING_BEKOR_DUSTBINTESTS_H

#include "Dustbin.h"
#include "Dustbin9000.h"

enum binType {GARBAGE, PAPER, PLASTIC, METAL };
class DustbinTests {
public:
    void run(){
        std::cout << "Test Started ..." << std::endl;
        failedTests = 0;
        TestOneGarbage();
        TestSqueezedPaperGarbage();
        TestNonSqueezedPaperGarbage();

        evaluateTestOutcomes();
        std::cout << "Test Ended! " << std::endl;
    }

private:

    int failedTests;

    void TestOneGarbage(){
        std::string color = "red";
        Dustbin d(binType::GARBAGE, color, 5);
        d.throwOutGarbage(Garbage("simple"));
        checkResult(4, d.spaceLeft());
    }

    void TestSqueezedPaperGarbage() {
        std::string color = "red";
        Dustbin d(binType::PAPER, color, 10);
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
        Dustbin d(binType::PAPER, color, 10);
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


    void checkResult(const int expected, const size_t actual)
    {
        if( actual >= (size_t)expected &&
            actual <= (size_t)expected  )
        {
            std::cout << "Test ran OK." << std::endl;
        }else{
            std::cout << "Invalid result! Expected: " << expected << " actual: " << actual << std::endl;
            ++failedTests;
        }
    }

    void evaluateTestOutcomes()
    {
        if(0 != failedTests){
            std::cout << failedTests << " tests failed." << std::endl;
        }else{
            std::cout << "All tests passed!" << std::endl;
        }
    }
};


#endif //CPP_WASTE_RECYCLING_BEKOR_DUSTBINTESTS_H
