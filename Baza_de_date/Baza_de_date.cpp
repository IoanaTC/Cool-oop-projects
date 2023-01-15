#include <iostream>
#include <cstring>
using namespace std;

///Meniu interactiv, cu comenzile disponibile in aceasta aplicatie
void AfisareListaOptiuni()
{
    cout<<"1. Adaugare persoane.\n";
    cout<<"2. Eliminare persoana in functie de NUME.\n";
    cout<<"3. Eliminare persoana in functie de ANUL NASTERII.\n";
    cout<<"4. Eliminare persoana in functie de SEX. \n";
    cout<<"5. Afisarea tuturor persoanelor in ordine alfabetica. \n";
    cout<<"6. Afisarea tuturor persoanelor in ordine crescatoare dupa varsta. \n";
    cout<<"7. Incetarea programului. \n\n";
}
class Persoana ///obiectul persoana cu informatii despre nume, an_nastere, respectiv sexul acesteia
{
    string nume;
    int an_nastere;
    char sex;
public:
    friend istream &operator>> (istream &in, Persoana &p);
    ///constructor parametrizt, de copiere
    Persoana(string nume, int an_nastere, char sex)//constructor parametrizat
    {
        this->nume=nume;
        this->an_nastere=an_nastere;
        this->sex=sex;
    }
    Persoana(){}

    Persoana (Persoana &p) //contructor de copiere
    {
        nume=p.nume;
        an_nastere=p.an_nastere;
        sex=p.sex;
    }

    void Afisaree(Persoana p)
    {
        cout<<p.nume<<" "<<p.an_nastere<<" "<<p.sex<<endl;
    }
    void Afisarea()
    {
        cout<<nume<<" "<<an_nastere<<" "<<sex<<endl;
    }
    //setteri
    void SetNume(string nume){this->nume=nume;}
    void SetAnNastere(int an_nastere){this->an_nastere=an_nastere;}
    void SetSex(char sex){this->sex=sex;}

    //getteri
    string GetNume(){return nume;}
    int GetAnNastere(){return an_nastere;}
    char GetSex(){return sex;}
};

class Baza_de_date /// baza de date = array cu persoane, respectiv cate sunt
{
    int numar_persoane;
    Persoana *v;
    //nu sunt necesari setteri/getteri pentru aceste date, deoarece obiectul baza_de_date este
    //doar un instrument de stocare pentru obiectele persoana, cele care au de fapt nevoie de metode de manipulare a valorilor atributelor
public:
    friend class Persoana;
    friend ostream &operator<< (ostream &out, Persoana p);

    //constructor
    Baza_de_date(){v=new Persoana[10000], numar_persoane=0;}

    //destructor
    ~Baza_de_date()
    {
        delete []v;
        numar_persoane=0;
    }

    //functie get pentru numarul de persoane din array
    int GetNumarPersoane(){return numar_persoane;}

    //metode de adaugare, eliminare si sortare a persoanelor
    void Adaugare(string nume, int an_nastere, char sex);
    void Eliminare(string nume);
    void Eliminare(int an_nastere);
    void Eliminare(char sex);
    void Alfabetic();
    void VarstaCrescator();

    //metoda de afisare a bazei de date
    void Afisare();
};



