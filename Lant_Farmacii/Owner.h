//
// Created by ioana on 14.05.2022.
//

#ifndef OOP_PROJECT3_OWNER_H
#define OOP_PROJECT3_OWNER_H

#include<iostream>
#include<tuple>
using namespace std;

class Owner {
protected:
    string owner;
public:
    explicit Owner(string owner = "null"): owner(move(owner)){}
    // std::move: doesn't copy name's value, instead it efficiently moves it directly into its place (t=move's param)

    Owner(Owner &owner) = default;
    virtual ~Owner()= default;

    friend istream& operator>>(istream &in, Owner *owner);
    friend ostream& operator<<(ostream& out, Owner *owner);

    virtual void AskForPharmacyData() = 0;
    virtual void PrintPharmacyData() = 0;

    string GetOwner() const;

};
#endif //OOP_PROJECT3_OWNER_H
