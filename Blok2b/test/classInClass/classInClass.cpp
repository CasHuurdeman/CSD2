#include <iostream>

#include "speaker.h"



Tweeter::Tweeter(){
    std::cout << "Tweeter - constructor\n";

    diameter;
    conePosition = 0.0f;
};


// Tweeter::Tweeter(float diam){
//     std::cout << "Tweeter - constructor with float diam parameter\n";
//     diameter = diam;
//     conePosition = 0.0f; // f --> float
// };



Woofer::Woofer(){
    std::cout << "Woofer - constructor\n";
    diameter = 25.0f;
    conePosition = 0.0f;
};


Speaker::Speaker(){
    std::cout << "Speaker - constructor\n";
    std::cout << "The diameter of the tweeter is: "
        << aTweeter.diameter << "\n";

    std::cout << "The diameter of the woofer is: "
    << aWoofer.diameter << "\n";
};


int main(){
    Speaker aSpeaker;
}

