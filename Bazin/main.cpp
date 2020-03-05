#include <iostream>
#include <vector>
#include "Bazin.h"

using namespace std;

int main()
{
   Bazin bazin;
   short n=1;
   while (n!=0)
  {
     bazin.Meniu();
     cout<<endl;
     cout<<"Introduceti optiunea : ";
     cin>>n;
     while (n>6)
            {
              cout<<endl;
              cout<<"Optiune incorecta, va rog reintroduceti optiunea : ";
              cin>>n;
             }
     switch (n)
     {
         case 1: bazin.AdaugaAntrenor();break;
         case 3: bazin.AfiseazaCursantiAntrenor();break;
         case 4: bazin.AdaugaCursant();break;
         case 5: bazin.StergeCursant();break;
         case 6: bazin.VizCursantiPotentiali();break;
     }
  }
  return 0;
}

