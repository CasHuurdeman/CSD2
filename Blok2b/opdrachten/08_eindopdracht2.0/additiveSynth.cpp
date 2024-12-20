//
// Created by cashu on 15/12/2024.
//
#include "additiveSynth.h"


AdditiveSynth::AdditiveSynth() : Synth(){
}

AdditiveSynth::~AdditiveSynth(){
}

//devided by sines.size() for scaling, *6 to match loudness with organSynth
void AdditiveSynth::calculate(){
    sample = 0;
    for (int i = 0; i < sines.size(); i++) {
        sample += sines[i].getSample() /sines.size() *6;
    }
}

void AdditiveSynth::tick() {
    calculate();
    for (int i = 0; i < sines.size(); i++) {
        sines[i].tick();
    }
}


void AdditiveSynth::setFrequency(float frequency) {
    for (int i = 0; i < sines.size(); i++) {
        sines[i].setFrequency(frequency * (i+1));
    }
}

void AdditiveSynth::fillSines() {
    for (int i = 0; i < numOfHarmonics; i++) {
        sines.push_back(sine); ;
    }
}

void AdditiveSynth::setNumOfHarmonics(int numHarmonics) {
    numOfHarmonics = numHarmonics;
}