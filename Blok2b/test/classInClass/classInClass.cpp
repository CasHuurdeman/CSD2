#include <iostream>

class Speaker (

);


class Tweeter(
public:
    // constructor
    Tweeter();
    Tweeter(float diam); //in cm

    float diameter;
    float conePosition;
);

Tweeter::Tweeter(float diam){
    std::cout << "Tweeter - constructor\n";
    diameter = diam;
    conePosition = 0.0f; // f --> float
}

// Tweeter::Tweeter

class Speaker(
public:
    Speaker();
    Tweeter a Tweeter;
)

Speaker::Speaker(){
    std::cout << "Speaker - constructor\n";
    std::cout << "The diameter of the tweeter is: "
        << aTweeter.diameter << "\n";
}

//TODO - add woofer

int main(){
    Tweeter aTweeter(2.4);
};
