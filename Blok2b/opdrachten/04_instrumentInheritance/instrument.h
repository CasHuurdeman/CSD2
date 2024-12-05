
class Instrument{
public:  
    //constructor
    Instrument();
    ~Instrument();

    //methods
protected:
    void setHighFreq(float f);
    void setLowFreq(float f);

public:
    float getLowFreq();
    float getHighFreq();

    void play();

private:
    //fields
    float lowFreq = 20.0;
    float highFreq = 20000.0;
};