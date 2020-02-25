#include <iostream>
#include <vector>
#include "Bazin.h"

using namespace std;

void Meniu()
{
    system("CLS");
    cout<<"********Organizare activitate bazin*******"<<endl;
    cout<<endl;
    cout<<"Alegeti optiunea dorita:"<<endl;
    cout<<endl;
    cout<<"1. Adauga antrenor"<<endl;
    cout<<"2. Sterge antrenor"<<endl;
    cout<<"3. Afiseaza ore antrenor"<<endl;
    cout<<"4. Adauga cursant"<<endl;
    cout<<"5. Sterge cursant"<<endl;
    cout<<"6. Vizualizare cursanti potentiali"<<endl;
    cout<<"0. Inchidere program"<<endl;
}
int main()
{
   Bazin bazin;
   short n=1;
   while (n!=0)
  {
     Meniu();
     cout<<endl;
     cout<<"Introduceti optiunea : ";
     cin>>n;
   /*while (n>2)
            {
              cout<<"Optiune incorecta, va rog reintroduceti optiunea : ";
              cin>>n;
             }*/
     switch (n)
     {
         case 1: bazin.AdaugaAntrenor();break;
         case 2:{};

     }

  }
}

