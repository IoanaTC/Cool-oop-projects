//
// Created by ioana on 14.05.2022.
//

#ifndef OOP_PROJECT3_ONLINEPHARMACY_H
#define OOP_PROJECT3_ONLINEPHARMACY_H
#include "Owner.h"

class OnlinePharmacy : public Owner {
protected:
    tuple<string, int, double> pharmacydata;
public:
    explicit OnlinePharmacy(string owner = "null");
    //explicit=> prevents the constructor from implicitly converting a given parameter when called
    OnlinePharmacy(OnlinePharmacy &onlinepharmacy) = default;
    ~OnlinePharmacy() = default;

    void AskForPharmacyData() override;
    void PrintPharmacyData() override;
    //keyword override => ensures the compilator that this function exists in the base class

    OnlinePharmacy& operator=(OnlinePharmacy pharmacy);

    tuple<string, int, double> GetTuple();
};

#endif //OOP_PROJECT3_ONLINEPHARMACY_H