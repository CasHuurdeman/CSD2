//
// Created by cashu on 05/12/2024.
//

#include <iostream>
#include "melody.h"

#ifndef SYNTH_H
#define SYNTH_H

class Synth{
public:
    //constructors
    Synth();
    virtual ~Synth();

    //methods

    float mtof(float midiPitch);
    void updatePitch(Melody& melody, Synth& synth);

    float getSample();
    virtual void tick() = 0;
    virtual void calculate() = 0;
    virtual void setFrequency(float freq) = 0;
    virtual void setNumOfHarmonics(int numHarmonics) = 0;

    //fields
    float sample;
    float amplitude;
    int midiNote;
    virtual void fillSines() = 0;

    // NOTE: needs to be same order as the synthTypeOptions string array
    enum SynthType {
        OrganSynth = 0, // ensure enum starts at 0
        AdditiveSynth,
        Size // 2
      };
    // setters and getters
    void setSynthType(SynthType type);

    // static method because this method does not depend on objects
    static std::string synthTypeToString(SynthType type);
};

#endif //SYNTH_H
