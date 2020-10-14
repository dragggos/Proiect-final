#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Bazin.h"

using namespace std;

int main()
{
   Bazin bazin;
   ifstream inAntrenori("Antrenori.txt");
   while(!inAntrenori.eof())
    {
      char bufT[20];
      string d,dd;
      short i;
      inAntrenori.getline(bufT, 20);
      stringstream ss;
      ss<< bufT;
      if(ss.str().length() != 0)
      {
        ss>>d>>dd>>i;
        bazin.ImportAntrenori(d,dd,i);
      }
    }
    ifstream inCursantiPotentiali("CursantiPotentiali.txt");
    while(!inCursantiPotentiali.eof())
    {
      char bufT[70];
      string d,dd,e,t;
      inCursantiPotentiali.getline(bufT,70);
      stringstream ss;
      ss<< bufT;
      if(ss.str().length() != 0)
      {
        ss>>d>>dd>>e>>t;
        bazin.ImportCursantiPotentiali(d,dd,e,t);
      }
    }
    ifstream inCursanti("Cursanti.txt");
    while(!inCursanti.eof())
    {
      char bufT[70];
      string d,dd;
      short c;   short nrlinie=0;
      inCursanti.getline(bufT,70);
      stringstream ss;
      ss<< bufT;
      while ((ss.str().length() != 0) && (ss.tellg() != -1))
      {

        ss>>d>>dd>>c;
        bazin.ImportCursanti(d,dd,c,nrlinie);
        nrlinie++;
      }
    }
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
         case 2: bazin.StergeAntrenor();break;
         case 3: bazin.AfiseazaCursantiAntrenor();break;
         case 4: bazin.AdaugaCursant();break;
         case 5: bazin.StergeCursant();break;
         case 6: bazin.VizCursantiPotentiali();break;
     }
  }
   ofstream outAntrenori("Antrenori.txt");
   bazin.ExportAntrenori(outAntrenori);
   ofstream outCursanti("Cursanti.txt");
   bazin.ExportCursant(outCursanti);
   ofstream outCursantiPotentiali("CursantiPotentiali.txt");
   bazin.ExportCursantiPotentiali(outCursantiPotentiali);
   return 0;
}

