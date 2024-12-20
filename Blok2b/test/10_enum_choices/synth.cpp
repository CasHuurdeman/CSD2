#include "synth.h"

Synth::Synth()
{
  // std::cout << "\nSynth::Synth" << std::endl;
}

Synth::~Synth()
{
  // std::cout << "\nSynth::~Synth" << std::endl;
}


void Synth::setSynthType(SynthType type)
{
  // std::cout << "\nSynth::setWaveform" << std::endl;

  std::cout << "\nUsing " << synthTypeToString(type) << " as synthType"
            << std::endl;
}


std::string Synth::synthTypeToString(SynthType type)
{
  switch(type) {
    case SynthType::OrganSynth:
      return "OrganSynth";
    case SynthType::AdditiveSynth:
      return "AdditiveSynth";
    default:
      return "Invalid synthType";
  }
}