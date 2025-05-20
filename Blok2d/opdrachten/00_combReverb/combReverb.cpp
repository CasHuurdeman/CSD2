//
// Created by cashu on 13/05/2025.
//

#include <iostream>
#include "combReverb.h"

CombReverb::CombReverb(float DelayTime) {
    std::cout << "CombReverb - constructor" << std::endl;

}

CombReverb::~CombReverb() {
    std::cout << "CombReverb - destructor" << std::endl;
}

double CombReverb::applyEffect(double input) {

    //CF --> CombFilter
    double output = CF1.process(input) + CF2.process(input)
    + CF3.process(input) + CF4.process(input);

    return output;
}

void CombReverb::change_g(float &gCurrent, float gNew) {
    gCurrent = gNew;
}

