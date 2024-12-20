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


    float mtof(float midiPitch);
    void updatePitch(Melody& melody, Synth& synth);

    float getSample();
    virtual void tick() = 0;
    virtual void setFrequency(float freq) = 0;
    virtual void setNumOfHarmonics(int numHarmonics) = 0;

    virtual void fillSines() = 0;

    // NOTE: needs to be same order as the synthTypeOptions string array
    enum SynthType {
        OrganSynth = 0,
        AdditiveSynth,
        Size //2
      };
    void setSynthType(SynthType type);

    // static method because this method does not depend on objects
    static std::string synthTypeToString(SynthType type);

protected:
    virtual void calculate() = 0;

    float sample;
    float amplitude;
    int midiNote;
};

#endif //SYNTH_H
