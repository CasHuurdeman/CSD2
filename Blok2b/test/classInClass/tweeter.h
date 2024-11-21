
class Tweeter{
public:
    // constructor
    Tweeter();
    //constructor delegation
    Tweeter(float diameter) : Tweeter(){};

    
    // fields
    float diameter;
    float conePosition;
};

//constructor delegation + giving 'arguments' to classes
