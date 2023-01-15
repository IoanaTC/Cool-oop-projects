//
// Created by ioana on 14.05.2022.
//

#include "OnlinePharmacy.h"
OnlinePharmacy::OnlinePharmacy(const string owner) {
    if(owner == "null"){
        cin>>&(*this); //modifies actual_client; operator overload
    }
    else this->owner=owner;
    pharmacydata = make_tuple("null", 0, 0);
}
void OnlinePharmacy::AskForPharmacyData() {
    cout<<"\nURL = "; cin>>get<0>(pharmacydata);
    cout<<"Numarul de vizitatori = "; cin>>get<1>(pharmacydata);
    cout<<"Valoarea discountului = "; cin>>get<2>(pharmacydata);
}
void OnlinePharmacy::PrintPharmacyData() {
    cout<<&(*this)<<"datele farmaciei dumneavoastra online sunt urmatoarele:";
    cout<<"\nURL = "<<get<0>(pharmacydata);
    cout<<"\nNumarul de vizitatori = "<<get<1>(pharmacydata);
    cout<<"\nValoarea discountului = "<<get<2>(pharmacydata);
}
OnlinePharmacy& OnlinePharmacy::operator=(OnlinePharmacy pharmacy){
    cout<<"\nSe aplica modificarile...";
    this->pharmacydata = pharmacy.GetTuple();
    return *this;
}
tuple<string, int, double> OnlinePharmacy::GetTuple() {
    return pharmacydata;
}