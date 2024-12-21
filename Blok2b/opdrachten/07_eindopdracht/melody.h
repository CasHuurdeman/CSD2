#pragma once

#include <iostream>

#define NUM_NOTES 19
#define NUM_NOTES1 10

class Melody
{
public:
  Melody();
  ~Melody();

  // setters and getters
  float getNote();

protected:

  void setMelody();

  // Dissonance
  float melody[NUM_NOTES] = {71.5,71.5, 67, 63, 69, 62, 58, 54, 60, 67, 70, 67, 63, 72, 54, 73, 58, 69, 73};

  // Cmaj7 -  arpeggio
  float melody1[NUM_NOTES1] = {60, 64, 67, 71, 64, 67, 64, 69, 60, 55};

  // the index of the current note - readIndex
  int index = 0;
};
