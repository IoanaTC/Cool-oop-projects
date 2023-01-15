//
// Created by ioana on 14.05.2022.
//
#include <cstdlib>
#include "PharmacyManagement.h"

bool client, online;
int ok;

int PrintAlegere();
bool Finish();
int main()
{
    //test operator=
//    Pharmacy pharmacy("null"); pharmacy.AskForPharmacyData();
//    Pharmacy pharmacy1("null"); pharmacy1.AskForPharmacyData();
//
//    pharmacy.PrintPharmacyData();
//    pharmacy=pharmacy1;
//    pharmacy.PrintPharmacyData();

    system("cls");
    cout << "Buna ziua!\nVa voi ajuta sa manipulati baza dumneavoastra de informatii in legatura cu farmaciile detinute\n";
    do {
        online=0;
        PharmacyManagement<Pharmacy> chain;
        PharmacyManagement<OnlinePharmacy> chain_online;

        Owner *owner = new Pharmacy("null");
        owner->AskForPharmacyData();
        chain+=(dynamic_cast<Pharmacy*>(owner));

        system("cls");
        do{
            ok=PrintAlegere();
            system("cls");
            switch(ok){
                case 1:{
                    cout<<"Ati ales optiunea: -Adaugarea unei farmacii-";
                    do{
                        owner = new Pharmacy(owner->GetOwner());
                        owner->AskForPharmacyData();
                        chain+=(dynamic_cast<Pharmacy*>(owner));

                    }while(Finish());
                    system("cls");
                    chain.PrintChain();
                    break;
                }
                case 2:{
                    cout<<"Ati ales optiunea: -Adaugarea unei farmacii online-";
                    online=1;

                    do{
                        owner = new OnlinePharmacy(owner->GetOwner());
                        owner->AskForPharmacyData();
                        chain_online+=(dynamic_cast<OnlinePharmacy*>(owner));

                    }while(Finish());
                    system("cls");
                    chain_online.PrintChain();
                    break;
                }
                case 3:{
                    cout<<"Ati ales optiunea: -Afisare a farmaciilor inregistrate pana acum-";
                    chain.PrintChain();
                    break;
                }
                case 4:{
                    cout<<"Ati ales optiunea: -Afisare a farmaciilor online inregistrate pana acum-";
                    chain_online.PrintChain();
                    break;
                }
                case 5:{
                    cout<<"Ati ales optiunea: -Afisare numar clienti farmacii-";
                    chain.Visitors();
                    break;
                }
                case 6:{
                    if(online){
                        cout<<"Ati ales optiunea: -Afisare numar clienti farmacii online-";
                        chain_online.Visitors();
                    }
                    else cout<<"Nu exista farmacii online inregistrate";
                    break;
                }
                case 7:{
                    cout<<"Ati ales optiunea: -Stergerea ultimei farmacii-";
                    chain.EraseLastPharmacy();
                    cout<<"\nFarmaciile ramase:\n";
                    chain.PrintChain();
                    break;
                }
                case 8: {
                    cout<<"Ati ales optiunea: -Stergerea ultimei farmacii online-";
                    chain_online.EraseLastPharmacy();
                    cout<<"\nFarmaciile ramase:\n";
                    chain_online.PrintChain();
                    break;
                }
            }
        }while(ok);

        system("cls");
        cout<<"\nID chain = "<<chain.GetId();
        chain.PrintChain();

        if(online){
            cout<<"\nID chain = "<<chain_online.GetId();
            chain_online.PrintChain();
        }
        cout<<"\nMai primim un client? (0)NU\\(1)DA\nRASPUNS = "; cin>>client;
        if(!client){
            cout<<"Programul s-a incheiat pe ziua de azi!\nLa revedere!";
        }
    }while(client);

    return 0;
}
bool Finish(){
    string answer;
    cout<<"\nContinuati adaugarea?\nDA\\NU\nRASPUNS = "; cin>>answer;
    if(answer[0]=='D' || answer[0]=='d')
        return 1;
    else if(answer[0]=='N' || answer[0]=='n')
        return 0;
    else {
        cout << "Introduceti din nou raspunsul: ";
        return Finish();
    }
}
int PrintAlegere(){
    int alegere;
    cout<<"\n\nCe doriti sa realizati?\n";
    cout<<"\n(1)Adaugarea unei farmacii\n(2)Adaugarea unei farmacii online";
    cout<<"\n(3)Afisarea farmaciilor inregistrate pana acum\n(4)Afisarea farmaciilor online inregistrate pana acum";
    cout<<"\n(5)Cati clienti au avut farmaciile?\n(6)Cati clienti au avut farmaciile online?";
    cout<<"\n(7)Stergerea ultimei farmacii\n(8)Stergerea ultimei farmacii online\n(0)Nimic";
    cout<<"\nALEGERE = "; cin>>alegere;
    return alegere;
}