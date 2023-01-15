//
// Created by ioana on 14.05.2022.
//

#include "Pharmacy.h"
//constructor
Pharmacy::Pharmacy(string owner){
    if(owner == "null"){
        cin>>&(*this); //modifies actual_client; operator overload
    }
    else this->owner=owner;
    pharmacydata = make_tuple("null", 0, 0);
}
//read and print
void Pharmacy::AskForPharmacyData() {
    cout<<"\nDenumirea farmaciei = "; cin>>get<0>(pharmacydata);
    cout<<"Numarul de angajati = "; cin>>get<1>(pharmacydata);
    cout<<"Valoarea profitului = "; cin>>get<2>(pharmacydata);
}
void Pharmacy::PrintPharmacyData() {
    cout<<"\n"<<this->owner<<", datele farmaciei dumneavoastra sunt urmatoarele:";
    cout<<"\nDenumire = "<<get<0>(pharmacydata);
    cout<<"\nNumarul de angajati = "<<get<1>(pharmacydata);
    cout<<"\nValoarea profitului = "<<get<2>(pharmacydata);
}
Pharmacy& Pharmacy::operator=(Pharmacy pharmacy){
    cout<<"\nSe aplica modificarile...";
    get<0>(this->pharmacydata) = get<0>(pharmacy.pharmacydata);
    get<1>(this->pharmacydata) = get<1>(pharmacy.pharmacydata);
    get<2>(this->pharmacydata) = get<2>(pharmacy.pharmacydata);
    return *this;
}
tuple<string, int, double>Pharmacy::GetTuple() {
    return pharmacydata;
}