int main()
{
    ///TESTARE CONSTRUCTOR PARAMETRIZAT, RESP. CONSTRUCTOR COPIERE
    // Persoana p("Ioana", 2002, 'F');
    // p.Afisarea();

    // Persoana b;
    // b.Afisaree(p);

    /////

    char raspuns[10];

    cout<<"Hello world!\n\n";
    cout<<" Doriti sa creati o baza de date? (da/nu/nu stiu) \n\nRaspunsul dumneavoastra: "; cin.getline(raspuns, 10);
    bool gata=1;
    do
    {
        if(!strcmp(raspuns, "da") || !strcmp(raspuns, "Da")) //Rapsuns=da =>baza de date se va crea
        {
            system("cls");
            cout<<"\n\n Haideti sa ne apucam de baza de date:"; gata=true;

            int comanda;
            bool continuare_program=1;

            Baza_de_date b;
            cout<<"\n\n Va rog sa alegeti o optiune din lista urmatoare de comenzi, apasand tasta corespunzatoare indicelui ei:\n";
            do
            {
                //AFISARE MENIU INTERCATIV

                cout<<"\n\n Acesta este meniul:\n\n";
                AfisareListaOptiuni();
                cout<<"Raspunsul dumneavoastra: "; cin>>comanda;

                system("cls");

                switch (comanda) //  INCEPUTUL INTERACTIUNII CU MENIUL
                {
                case 1: //adaugare persoana in baza de date
                    {
                        bool adaugare=0;
                        do
                        {
                            cout<<"\n\n Ati ales optiunea de inserare a persoanelor in baza dumneavoatra de date:\n";
                            b.Afisare();

                            Persoana p;
                            operator>>(cin, p); //supraincarcare >> => citirea tuturor datelor necesare unei persoane din baza de date
                            b.Adaugare(p.GetNume(), p.GetAnNastere(), p.GetSex());

                            cout<<" \nMai doriti sa adugati pe cineva? (da=1, nu=0)\nRaspunsul dumneavoastra: "; cin>>adaugare;

                            system("cls");
                        }while(adaugare==1);
                        b.Afisare();
                        cout<<"\n\nDoriti sa continuati? (da=1, nu=0)\nRaspunsul dumneavoastra: "; cin>>continuare_program;
                        break;
                    }
                case 2: // eliminare persoana in functie de nume
                    {
                        string nume;
                        bool eliminare=1;
                        do
                        {
                            if(b.GetNumarPersoane()>0) //eliminarea are loc doar daca baza nu este vida
                            {
                                cout<<"\n\n Ati ales optiunea de eliminare a persoanelor din baza dumneavoatra de date, in functie de NUME\n";
                                b.Afisare();

                                cout<<"\n Ce persoane doriti sa eliminati?\nNume: "; cin>>nume; system("cls");
                                cout<<"\n\nVa rog asteptati, se elimina persoanele care poarta numele de "<<nume<<"...\n\n";
                                b.Eliminare(nume);
                                b.Afisare();

                                cout<<"\n Va doriti sa mai eliminati pe cineva in functie de nume? (da=1, nu=0)\nRaspunsul dumneavoastra: ", cin>>eliminare, system("cls");
                            }
                            else
                                cout<<"\n Actiune nepermisa!\n", eliminare=0;

                        }while(eliminare==1);
                        b.Afisare();
                        cout<<"\n\nDoriti sa continuati? (da=1, nu=0)\nRaspunsul dumneavoastra: "; cin>>continuare_program;
                        break;
                    }
                case 3: // eliminare perosana in functie de anul nasterii
                    {
                        int an_nastere;
                        bool eliminare=1;
                        do
                        {
                            if(b.GetNumarPersoane()>0) // eliminarea are loc doar daca baza nu este vida
                            {
                                cout<<"\n\n Ati ales optiunea de eliminare a persoanelor din baza dumneavoatra de date, in functie de ANUL NASTERII\n";
                                b.Afisare();

                                cout<<"\n Ce persoane doriti sa eliminati?\nAnul Nasterii: "; cin>>an_nastere; system("cls");
                                cout<<"\n\nVa rog asteptati, se elimina persoanele care s-au nascut in anul "<<an_nastere<<"...\n\n";
                                b.Eliminare(an_nastere);
                                b.Afisare();

                                cout<<"\n Va doriti sa mai eliminati pe cineva in functie de anul nasterii? (da=1, nu=0)\nRaspunsul dumneavoastra: ", cin>>eliminare, system("cls");
                            }
                            else
                                cout<<"\n Actiune nepermisa!\n", eliminare=0;

                        }while(eliminare==1);
                        b.Afisare();
                        cout<<"\n\nDoriti sa continuati? (da=1, nu=0)\nRaspunsul dumneavoastra: "; cin>>continuare_program;
                        break;
                    }
                case 4: // eliminare persoana in functie de sex
                    {
                        char sex;
                        bool eliminare=1;
                        do
                        {
                            if(b.GetNumarPersoane()>0) // eliminarea are loc doar daca baza nu este vida
                            {
                                 cout<<"\n\n Ati ales optiunea de eliminare a persoanelor din baza dumneavoatra de date, in functie de SEX\n";
                                b.Afisare();

                                cout<<"\n Ce persoane doriti sa eliminati?\nSex (M/F): "; cin>>sex; system("cls");
                                if(sex=='F' || sex=='f')
                                    cout<<"\n\nVa rog asteptati, se elimina persoanele de sex "<<sex<<"eminin...\n\n";
                                else if(sex=='M' || sex=='f')
                                    cout<<"\n\nVa rog asteptati, se elimina persoanele de sex "<<sex<<"asculin...\n\n";
                                b.Eliminare(sex);
                                b.Afisare();

                                cout<<"\n Va doriti sa mai eliminati pe cineva in functie de sex? (da=1, nu=0)\nRaspunsul dumneavoastra: ", cin>>eliminare, system("cls");
                            }
                            else
                                cout<<"\n Actiune nepermisa!\n", eliminare=0;

                        }while(eliminare==1);
                        b.Afisare();
                        cout<<"\n\nDoriti sa continuati? (da=1, nu=0)\nRaspunsul dumneavoastra: "; cin>>continuare_program;
                        break;
                    }
                case 5: // afisarea persoanelor in ordine alfabetica
                    {
                        cout<<"\n\n Ati ales optiunea de afisare a persoanelor din baza dumneavastra de date in ordine alfabetica.\n";

                        if(b.GetNumarPersoane()>0) // afisarea are loc doar daca baza nu este vida
                            b.Alfabetic();
                        else cout<<"\n Actiune nepermisa!\n";

                        b.Afisare();
                        cout<<"\n\nDoriti sa continuati? (da=1, nu=0)\nRaspunsul dumneavoastra: "; cin>>continuare_program;
                        break;
                    }
                case 6: // afisarea persoanelor in ordinea crescatoare a varstei
                    {
                        cout<<"\n\n Ati ales optiunea de afisare a persoanelor din baza dumneavoastra de date in ordinea crescatoare a varstei.\n";

                        if(b.GetNumarPersoane()>0) // afisarea are loc doar daca baza nu este vida
                            b.VarstaCrescator();
                        else cout<<"\n Actiune nepermisa!\n";

                        b.Afisare();
                        cout<<"\n\nDoriti sa continuati? (da=1, nu=0)\nRaspunsul dumneavoastra: "; cin>>continuare_program;
                        break;
                    }
                case 7: // termiiarea programului
                    {
                        cout<<"La revedere!!";
                        return 0;
                    }
                default: // comanda necunoscuta => recitirea acesteia
                    cout<<"\n Comanda introdusa nu exista. Va rog introduceti din nou comanda: \n\nRaspunsul dumneavoastra: "; cin>>comanda;
                }

            }while(continuare_program==1);
            cout<<"\n\nLa revedere!!";
            return 0;
        }
        else if(!strcmp(raspuns, "nu") || !strcmp(raspuns, "Nu")) // Raspuns=nu => programul se asigura ca clientul isi doreste sa paraseasca aplicatia
        {
            system("cls");
            cout<<"\n Sunteti sigur ca doriti sa parasiti aceste meniu? (da/nu)\n Aceasta actiune este irevocabila\n\nRaspunsul dumneavoastra: "; cin.getline(raspuns, 10);
            if (!strcmp(raspuns, "da") || !strcmp(raspuns, "Da")) // terminarea programului
            {
                cout<<"\nLa revedere!!";
                return 0;
            }
            else if(!strcmp(raspuns, "nu") || !strcmp(raspuns, "Nu")) // continuarea programului=>crearea bazei de date
                cout<<"\n Super\n", strcpy(raspuns, "da"), gata=false;
        }
        else if(!strcmp(raspuns, "nu stiu") || !strcmp(raspuns, "Nu stiu")) // bonus, raspunsul ,,nu stiu" :))
            {
                system("cls");
                cout<<"\n Cand va hotarati: Raspunsul dumneavoastra (da/nu): "; cin.getline(raspuns, 10);
                gata=0;
            }
        else // comanda inexistenta=>repetarea raspunsului
        {
            system("cls");
            cout<<" Habar nu am ce ati spus!\n\nRaspunsul dumneavoastra: (da/nu/nu stiu) "; cin.getline(raspuns, 10);
            gata=0;
        }
    }while(gata==0);
    return 0;
}


