#include <iostream>

class Instrument {
public:
    // Constructor
    Instrument();

    // Methods
    void play();

    // Fields

};

Instrument::Instrument(){
    std::cout << "Note - constructor\n";

};


void Instrument::play(){
    std::cout << "fweeeeeeeeeeeeep" << std::endl;
};


int main(){
    Instrument anInstrument;
    anInstrument.play();
};