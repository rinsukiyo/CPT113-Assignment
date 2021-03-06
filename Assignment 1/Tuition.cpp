//
// Created by rinsuki on 11/05/2022.
//

#include "Tuition.h"

void Tuition::setTuition(bool freshman, string maj, bool isInt) {
    major = maj;
    calcTuition(isInt);
 	calcExtraFee(freshman);
 }


// Set the tuition fee for international students and local students separately
void Tuition::calcTuition(bool i) { // Mutator
    short serialNum; // Serial Num of the majors

    // 1 - Computer Science, 2 - Dental, 3 - Mineral Resources Engineering, 4 - Management, 5 - TESOL
    double intlTuition[] = {0, 8230, 49100, 9800, 10050, 7500},
           localTuition[] = {0, 1030, 4500, 820, 900, 710};

    // Get the respective serial num of the major, since switch can't accept string as the parameter
    if (major == "CS") serialNum = 1; // Computer Science
    else if (major == "DEN") serialNum = 2; // Dental
    else if (major == "MRE") serialNum = 3; // Mineral Resources Engineering
    else if (major == "MNG") serialNum = 4; // Management
    else if (major == "TSL") serialNum = 5; // TESOL
    else serialNum = 0; // default

    // Set the tuition by the major (serial num)
    if (i) tuition = intlTuition[serialNum]; // For Intl Students
    else tuition = localTuition[serialNum]; // For Local Students

}

// Set the (non-)recurrent fee depending on whether the student is freshman
void Tuition::calcExtraFee(bool f) { // Mutator
    if (f) extraFee = nonRecurrentFee;
    else extraFee = recurrentFee;
}

// Calculate all the academic fee (including tuition fees, and (non-)recurrent fees)
void Tuition::setAcadFee(double &acad) const { // Mutator
    acad = tuition + extraFee;
}