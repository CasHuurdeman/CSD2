//
// Created by Dean on 27/02/2024.
//
#pragma once


//                   IIRFilter
//   X[n] ---->(+)--->[ 1 sample ] ---> Y[n]
//              |                   |
//             (a)<-----------------
//
class IIRFilter {
    public:
    float process(float input) {
        // Y[n] = X[n] + aY[n-1]
        feedback = input + (a * feedback);
        std::cout << feedback << std::endl;
        return feedback;
    }

    void setCoefficient(float coefficient) {
        // Do not exceed 1, for the safety of all our ears
        a = coefficient;
    }

private:
    float feedback { 0.0 };
    float a { 0.0 }; // Coefficient "a" is mostly used for feedback lines

};


//                    OneZero
//   X[n] ---->(+)--------------------> Y[n]
//              |                  |
//             (b)-->[ 1 sample ]-->
//
class FIRFilter {
    public:
    float process(float input) {
        // Y[n] = X[n] - bX[n-1]
        float output = b*input - (b * x1);

        x1 = input; // Recaching Delay
        return output;
    }

    void setCoefficient(float coefficient) {
        b = coefficient;
    }

private:
    float x1 {0.0 }; // x1 for a single sample delay
    float b { 0.0 };  // Coefficient "b" is usually used for feed forward lines

};

// MET SCALING
//                   OnePole
//   X[n] --(b)->(+)--->[ 1 sample ] ---> Y[n]
//              |                   |
//             (a)<-----------------
//
class OnePole {
    public:
    float process(float input) {
        // Y[n] = bX[n] + aY[n-1]
        // You make this one:

        feedback = b * input + a * feedback;
        return feedback;
    }

    void setCoefficient(float coefficient) {
        a = coefficient;
        b = 1.0f - a;
    }

private:
    float feedback { 0.0 };
    float a { 0.0 };
    float b { 0.0 };
};


//                   4_Pole / Simple Cascade
//   X[n]--->[OnePole][OnePole][OnePole][OnePole]--->Y[n]
//
class SimpleLadder {
    public:
    SimpleLadder() {
        for (int i = 0; i < 4; i++) {
            OnePole onePole;
            array[i] = onePole;
            array[i].setCoefficient(0.9f);
        }
    }

    float process(float input) {
        for (int i = 0; i < 4; i++) {
            input = array[i].process(input);
        }
        feedback = input;
        return feedback;
    }

    void setCoefficient(float coefficient) {
        a = coefficient;
        b = 1.0f - a;
    }

private:
    float feedback { 0.0 };

    std::array<OnePole, 4> array;

    float b { 0.0 };
    float a { 0.0 };
};


//                   4 Sample
//   X[n] --(b)->(+)--->[ 4 sample ] ---> Y[n]
//              |                   |
//             (a)<-----------------
//

//TODO - dynamic allocation or queue insteead of vector
class FourSample {
    public:
    float process(float input) {
        // Y[n] = bX[n] + aY[n-4]

        //feedback = sample delayed by 4
        feedback = delay.at(3);
        delay.insert(delay.begin(), input);
        delay.pop_back();

        output = b * input + a* feedback;
        return output;
    }

    void setCoefficient(float coefficient) {
        a = coefficient;
        b = 1.0f - a;
    }


private:
    std::vector<float> delay {0.0, 0.0, 0.0, 0.0};
    float feedback { 0.0 };
    float output {0.0};
    float b { 0.0 };
    float a { 0.0 };
};


//                   Halve Biquad
//   X[n] --(b)->(+)--------------------> Y[n]
//                |                  |
//               (a1)<----------[ 1 sample ]
//                |                  |
//               (a2)<----------[ 1 sample ]
//
//
class HalfBiquad {
    public:
    float process(float input) {
      // y[n] = bX[n] - a1Y[n-1] - a2Y[n-2]

        //feedback = sample delayed by 4
        feedback1 = delay.at(0);
        feedback2 = delay.at(1);
        delay.insert(delay.begin(), input);
        delay.pop_back();

        output = b * input + a1 * feedback1 + a2 * feedback2;
        return output;


    }

    void setBCoefficient(float coefficient){
        b = coefficient;
    }

    void setA1Coefficient(float coefficient) {
        a1 = coefficient;
    }

    void setA2Coefficient(float coefficient) {
        a2 = coefficient;
    }


private:
    std::vector<float> delay {0.0, 0.0};
    float feedback1 {0.0};
    float feedback2 {0.0};
    float output {0.0};
    float b;
    float a1;
    float a2;
};


class Biquad {
public:
    // Zoek een Biquad, en maak  'm :- )
    // Probeer het internet, of Will Pirkle, zijn verschillende benaderingen
    // Succes.

};
