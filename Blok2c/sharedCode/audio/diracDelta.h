//
// Created by cashu on 13/03/2025.
//

#pragma once


class DiracDelta
{
public:
    //Constructor and destructor
    DiracDelta(){
    count = 0;
    };
    ~DiracDelta(){};

    float givePulse(){
        if(count == 0){
            count++;
          return 1.0f;}
        else{count++;}
      };

private:
    int count;
    // calculate the next sample according to square calculation
};