///Suprascrierea operatorilor << , >>

ostream &operator<< (ostream &out, Persoana p) // afisare date persoana: nume, an_nastere, sex
{
    if(p.GetSex()=='F')
        out<<p.GetNume()<<" ("<<p.GetSex()<<"eminin), nascuta in anul "<<p.GetAnNastere()<<endl;
    else out<<p.GetNume()<<" ("<<p.GetSex()<<"asculin), nascut in anul "<<p.GetAnNastere()<<endl;

    return out;
}

istream &operator>> (istream &in, Persoana &p) // citire date persoana: nume, an_nastere, sex
{

    cout<<"\n\n  Datele persoanei sunt:\n";
    cout<<"Nume: "; in>>p.nume, cin.get();
    cout<<"Anul in care s-a nascut: "; in>>p.an_nastere;
    cout<<"Sex (M/F): "; in>>p.sex;

    return in;
}

///Metodele folosite in clasa Baza_de_date

void Baza_de_date::Adaugare(string Nume, int An_nastere, char Sex) // ADAUGARE PERSOANA
{
    Persoana p;
    p.SetNume(Nume), p.SetAnNastere(An_nastere), p.SetSex(Sex);

    v[++numar_persoane]=p;
}
void Baza_de_date::Eliminare(string Nume) // ELIMINARE PERSOANA DUPA NUME
{
    if(numar_persoane==0)
        cout<<"\n\n Baza dumneavoastra de date este vida. Va rog, adaugati persoane!";
    else
    {
        for(int i=1; i<=numar_persoane; i++)
        if(v[i].GetNume()==Nume)
        {
            for(int j=i+1; j<=numar_persoane; j++)
            {

                v[j-1].SetNume(v[j].GetNume());
                v[j-1].SetAnNastere(v[j].GetAnNastere());
                v[j-1].SetSex(v[j].GetSex());
            }
            numar_persoane--;
            i--;
        }
    }
}
void Baza_de_date::Eliminare(int An_nastere) // ELIMINARE PERSOANA DUPA ANUL NASTERII
{
    if(numar_persoane==0)
        cout<<"\n\n Baza dumneavoastra de date este vida. Va rog, adaugati persoane!";
    else
    {
        for(int i=1; i<=numar_persoane; i++)
        if(v[i].GetAnNastere()==An_nastere)
        {
            for(int j=i+1; j<=numar_persoane; j++)
            {
                v[j-1].SetNume(v[j].GetNume());
                v[j-1].SetAnNastere(v[j].GetAnNastere());
                v[j-1].SetSex(v[j].GetSex());
            }
            numar_persoane--;
            i--;
        }
    }
}
void Baza_de_date::Eliminare(char Sex) // ELIMINARE PERSOANA DUPA SEX
{
    if(numar_persoane==0)
        cout<<"\n\n Baza dumneavoastra de date este vida. Va rog, adaugati persoane!";
    else
    {
        for(int i=1; i<=numar_persoane; i++)
        if(v[i].GetSex()==Sex)
        {
            for(int j=i+1; j<=numar_persoane; j++)
            {
                v[j-1].SetNume(v[j].GetNume());
                v[j-1].SetAnNastere(v[j].GetAnNastere());
                v[j-1].SetSex(v[j].GetSex());
            }
            numar_persoane--;
            i--;
        }
    }
}
void Baza_de_date::Alfabetic() // AFISAREA PERSOANLEOR IN ORDINE ALFABETICA
{
    for(int i=1; i<numar_persoane; i++)
        for(int j=i+1; j<=numar_persoane; j++)
            if(v[i].GetNume()>v[j].GetNume())
            {
                Persoana p1(v[i].GetNume(), v[i].GetAnNastere(), v[i].GetSex());
                v[i].SetNume(v[j].GetNume());
                v[i].SetAnNastere(v[j].GetAnNastere());
                v[i].SetSex(v[j].GetSex());

                v[j].SetNume(p1.GetNume());
                v[j].SetAnNastere(p1.GetAnNastere());
                v[j].SetSex(p1.GetSex());
            }
                //swap(v[i], v[j]);
}
void Baza_de_date::VarstaCrescator() // AFISAREA PERSOANELOR IN ORDINEA CRESCATOARE A VARSTEI LOR
{
    for(int i=1; i<numar_persoane; i++)
        for(int j=i+1; j<=numar_persoane; j++)
            if(v[i].GetAnNastere()<v[j].GetAnNastere())
            {
                Persoana p1(v[i].GetNume(), v[i].GetAnNastere(), v[i].GetSex());
                v[i].SetNume(v[j].GetNume());
                v[i].SetAnNastere(v[j].GetAnNastere());
                v[i].SetSex(v[j].GetSex());

                v[j].SetNume(p1.GetNume());
                v[j].SetAnNastere(p1.GetAnNastere());
                v[j].SetSex(p1.GetSex());
            }
                //swap(v[i], v[j]);
}
void Baza_de_date::Afisare() // AFISAREA, PUR SI SIMPLU, A PERSOANELOR STOCATE SAU A BAZEI DE DATE VIDE DACA ESTE CAZUL
{
    if(numar_persoane==0)
        cout<<"\n\n Baza dumneavoastra de date este vida. Va rog, adaugati persoane!\n";
    else
    {
        cout<<"\n Persoanele existente in baza dumneavoastra, alaturi de datele acestora sunt:\n\n";
        for(int i=1; i<=numar_persoane; i++)
                operator<<(cout, v[i]); //suprascriere <<
    }
}