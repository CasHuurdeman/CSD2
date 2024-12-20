#pragma once

#include <iostream>




class Synth
{
public:
  Synth();
  ~Synth();

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

protected:

};
