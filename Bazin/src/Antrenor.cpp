#include "Antrenor.h"
#include <iostream>

using namespace std;

Antrenor::Antrenor()
{
    //ctor
}
Antrenor::Antrenor(string n, string p, short i)
{
    nume=n;
    prenume=p;
    id=i;
}

bool Antrenor::VerificaDispAntrenor()
{
    if (vect_cursant.size()<40) return true;
      else return false;
}
void Antrenor::AfiseazaCursant()
{
    for(unsigned int i=0; i<vect_cursant.size();i++)
        cout<<i+1<<"."<<vect_cursant[0].Get_prenume_cursant()<<" "<<vect_cursant[i].Get_nume_cursant()<<" "<<vect_cursant[i].Get_categorie_cursant()<<endl;
    cout<<"Total cursanti : "<<vect_cursant.size()<<endl;
    system("PAUSE");
}
void Antrenor::CreazaCursant(string n, string p, short c)
{
    /*string n,p;
    short c;
    cout<<"Introduceti nume cursant: ";
    cin>>n;
    cout<<"Introduceti prenume cursant: ";
    cin>>p;
    cout<<"Introduceti categorie cursant: 1.copil, 2.student, 3.adult, 4. pensionar: ";
    cin>>c;*/
    vect_cursant.push_back(Cursant(n,p,c));
}
short Antrenor::NrCursAntrenor()
{
    return vect_cursant.size();
}


Antrenor::~Antrenor()
{
    //dtor
}
