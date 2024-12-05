
#include <iostream>

#include "instrument.h" //moet hier ook!

int main(){

    Instrument anInstrument;
    std::cout << "Highest Freq: " 
        << anInstrument.getHighFreq() << std::endl;

};