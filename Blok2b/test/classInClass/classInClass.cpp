#include <iostream>

#include "speaker.h"



Tweeter::Tweeter() : Tweeter(2.5f){
    std::cout << "Tweeter - constructor\n";

};


Tweeter::Tweeter(float diam){
    std::cout << "Tweeter - overloaded constructor\n";

    diameter = diam;
    conePosition = 0.0f;
};



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

