//
// Created by cashu on 11/02/2025.
//

#ifndef INTERPOLATION_H
#define INTERPOLATION_H

class Interpolation {
  public:

    static float nnMap(float value, float low, float high);
    static float linMap(float value, float low, float high);
    static float mapInRange(float value, float fromLow, float fromHigh,
                     float toLow, float toHigh);



};

#endif //INTERPOLATION_H
