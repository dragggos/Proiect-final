#include "Antrenor.h"
#include <iostream>
#include <vector>

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
        {
            cout<<i+1<<". "<<vect_cursant[i].Get_prenume_cursant()<<" "<<vect_cursant[i].Get_nume_cursant()<<" ";
            switch (vect_cursant[i].Get_categorie_cursant())
                {
                  case 1: cout<<" categoria - copil "<<endl;break;
                  case 2: cout<<" categoria - student "<<endl;break;
                  case 3: cout<<" categoria - adult "<<endl;break;
                  case 4: cout<<" categoria - pensionar "<<endl;break;
                }
        }
    cout<<endl;
    //cout<<"Total cursanti : "<<vect_cursant.size()<<endl;
    //cout<<endl;
    //system("PAUSE");
}
void Antrenor::AfiseazaCursantpentruSters(short n)
{
    for(unsigned int i=0; i<vect_cursant.size();i++)
        {
            cout<<n<<". "<<vect_cursant[i].Get_prenume_cursant()<<" "<<vect_cursant[i].Get_nume_cursant()<<" ";
            cout<<endl;
            n++;
        }

}
void Antrenor::CreazaCursant(string n, string p, short c)
{
   vect_cursant.push_back(Cursant(n,p,c));
}
short Antrenor::NrCursantiAntrenor()
{
    return vect_cursant.size();
}

void Antrenor::StergeC(short n)
{
    vect_cursant.erase(vect_cursant.begin()+n);
}

Antrenor::~Antrenor()
{
    //dtor
}
