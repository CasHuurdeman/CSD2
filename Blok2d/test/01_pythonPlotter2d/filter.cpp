//
// Created by cashu on 29/05/2025.
//

#include "filter.h"
#include <iostream>

Filter::Filter(float D, float g){

    this->D = D;
    this->g = g;

    std::cout << "Filter - constructor \n D: " << this->D << std::endl;

    //TODO - is +1 nodig?
    //Using ceil() because input has to be an int and >= D
    //+1 for a case of float errors (just to be sure)
    x = new CircularBuffer{static_cast<unsigned int>(ceil(D)) + 1, D};
    y = new CircularBuffer{static_cast<unsigned int>(ceil(D)) + 1, D};

}

Filter::~Filter(){
    std::cout << "Filter - destructor" << std::endl;
}

void Filter::setD(float D) {
    this->D = D;

    //+1 for a case of float errors (just to be sure)
    x->setBufferSize(static_cast<int>(ceil(D)) + 1);
    y->setBufferSize(static_cast<int>(ceil(D)) + 1);

    x->setNumSamplesDelay(D);
    y->setNumSamplesDelay(D);

}

float Filter::getD(){return D;}

void Filter::set_g(float g) {
    this->g = g;
}

float Filter::get_g(){return g;}