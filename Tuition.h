//
// Created by rinsuki on 11/05/2022.
//

#ifndef CPT113_ASSIGNMENT_TUITION_H
#define CPT113_ASSIGNMENT_TUITION_H

#include "Student.h"
#include "Output.h"
#include <iostream>

using namespace std;

class Tuition {
private:
    Student s;

protected:
    double tuition = 0,
           recurrentFee = 112.50,
           nonRecurrentFee = 1330.00,
           extraFee = 0;


public:
    // Default Constructor
    Tuition() {
        cout << "Tuition: " << calcTuition(s.checkInt()) << "\n"
             << "Extra Fee: (non-)recurrent fee: " << calcExtraFee(s.checkFreshman()) << endl;

    }

    // Prototype
    double calcTuition(bool);
    double calcExtraFee(bool);
    void calcNecCost(Output&); // a friend function of class Tuition

    // Inline Function
//    double getTuition() const {return tuition;}
//    double getExtraFee() const {return extraFee;}




};


#endif //CPT113_ASSIGNMENT_TUITION_H