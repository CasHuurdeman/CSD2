#include <iostream>


class Tweeter{
public:
    // constructor
    Tweeter();
    // overloaded constructor
    Tweeter(float diam); //in cm
    
    // fields
    float diameter;
    float conePosition;
};

Tweeter::Tweeter(){
    std::cout << "Tweeter - default constructor\n";

    diameter = 2.5f;
    conePosition = 0.0f;
};


Tweeter::Tweeter(float diam){
    std::cout << "Tweeter - constructor with float diam parameter\n";
    diameter = diam;
    conePosition = 0.0f; // f --> float
};


class Woofer{
public:
    //constructor
    Woofer();

    //Method

    //fields
    float diameter;
    float conePosition;
};

Woofer::Woofer(){
    std::cout << "Woofer - constructor\n";
    diameter = 25.0f;
    conePosition = 0.0f;
};


class Speaker{
public:
    Speaker();
    Tweeter aTweeter;
    Woofer aWoofer;
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
};
