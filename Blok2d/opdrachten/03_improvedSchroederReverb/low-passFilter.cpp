//
// Created by cashu on 31/05/2025.
//

#include "low-passFilter.h"
#include <iostream>

//TODO - is dit hoe ik mijn filter base class initialiseer?
LPF::LPF(float D, float g): Filter(D, g){
    std::cout << "LPF - constructor" << std::endl;
}

LPF::~LPF() {
    std::cout << "LPF - destructor" << std::endl;
}

double LPF::process(double input) {
    x->write(input);

    //TODO - maybe just without buffer
//FIXME - this is a combfilter too!
    double output = input + g*y->read();

    y->write(output);

    return output;
}