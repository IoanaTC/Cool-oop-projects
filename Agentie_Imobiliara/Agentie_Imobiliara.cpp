#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
void MeniuDeAlegeri();
///LOCUINTA
class Locuinta
{
protected:
    string numeClient;
    int suprafataUtila;
    float discount;

public:
    //constructori pentru locuinta
    Locuinta(string numeClient="", int suprafataUtila=0, float discount=0):numeClient(numeClient), suprafataUtila(suprafataUtila), discount(discount){}
    Locuinta (Locuinta &locuinta): numeClient(locuinta.numeClient), suprafataUtila(locuinta.suprafataUtila), discount(locuinta.discount){}

    //destructor pentru locuinta
    virtual ~Locuinta(){}

    //settere+gettere
    void SetnumeClient(string nume);
    void SetsuprafataUtila(int suprafataUtila);
    void SetDiscount(float discount);

    string GetnumeClient();
    int GetsuprafataUtila();
    float GetDiscount();

    ///metode
    virtual double CalculChirie (int x, bool y)=0;

    //suparincarcare operatori
    virtual ostream &operator<< (ostream &out)=0;
    virtual istream &operator>> (istream &in)=0;

};
///APARTAMENT
class Apartament : public Locuinta
{
protected:
    int etaj;
    static int numarclientiapartament;

public:
    //constructori pentru clasa apartament
    Apartament(int etaj=0, string numeClient="", int suprafataUtila=0, float discount=0): Locuinta(numeClient, suprafataUtila, discount), etaj(etaj){} //constr param+neparam (are param default)
    Apartament(Apartament &apartament):Locuinta(apartament), etaj(apartament.etaj){}

    //destructor pentru clasa apartament
    ~Apartament(){}

    //settere+gettere
    void SetEtaj(int etaj);
    int GetEtaj();

    //supraincarcare operatori
    ostream& operator<< (ostream& out);
    istream& operator>> (istream& in);
    Apartament& operator= (Apartament& locuinta);

    ///metode
    double CalculChirie (int x, bool y);

    static void AfisareApartament(Apartament apartament);
    static int Getnumarclientiapartament();
    static void Incrementareclentiapartament();
};
int Apartament::numarclientiapartament=0;

///CASA
class Casa : public Locuinta
{
protected:
    int suprafataCurte;
    static int numarclienticasa;

public:
    //constructori pentru clasa casa
    Casa(int suprafataCasa=0, string numeClient="", int suprafataUtila=0, float discount=0): Locuinta(numeClient, suprafataUtila, discount), suprafataCurte(suprafataCasa){} //constructor param+neparam (param default)
    Casa(Casa &casa): Locuinta(casa), suprafataCurte(casa.suprafataCurte){}

    //destructor pentru clasa casa
    ~Casa(){}

    //settere+gettere
    void SetsuprafataCurte(int etaj);
    int GetsuprafataCurte();

    //supraincarcare operatori
    ostream& operator<< (ostream& out);
    istream& operator>> (istream& in);
    Casa& operator= ( Casa& locuinta);

    ///metode
    double CalculChirie (int x=200, bool y=0);

    static void AfisareCasa(Casa casa);
    static int Getnumarclienticasa();
    static void Incrementarenumarclienticasa();
};
int Casa::numarclienticasa=0;

///AGENTIE IMOBILIARA
class AgentieImobiliara
{
protected:
    vector<Locuinta*> agentie;
    static int numar_clienti; //variabila statica - tine cont de nr de clienti
public:
    //constructori pentru clasa agentie imobiliara
    AgentieImobiliara(){};
    AgentieImobiliara(AgentieImobiliara &agentie2);

    //destructor
    ~AgentieImobiliara();

    //metode
    void AdaugareResedinta(Locuinta *resedinta);
    static int GetNumarClienti();
    void AfisareClienti();
};
int AgentieImobiliara::numar_clienti=0;

void EfectuareSarcina(int alegere, Locuinta *resedinta);
int main()
{
    AgentieImobiliara agentie;
    system("cls");
    cout<<"Bine ati venit la agentia noastra imobiliara! \nSperam ca serviciile noastre sa va fie de folos!";

    bool inca_un_client=1, utilizare=1, vizualizare;
    do
    {
        int alegere;
        cout<<"\n\nCu ce tip de resedinta va putem ajuta? (apartament\\casa)\n\n";

        string resedinta; cin>>resedinta;
        if (tolower(resedinta[0])=='a')
            {
                Locuinta *apartament = new Apartament;
                agentie.AdaugareResedinta(apartament);
                system("cls");
                apartament->operator<<(cout);
                do
                {
                    MeniuDeAlegeri();
                    cout<<"\nAleg numarul "; cin>>alegere;
                    system("cls");
                    EfectuareSarcina(alegere, apartament);

                    cout<<"\n\nDoriti sa mai efectuati o actiune din meniu? (da=1, nu=0): "; cin>>utilizare;
                } while (utilizare);
            }
        else if(tolower(resedinta[0]=='c'))
            {
                Locuinta *casa = new Casa;
                agentie.AdaugareResedinta(casa);
                system("cls");

                casa->operator<<(cout);
                do
                    {
                        MeniuDeAlegeri();
                        cout<<"\nAleg numarul "; cin>>alegere;
                        system("cls");
                        EfectuareSarcina(alegere, casa);

                        cout<<"\n\nDoriti sa mai efectuati o actiune din meniu? (da=1, nu=0): "; cin>>utilizare;
                    } while (utilizare);
            }

        cout<<"\nDoriti sa vizualizati clientii de pana acum? (da=1, nu=0): "; cin>>vizualizare;
        if(vizualizare)
            agentie.AfisareClienti();

        cout<<"\n\nMai primim un client? (da=1, nu=0): \n\n";
        cin>>inca_un_client;

        system("cls");
    }while (inca_un_client);

    cout<<"\n\nProgramul de lucru s-a incheiat pe ziua de azi\n\n";
    return 0;
}

