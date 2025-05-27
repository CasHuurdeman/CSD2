//
// Created by cashu on 13/05/2025.
//

#include <iostream>
#include "combReverb.h"
#include "delayMath.h"

CombReverb::CombReverb() {
    std::cout << "CombReverb - constructor" << std::endl;

}

CombReverb::~CombReverb() {
    std::cout << "CombReverb - destructor" << std::endl;
}

void CombReverb::prepare(unsigned int samplerate) {
    this->samplerate = samplerate;

    //TODO (later) - D and g should be computed, set but not be saved in this class
    // now using static D values from Pirkle (p466)

    std::cout << DelayMath::msToSamples(16.0f, samplerate) << std::endl;
    std::cout << DelayMath::msToSamples(6.5f, samplerate) << std::endl;
    std::cout << DelayMath::msToSamples(3.0f, samplerate) << std::endl;
    std::cout << DelayMath::msToSamples(1.7f, samplerate) << std::endl;

    // CF1 = CombFilter {DelayMath::msToSamples(16.0f, samplerate), 0.86f};
    // CF2 = CombFilter {DelayMath::msToSamples(6.5f, samplerate), 0.86f};
    // CF3 = CombFilter {DelayMath::msToSamples(3.0f, samplerate), 0.86f};
    // CF4 = CombFilter {DelayMath::msToSamples(1.7f, samplerate), 0.86f};

    CF1 = CombFilter(1,0.86f);
    CF2 = CombFilter(2,0.86f);
    CF3 = CombFilter(3,0.86f);
    CF4 = CombFilter(4,0.86f);
}


double CombReverb::applyEffect(double input) {

    //CF --> CombFilter
    double output = CF1.process(input) + CF2.process(input)
    + CF3.process(input) + CF4.process(input);

    return output;
}


