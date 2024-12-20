#pragma once

#include <iostream>

#define NUM_NOTES2 10
#define NUM_NOTES 16

class Melody
{
public:
  Melody();
  ~Melody();

  // setters and getters
  float getNote();

protected:
  // Cmaj7 -  arpeggio
  float melody2[NUM_NOTES2] = {60, 64, 67, 71, 64, 67, 64, 69, 60, 55};

  //Not jingle bells
  float melody[NUM_NOTES] = {60, 60, 60, 52, 60, 60, 60, 52, 60, 64, 56, 58, 60, 60, 60, 52};
  // the index of the current note - readIndex
  int index = 0;
};
