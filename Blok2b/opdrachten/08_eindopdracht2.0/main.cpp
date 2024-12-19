// #include "audioToFile.h"
#include "callback.h"
#include <iostream>
#include <thread>
#include "additiveSynth.h"



int main (int argc, char** argv) {
  std::cout << "UI..." << std::endl;
  AdditiveSynth additiveSynth;
  additiveSynth.printArray();

  ScopedMessageThreadEnabler scopedMessageThreadEnabler;
  CustomCallback audioSource (44100);


  JUCEModule juceModule (audioSource);
  juceModule.init (2, 2);
  std::cout << "Hello" << std::endl;

  std::cout << "Press q + Enter to quit..." << std::endl;
  bool running = true;
  while (running) {
    switch (std::cin.get()) {
      case 'q':
        running = false;
    }
  }
  //end the program
  return 0;
}  // main()
