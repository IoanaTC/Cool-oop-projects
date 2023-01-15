//
// Created by ioana on 14.05.2022.
//

#ifndef OOP_PROJECT3_PHARMACY_H
#define OOP_PROJECT3_PHARMACY_H
#include "Owner.h"

class Pharmacy : public Owner {
protected:
    tuple<string, int, double> pharmacydata;
public:
    explicit Pharmacy(string owner);
    Pharmacy()=default;
    //explicit=> prevents the constructor from implicitly converting a given parameter when called
    Pharmacy(Pharmacy &pharmacy) = default;
    ~Pharmacy()=default;

    void AskForPharmacyData() override;
    void PrintPharmacyData() override;
    //keyword override => ensures the compilator that this function exists in the base class

    Pharmacy &operator=(Pharmacy pharmacy);

    tuple<string, int, double> GetTuple();
};


#endif //OOP_PROJECT3_PHARMACY_H