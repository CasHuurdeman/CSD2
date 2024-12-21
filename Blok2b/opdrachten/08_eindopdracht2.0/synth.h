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
    float getAmplitude();

    virtual void setFrequency(float freq) = 0;
    virtual void setNumOfHarmonics(int numHarmonics) = 0;

    virtual void tick() = 0;

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


    //I didn't use a getter for amplitude and noteDelayFactor because I got an
    //error that I didn't understand and it's very late:) (so now it's public)
    float amplitude = 0.25;


/* instead of using bpm and specifying note lenghts we'll make every note
 * equal length and specify the delay between notes in terms of the samplerate
 *
 * A note of say 500 msec or 0.5 sec, takes 0.5*samplerate samples to be played
 */
    float noteDelayFactor = 0.13;

protected:
    virtual void calculate() = 0;

    float sample;
    int midiNote;
};

#endif //SYNTH_H
