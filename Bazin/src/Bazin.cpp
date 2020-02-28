#include "Bazin.h"

Bazin::Bazin()
{
    //ctor
}
void Bazin::AdaugaAntrenor()
{
    static short i=0;
    string n,p;
    cout<<"Introduceti nume antrenor: ";
    cin>>n;
    cout<<"Introduceti prenume antrenor: ";
    cin>>p;
    vect_antrenor.push_back(Antrenor(n,p,i));
    i++;
}
void Bazin::AdaugaCursant()
{
    bool este=false;
    for (unsigned int i=0;i<=vect_antrenor.size();i++)
        if (vect_antrenor[i].VerificaDispAntrenor())
            {
              este=true;
              break;
            }
     if este vect_antrenor[].CreazaCursant;
        {



        }




}
Bazin::~Bazin()
{
    //dtor
}
