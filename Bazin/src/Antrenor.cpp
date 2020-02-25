#include "Antrenor.h"
#include <iostream>

using namespace std;

Antrenor::Antrenor()
{
    //ctor
}
Antrenor::Antrenor(string n, string p, short i)
{
    nume_ant=n;
    prenume_ant=p;
    id=i;
}
void Antrenor::AdaugaCursant()
{
    string n,p;
    short c;
    cout<<"Introduceti nume cursant: ";
    cin>>n;
    cout<<"Introduceti prenume cursant: ";
    cin>>p;
    cout<<"Introduceti categorie cursant: 1.copil, 2.student, 3.adult, 4. pensionar: ";
    cin>>c;
    vect_cursant.push_back(Cursant(n,p,c));
}
void Antrenor::AfiseazaCursant()
{
    for(unsigned int i=0; i<=vect_cursant.size();i++)
        cout<<vect_cursant[i].Get_prenume_cursant();
}
Antrenor::~Antrenor()
{
    //dtor
}