//SUPARINCARCARE OPERATORI APARTAMENT
ostream& Apartament::operator<<(ostream& out)
{
    out<<"\n\n"<<numeClient<<", apartamentul dumneavoastra se afla la etajul "<<etaj<<" si are suprafata utila = "<<suprafataUtila<<"m^2";
    out<<"\nDiscountul dvs este = "<<discount;
    return out;
}
istream& Apartament::operator>>(istream& in)
{
    system("cls");
    cout<<"Eu voi fi asistentul dumneavoastra pe parcurusul comunicarii cu agentia noastra imobiliara\nCum va numiti?\n\n";
    in>>numeClient;

    system("cls");
    cout<<"Ma bucur sa va cunosc, "<<numeClient<<"! Ce suprafata utila are apartamentul dumneavoastra?(m^2)\n";
    cout<<"Are "; in>>suprafataUtila;

    system("cls");

    cout<<"Super! Discountul dvs este = "; cin>>discount;
    system("cls");
    cout<<"La ce etaj se gaseste locuinta?\nLa etajul "; cin>>etaj;
    //system("cls");
    return in;
}
Apartament& Apartament::operator=(Apartament& locuinta)
{
    cout<<"\n";

    this->SetnumeClient(locuinta.GetnumeClient());
    this->SetsuprafataUtila(locuinta.GetsuprafataUtila());
    this->SetDiscount(locuinta.GetDiscount());
    this->SetEtaj(locuinta.GetEtaj());
    return *this;
}

//settere+gettere pt APARTAMENT
void Apartament::SetEtaj(int etaj){this->etaj=etaj;}
int Apartament::GetEtaj(){return etaj;}
int Apartament::Getnumarclientiapartament(){return numarclientiapartament;}
void Apartament::Incrementareclentiapartament(){numarclientiapartament++;}

//metode pt APARTAMENT
void Apartament::AfisareApartament(Apartament apartament)
{
    cout<<"\nInformatii despre apartament:";
    apartament.operator<<(cout);
}



//SUPARINCARCARE OPERATORI CASA
ostream& Casa::operator<<(ostream& out)
{
    out<<"\n\n"<<numeClient<<", casa dumneavoastra are o curte cu o suprafata egala cu "<<suprafataCurte<<"m^2 si are suprafata utila = "<<suprafataUtila<<"m^2";
    out<<"\nDiscountul dvs = "<<discount;
    return out;
}
istream& Casa::operator>>(istream& in)
{
    system("cls");
    cout<<"Eu voi fi asistentul dumneavoastra pe parcurusul comunicarii cu agentia noastra imobiliara\nCum va numiti?\n\n";
    in>>numeClient;

    system("cls");
    cout<<"Ma bucur sa va cunosc, "<<numeClient<<"! Ce suprafata utila are casa dumneavoastra?(m^2)\n";
    cout<<"Are "; in>>suprafataUtila;cout<<"m^2";

    system("cls");

    cout<<"Super! Discountul dumneavoastra este = "; in>>discount;
    system("cls");
    cout<<"Ce suprafata are curtea dumneavoastra?(m^2)\nAre ";in>>suprafataCurte;
    system("cls");
    return in;
}
Casa& Casa::operator=(Casa& locuinta)
{
    cout<<"\n";
    this->SetnumeClient(locuinta.GetnumeClient());
    this->SetsuprafataUtila(locuinta.GetsuprafataUtila());
    this->SetDiscount(locuinta.GetDiscount());
    this->SetsuprafataCurte(locuinta.GetsuprafataCurte());
    return *this;
}

//settere+gettere CASA
void Casa::SetsuprafataCurte(int etaj){this->suprafataCurte=suprafataCurte;}
int Casa::GetsuprafataCurte(){return suprafataCurte;}
int Casa::Getnumarclienticasa(){return numarclienticasa;}
void Casa::Incrementarenumarclienticasa(){numarclienticasa++;}

//metode pt CASA
void Casa::AfisareCasa (Casa casa)
{
    cout<<"\nInformatii despre casa:";
    casa.operator<<(cout);
}



