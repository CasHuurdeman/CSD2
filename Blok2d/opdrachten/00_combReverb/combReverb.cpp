//
// Created by cashu on 13/05/2025.
//

#include <iostream>
#include "combReverb.h"

CombReverb::CombReverb(float DelayTime) {
    //TODO - D and g shouldn't be in this class, but only in combFilter
    std::cout << "CombReverb - constructor" << std::endl;

}

void CombReverb::prepare(unsigned int samplerate) {
    this->samplerate = samplerate;

    //TODO - D and g should be computed, set but not be saved in this class
    CF1 = CombFilter {D[0], g[0]};
    CF2 = CombFilter {D[1], g[1]};
    CF3 = CombFilter {D[2], g[2]};
    CF4 = CombFilter {D[3], g[3]};
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

