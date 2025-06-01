//
// Created by cashu on 13/05/2025.
//

#include <iostream>
#include "schroedersReverb.h"
#include "delayMath.h"

SchroedersReverb::SchroedersReverb() {
    std::cout << "SchroedersReverb - constructor" << std::endl;

}

SchroedersReverb::~SchroedersReverb() {
    std::cout << "SchroedersReverb - destructor" << std::endl;
}

void SchroedersReverb::prepare(unsigned int samplerate) {
    this->samplerate = samplerate;

    //TODO (later) - D and g should be computed, set but not be saved in this class
    // now using static D values from Pirkle (p466)

    CF1 = new CombFilter {DelayMath::msToSamples(16.0f, samplerate), 0.86f};
    CF2 = new CombFilter {DelayMath::msToSamples(6.5f, samplerate), 0.86f};
    CF3 = new CombFilter {DelayMath::msToSamples(3.0f, samplerate), 0.86f};
    CF4 = new CombFilter {DelayMath::msToSamples(1.7f, samplerate), 0.86f};

    //TODO - need new values
    APF1 = new APF{1, 0.5f};
    APF2 = new APF{2, 0.5f};
}


double SchroedersReverb::applyEffect(double input) {
    //CF --> CombFilter

    double output = CF1->process(input) + CF2->process(input)
    + CF3->process(input) + CF4->process(input);

    //for more APF you can do this with a for loop and an array
    output = APF1->process(output);
    output = APF2->process(output);

    return output;
}


