
#include "oscillator.h"

int main(){

    std::cout << "\nin main\n";
    Oscillator osc;

    // osc.setFreq(440);
    std::cout << "freq: " << osc.getFreq() << std::endl;
    std::cout << "amp: " << osc.getAmp() << std::endl;

  // end program
  return 0;
}