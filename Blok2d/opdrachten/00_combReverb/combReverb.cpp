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

    CF1 = CombFilter {DelayMath::msToSamples(16.0f, samplerate), 0.86f};
    CF2 = CombFilter {DelayMath::msToSamples(6.5f, samplerate), 0.86f};
    CF3 = CombFilter {DelayMath::msToSamples(3.0f, samplerate), 0.86f};
    CF4 = CombFilter {DelayMath::msToSamples(1.7f, samplerate), 0.86f};
}


double CombReverb::applyEffect(double input) {
    //CF --> CombFilter
    double cas1 = CF1.process(input);
    double cas2 = CF2.process(input);
    double cas3 = CF3.process(input);
    double cas4 = CF4.process(input);



    double output = cas1 +cas2
    + cas3 + cas4;


    return output;
}


