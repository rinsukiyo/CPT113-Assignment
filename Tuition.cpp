//
// Created by rinsuki on 11/05/2022.
//

#include "Tuition.h"

// Set the tuition fee for international students and local students separately
void Tuition::calcTuition(string maj, bool i) { // Mutator
    short serialNum = 0;

    // 1 - Computer Science, 2 - Dental, 3 - Mineral Resources Engineering, 4 - Management, 5 - TESOL
    double intlTuition[] = {0, 8230, 49100, 9800, 10050, 7500},
           localTuition[] = {0, 1030, 4500, 820, 900, 710};

    // Get the respective serial num of the major, since switch can't accept string as the parameter
    if (maj == "CS") serialNum = 1; // Computer Science
    else if (maj == "DEN") serialNum = 2; // Dental
    else if (maj == "MRE") serialNum = 3; // Mineral Resources Engineering
    else if (maj == "MNG") serialNum = 4; // Management
    else if (maj == "TSL") serialNum = 5; // TESOL
    else serialNum = 0;

    // Set the tuition by the major (serial num)
    if (i) tuition = intlTuition[serialNum];
    else tuition = localTuition[serialNum];

}

// Set the (non-)recurrent fee depending on whether the student is freshman
void Tuition::calcExtraFee(bool f) { // Mutator
    if (f) extraFee = nonRecurrentFee;
    else extraFee = recurrentFee;

}

void Tuition::displayTuition() {
    cout << "Tuition: " << tuition << endl; // Mutator
    if (s.checkFreshman()) cout << "Non-recurrent Fees: " << nonRecurrentFee << endl;
    else cout << "Recurrent Fees: " << recurrentFee << endl;

}

// Calculate all the academic fee (including tuition fees, and (non-)recurrent fees)
void Tuition::setAcadFee(double &acad){ // Mutator
    // Execute calcExtraFee first, then variable tuition and variable extraFee can save correct value.
    // After that, what we need to do next is adding them together, and return the academic fee (acadFee).
    acad = tuition + extraFee;

 }