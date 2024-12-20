#include <iostream>
#include "uiUtilities.h"
#include "synth.h"

int main()
{

  // create a string array with the synth type options
  std::string* synthTypeOptions = new std::string[Synth::SynthType::Size];
  for(int i = 0; i < Synth::SynthType::Size; i++) {
    synthTypeOptions[i] = Synth::synthTypeToString((Synth::SynthType)i);
  }

  // retrieve the user selection in form of an enum
  Synth::SynthType synthType = (Synth::SynthType)
    UIUtilities::retrieveSelectionIndex(synthTypeOptions, Synth::SynthType::Size);

  //Retrieve number of
  if (synthType == 1) {
    std::cout << "\nSelect number of harmonics, " << std::endl;
    float value =  UIUtilities::retrieveValueInRange(1, 50);

  }

  Synth synth;

  // use synth of user's choice
  synth.setSynthType(synthType);
}