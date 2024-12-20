//
// Created by Ciska Vriezenga on 06/12/2022.
//

#include "sine.h"
#include "math.h"

Sine::Sine (float frequency, float samplerate) : Oscillator (frequency, samplerate) {}

void Sine::calculate() { sample = sin (pi * 2 * phase) * amplitude; }