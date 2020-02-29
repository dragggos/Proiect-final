#include "Bazin.h"
#include "Antrenor.h"
#include <vector>
#include <iostream>

using namespace std;

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
    vector<Antrenor> vect_ant_disp;
    for (unsigned int i=0;i<vect_antrenor.size();i++)
        if (vect_antrenor[i].VerificaDispAntrenor())
               {
                   vect_ant_disp.push_back(vect_antrenor[i]);
                   este=true;
               }
      if (!este)
               {
                 system("CLS");
                 cout<<"Ne pare rau, toti antrenorii nostri sunt ocupati!"<<endl;
                 cout<<"Lasati-ne datele de contact si va vom contacta deindata ce apare o pozitie libera!"<<endl;
                 cout<<endl;
                 string n,p,e,t;
                 cout<<"Introduceti numele: ";
                 cin>>n;
                 cout<<"Introduceti prenume: ";
                 cin>>p;
                 cout<<"Introduceti email: ";
                 cin>>e;
                 cout<<"Introduceti telefon: ";
                 cin>>t;
                 vect_cursant_potential.push_back(CursPotential(n,p,e,t));
               }
          else
          {
           short m;
           string n,p;
           short c;
           cout<<"Introduceti nume cursant: ";
           cin>>n;
           cout<<"Introduceti prenume cursant: ";
           cin>>p;
           cout<<"Introduceti categorie cursant: 1.copil, 2.student, 3.adult, 4. pensionar: ";
           cin>>c;
           cout<<"Selectati antrenor: ";
           cout<<endl;
           for (unsigned int j=0; j<vect_ant_disp.size();j++)
               cout<<vect_ant_disp[j].Get_id_antrenor()<<". "<<vect_ant_disp[j].Get_nume_antrenor()<<" "<<vect_ant_disp[j].Get_prenume_antrenor()<<endl;
           cout<<"Introduceti id : ";
           cin>>m;
           for (unsigned i=0;i<vect_antrenor.size();i++)
                  if(m==vect_antrenor[i].Get_id_antrenor())
                              vect_antrenor[i].CreazaCursant(n,p,c);
          }
}
void Bazin::StergeAntrenor()
{
    for (unsigned int i=0; i<vect_antrenor.size();i++)
        cout<<vect_antrenor[i].Get_id_antrenor()<<". "<<vect_antrenor[i].Get_nume_antrenor()<<" "<<vect_antrenor[i].Get_prenume_antrenor()<<endl;
    cout<<"Introducti id antrenor de sters: ";
    short n;
    cin>>n;
    short minim=100;
    short id=100;
    for (unsigned short i=0; i<vect_antrenor.size();i++)
      if (vect_antrenor[i].Get_id_antrenor()!=n)
          if (minim>vect_antrenor[i].NrCursantiAntrenor())
             {
               minim=vect_antrenor[i].NrCursantiAntrenor();
               id=vect_antrenor[i].Get_id_antrenor();
             }
     for (unsigned short i=0; i<vect_antrenor.size();i++)
        if (vect_antrenor[i].Get_id_antrenor()==n){}


}
void Bazin::StergeCursant()
{
   system("CLS");
   cout<<"Cursantii bazinului sunt:"<<endl;
   cout<<endl;
   for (unsigned int i=0; i<vect_antrenor.size();i++)
         vect_antrenor[i].AfiseazaCursantpentruSters();
   cout<<endl;
   cout<<"Selectati numarul cursantului de sters: ";
   short n;
   cin>>n;
   for (unsigned int i=0; i<vect_antrenor.size();i++)
        if (vect_antrenor[i].NrCursantiAntrenor()<n)
             n=n-vect_antrenor[i].NrCursantiAntrenor();
           else
              vect_antrenor[i].StergeC(n);
}
void Bazin::VizCursantiPotentiali()
{
   system("CLS");
   cout<<"****Lista cursanti potentiali****"<<endl;
   cout<<endl;
   for (unsigned short i=0;i<vect_cursant_potential.size();i++)
   {

       cout<<i+1<<". "<<vect_cursant_potential[i].Get_nume_cursant_potential()<<" ";
       cout<<vect_cursant_potential[i].Get_prenume_cursant_potential()<<"   email: ";
       cout<<vect_cursant_potential[i].Get_email_cursant_potential()<<"  tel: ";
       cout<<vect_cursant_potential[i].Get_tel_cursant_potential()<<endl;
   }
   cout<<endl;
   system("PAUSE");
}
void Bazin::AfiseazaCursantiAntrenor()
{
  system("CLS");
  cout<<"Selectati antrenorul: "<<endl;
  cout<<endl;
  for (unsigned short i=0;i<vect_antrenor.size();i++)
    cout<<vect_antrenor[i].Get_id_antrenor()<<". "<<vect_antrenor[i].Get_nume_antrenor()<<" "<<vect_antrenor[i].Get_prenume_antrenor()<<endl;
  cout<<endl;
  cout<<"Introduceti id-ul antrenorului pentru care doriti sa vizualizati cursantii: ";
  short n;
  cin>>n;
  cout<<endl;
  for (unsigned short i=0;i<vect_antrenor.size();i++)
    if (vect_antrenor[i].Get_id_antrenor()==n)
        {
            vect_antrenor[i].AfiseazaCursant();
            cout<<"Total cursanti antrenor : "<<vect_antrenor[i].NrCursantiAntrenor()<<endl;
        }
   cout<<endl;
   system("PAUSE");
}

Bazin::~Bazin()
{
    //dtor
}
