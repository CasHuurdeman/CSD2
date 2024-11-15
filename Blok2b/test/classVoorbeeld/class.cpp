#include <iostream>

/*
class
1. define the class
2. define the constructor
3. implement the comstructor
4. add fields / methods (and define the methods)

*/



class Note {
public:
    // default constructor
    Note(); //same name as a class name

    // methods (a method is a function & a member of a class)
    void play(); //function  without return
    int getVelocity(); //function with int return

    // fields (a field is a member of a class)
    int midiNoteValue;
    int velocity;
};

Note::Note(){
    std::cout << "Note - constructor\n";
    midiNoteValue = 60;
    velocity = 127;
}

int Note::getVelocity() {
    return velocity;
}

int main() {
    // std::cout << "TEST\n"; //std::endl

    Note aNote;
    std::cout << "aNote contains: \n" 
    << aNote.midiNoteValue << "\n"
    << aNote.velocity << "\n";

    aNote.getVelocity();
};