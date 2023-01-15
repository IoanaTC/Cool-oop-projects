//
// Created by ioana on 14.05.2022.
//

#include "Owner.h"
#include "Pharmacy.h"
istream& operator>>(istream& in, Owner *owner){
    cout<<"\nNumele dumneavoastra = "; in>>owner->owner;
    return in;
}
ostream& operator<<(ostream& out, Owner *owner){
    system("cls");
    cout<<"\n"<<owner->owner<<", ";
    return out;
}
string Owner::GetOwner() const{
    return owner;
}

