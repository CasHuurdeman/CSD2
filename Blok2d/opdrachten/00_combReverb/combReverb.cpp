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

    CF1 = new CombFilter {DelayMath::msToSamples(16.0f, samplerate), 0.86f};
    CF2 = new CombFilter {DelayMath::msToSamples(6.5f, samplerate), 0.86f};
    CF3 = new CombFilter {DelayMath::msToSamples(3.0f, samplerate), 0.86f};
    CF4 = new CombFilter {DelayMath::msToSamples(1.7f, samplerate), 0.86f};
}


double CombReverb::applyEffect(double input) {
    //CF --> CombFilter

    double output = CF1->process(input) + CF2->process(input)
   + CF3->process(input) + CF4->process(input);

    return output;
}