//CALCUL CHIRIE
double Apartament::CalculChirie(int x, bool y)
{
    return x*suprafataUtila * (1-y*discount/100.0);
}
double Casa::CalculChirie(int x, bool y)
{
    return x*(suprafataUtila + 0.2*suprafataCurte) * (1-y*discount/100.0);
}



//settere+gettere Locuinta
void Locuinta::SetnumeClient(string numeClient){this->numeClient=numeClient;}
void Locuinta::SetsuprafataUtila(int suprafataUtila){this->suprafataUtila=suprafataUtila;}
void Locuinta::SetDiscount(float discount){this->discount=discount;}

string Locuinta::GetnumeClient(){return numeClient;}
int Locuinta::GetsuprafataUtila(){return suprafataUtila;}
float Locuinta::GetDiscount(){return discount;}



//constructor_copiere AGENTIE IMOBILIARA
AgentieImobiliara::AgentieImobiliara(AgentieImobiliara &Agentie)
{
    for(int i=0; i<(Agentie.agentie).size(); i++)
        this->agentie[i] = Agentie.agentie[i];
    for(int i=Agentie.agentie.size(); i<this->agentie.size(); i++)
        this->agentie.erase(this->agentie.begin()+i);
}
//destructor AGENTIE IMOBILIARA
AgentieImobiliara::~AgentieImobiliara()
{
    agentie.clear();
}

//metode AGENTIE IMOBILIARA
void AgentieImobiliara::AdaugareResedinta(Locuinta *resedinta)
{
    agentie.push_back(resedinta);

    numar_clienti++;

    if(Apartament* apartament = dynamic_cast<Apartament*>(resedinta))
        {
            apartament->operator>>(cin);
            Apartament::Incrementareclentiapartament();
        }

    else if(Casa* casa = dynamic_cast<Casa*>(resedinta))
        {
            casa->operator>>(cin);
            Casa::Incrementarenumarclienticasa();
        }
}
int AgentieImobiliara::GetNumarClienti()
{
    return numar_clienti;
}



void MeniuDeAlegeri()
{
    cout<<"\n\nAcesta este meniul:";
    cout<<"\nAlegeti o optiune dintre cele afisate, sau 0 pentru a parasi interactiunea";
    cout<<"\n\n1) Cati clienti au trecut pragul agentiei noastre pana acum?";
    cout<<"\n2) Date despre locuinta mea";
    cout<<"\n3) Costul chiriei dupa calculul discountului";
    cout<<"\n4) Cati clienti detin un apartament?";
    cout<<"\n5) Cati clienti detin o casa?";
}

void EfectuareSarcina(int alegere, Locuinta *resedinta)
{
    switch(alegere)
    {
        case 1:
        {
            cout<<"\n\nAti ales 1: -numarul de clienti care au trecut pragul agentiei-";
            cout<<"\nCLIENTI = "<<AgentieImobiliara::GetNumarClienti();

            break;
        }
        case 2:
        {
            cout<<"\n\nAti ales 2: -date despre locuinta mea-";

            if(Apartament *apartament = dynamic_cast<Apartament*>(resedinta))
            {
                Apartament ap;
                ap.operator=(*apartament);

                Apartament::AfisareApartament(ap);
            }
            else if(Casa *casa = dynamic_cast<Casa*>(resedinta))
            {
                Casa ca;
                ca.operator=(*casa);

                Casa::AfisareCasa(ca);
            }
            break;
        }
        case 3:
        {
            cout<<"\n\nAti ales 3: -calculul chiriei-";

            int x;
            bool y;
            cout<<"\nCe suma trebuie sa platiti drept chirie, fara a lua in considerare discountul? "; cin>>x;
            cout<<"\nPutem lua in considerare discountul? (da=1, nu=0) "; cin>>y;

            cout<<"\n\nIn total aveti de platit: ";
            if(Apartament *apartament = dynamic_cast<Apartament*>(resedinta))
                cout<<apartament->CalculChirie(x,y);
            else if(Casa *casa = dynamic_cast<Casa*>(resedinta))
                cout<<casa->CalculChirie(x,y);

            cout<<" unitati monetare";
            break;
        }
        case 4:
        {
            cout<<"\n\nAti ales 4: -numarul clientilor care detin un apartament-";

            cout<<"\nCLIENTI = "<<Apartament::Getnumarclientiapartament();
            break;
        }
        case 5:
        {
            cout<<"\n\nAti ales 5: -numarul clientilor care detin o casa-";

            cout<<"\nCLIENTI = "<<Casa::Getnumarclienticasa();
            break;
        }
        default:
        {
            cout<<"Ati incheiat interactiunea cu meniul";
            break;
        }
    }
}
void AgentieImobiliara::AfisareClienti()
{
    system("cls");
    cout<<"Clientii care au pasit pragul astazi sunt in numar de "<<AgentieImobiliara::GetNumarClienti();

    for(int i=0; i<agentie.size(); i++)
        if(Apartament *apartament = dynamic_cast<Apartament*>(agentie[i]))
            apartament->operator<<(cout);
        else if(Casa *casa = dynamic_cast<Casa*>(agentie[i]))
            casa->operator<<(cout);
}