//
// Created by rinsuki on 11/05/2022.
//

#ifndef CPT113_ASSIGNMENT_INTL_H
#define CPT113_ASSIGNMENT_INTL_H

#include <iostream>

class Intl {
private:
    float visaFee = 1200.0;

    double quarantineFee = 0,
           quarantineFeePerDay = 150.0;

    const int quarantineDays = 5;

public:
    // Default Constructor
    Intl() = default;
    
    //pass value through this member function from derived class student and calculate quaratine fee 
    void setIntl(bool, bool);

    // Prototype
    void calcQuarantineFee(bool, bool); // Mutator
    void calcTotalIntl(double &) const; // Mutator

};


#endif //CPT113_ASSIGNMENT_INTL_H
