//
// Created by ioana on 14.05.2022.
//

#ifndef OOP_PROJECT3_PHARMACYMANAGEMENT_H
#define OOP_PROJECT3_PHARMACYMANAGEMENT_H

#include "Pharmacy.h"
#include "OnlinePharmacy.h"

#include<vector>
#include <tuple>
#include<typeinfo>
#include <stdexcept>

template <class T> class PharmacyManagement {
protected:
    const int id = IdGenerator(identification); //identification name for chain
    int index; //index calculates how many pharmacies in a chain
    vector <T*> chain;

    static int identification;
public:
    PharmacyManagement()=default;
    PharmacyManagement(PharmacyManagement &pharmacyManagement)=default;
    ~PharmacyManagement()=default;

    int GetId() const;
    static int IdGenerator(int &ID); //id generator for pharmacy chains

    void EraseLastPharmacy();

    void Visitors() ;
    void PrintChain();

    void operator+=(T *pharmacy);
};
template<class T>
int PharmacyManagement<T>::identification=0;

template<class T>
int PharmacyManagement<T>::IdGenerator(int &ID) {
    PharmacyManagement<T>::identification+=1;
    return PharmacyManagement<T>::identification;
}

template<class T>
void PharmacyManagement<T>::operator+=(T *pharmacy) {
    cout<<"\nSe adauga o noua farmacie...";
    chain.push_back(pharmacy);
    index+=1;
}
template<class T>
void PharmacyManagement<T>::PrintChain() {
    try{
        if(typeid(*this).name() != typeid(PharmacyManagement<OnlinePharmacy>).name())
            throw logic_error("Error");
        cout<<"\n\nDetalii despre farmaciile online:\n";

        if(chain.size())
            for(int i=0; i<chain.size(); i++)
                chain[i]->PrintPharmacyData(), cout<<endl;
        else cout<<"Nu exista farmacii online inregistrate";

    }catch (logic_error ex) {
        cout << "\n\nDetalii despre farmaciile fizice:\n";

        if(chain.size())
            for (int i = 0; i < chain.size(); i++)
                chain[i]->PrintPharmacyData(), cout<<endl;
        else cout<<"Nu exista farmacii inregistrate";
    }
}
template<class T>
int PharmacyManagement<T>::GetId() const {
    return id;
}
template<class T>
void PharmacyManagement<T>::EraseLastPharmacy(){
    if(!chain.empty())
    {
        cout<<"\nSe sterge ultima farmacie...";
        chain.pop_back();
        index-=1;
    }
    else cout<<"\nNu mai exista nicio farmacie stocata";
}
template<class T>
void PharmacyManagement<T>::Visitors() {
    cout<<"\n\nFarmaciile au un total de ";
    int visitors=0;
    for(int i=0; i<index; i++)
        visitors+=get<1>(chain[i]->GetTuple());
    cout<<visitors<<" vizitatori";
}
template<>
void PharmacyManagement<OnlinePharmacy>::Visitors() {
    cout<<"\n\nFarmaciile online au un total de ";
    int visitors=0;
    for(int i=0; i<index; i++)
        visitors+=get<1>(chain[i]->GetTuple());
    cout<<visitors<<" vizitatori";
}
template class PharmacyManagement<Pharmacy>;
template class PharmacyManagement<OnlinePharmacy>;

#endif //OOP_PROJECT3_PHARMACYMANAGEMENT_H
