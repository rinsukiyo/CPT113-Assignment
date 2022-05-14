/*composition of studnet class

*/

#ifndef CPT113_ASSIGNMENT_DESA_H
#define CPT113_ASSIGNMENT_DESA_H


#include <iostream>

using namespace std;

class Desa {

private:
    short month = 0;

    float desaFee = 0,
          insuranceFee = 0,
          parkingFee = 0, // to be used in other classes
          monthlyParkingCard = 500; // No longer be afraid of cars being locked
  

public:
    // Default Constructor
    Desa() {};
    
    // Pass values through this member function from derived class and calculate desa fee, insurance fee and parking fee
    void setDesa(short, short, short);
                       

    // Prototype
    float calcDesaFee(short);
    float calcInsurance(short);
    float calcParking(short);
    void calcBasicCost(double &); // Mutator
};


#endif //CPT113_ASSIGNMENT_DESA_H


