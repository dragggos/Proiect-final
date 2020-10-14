#include "Bazin.h"
#include "Antrenor.h"
#include <vector>
#include <iostream>
#include <fstream>


using namespace std;

Bazin::Bazin()
{
    //ctor
}
void Bazin::Meniu()
{
    system("CLS");
    cout<<"********Organizare activitate bazin*******"<<endl;
    cout<<endl;
    cout<<"Alegeti optiunea dorita:"<<endl;
    cout<<endl;
    cout<<"1. Adauga antrenor"<<endl;
    cout<<"2. Sterge antrenor"<<endl;
    cout<<"3. Afiseaza cursanti antrenor"<<endl;
    cout<<"4. Adauga cursant"<<endl;
    cout<<"5. Sterge cursant"<<endl;
    cout<<"6. Vizualizare cursanti potentiali"<<endl;
    cout<<"0. Inchidere program"<<endl;
}
void Bazin::AdaugaAntrenor()
{
   // static short i=1;
    short max=1;
    string n,p;
    cout<<"Introduceti nume antrenor: ";
    cin>>n;
    cout<<"Introduceti prenume antrenor: ";
    cin>>p;
    if (vect_antrenor.size()==0)
         vect_antrenor.push_back(Antrenor(n,p,1));
       else
         {
          for (short i=1; i<vect_antrenor.size();i++)
            if (max<vect_antrenor[i].Get_id_antrenor())
                      max=vect_antrenor[i].Get_id_antrenor();
          vect_antrenor.push_back(Antrenor(n,p,++max));
         }
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
           cout<<"Selectati categorie cursant: 1.copil, 2.student, 3.adult, 4. pensionar: ";
           cin>>c;
           while (c>4)
            {
              cout<<endl;
              cout<<"Optiune incorecta, va rog reintroduceti categoria : ";
              cin>>c;
              cout<<endl;
             }
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
    for (unsigned short r=0; r<vect_antrenor.size();r++)
        cout<<vect_antrenor[r].Get_id_antrenor()<<". "<<vect_antrenor[r].Get_nume_antrenor()<<" "<<vect_antrenor[r].Get_prenume_antrenor()<<endl;
    cout<<"Introduceti id antrenor de sters: ";
    int n;
    cin>>n;
    bool opt=false;
    while (opt!=true)
    {
      for(unsigned short index=0;index<vect_antrenor.size();index++)
         if (n!=vect_antrenor[index].Get_id_antrenor())
                opt=false;
               else
               {
                opt=true;
                break;
               }
       if (opt==false)
           {
             cout<<endl;
             cout<<"Optiune incorecta, va rog reintroduceti optiunea : ";
              cin>>n;
            }
       }
    short minim=100, total_locuri_disp=0;
    short poz_ant_min=0, poz_ant_sters=0;
    for (unsigned short i=0; i<vect_antrenor.size();i++)
      if (vect_antrenor[i].Get_id_antrenor()!=n)
          {
            total_locuri_disp=total_locuri_disp+(4-vect_antrenor[i].NrCursantiAntrenor());
            if (minim>vect_antrenor[i].NrCursantiAntrenor())
             {
               minim=vect_antrenor[i].NrCursantiAntrenor();
               poz_ant_min=i;
             }
          }
         else poz_ant_sters=i;

   if (4-minim>=vect_antrenor[poz_ant_sters].NrCursantiAntrenor())
       {
           short nrc=vect_antrenor[poz_ant_sters].NrCursantiAntrenor();
           for (unsigned short j=0;j<nrc;j++)
              {
                vect_antrenor[poz_ant_min].MutaCursant(vect_antrenor[poz_ant_sters].ReturnCursant());
                vect_antrenor[poz_ant_sters].StergeC(0);
              }
       }
      else
         {
          short k=0;
          while (total_locuri_disp!=0)
            {
              short disp=4-vect_antrenor[k].NrCursantiAntrenor();
              if (k!=poz_ant_sters)
                for (unsigned short i=0;i<disp;i++)
                  {
                    vect_antrenor[k].MutaCursant(vect_antrenor[poz_ant_sters].ReturnCursant());
                    vect_antrenor[poz_ant_sters].StergeC(0);
                    total_locuri_disp--;
                    if (vect_antrenor[poz_ant_sters].NrCursantiAntrenor()==0) break;
                  }
              k++;
              if (vect_antrenor[poz_ant_sters].NrCursantiAntrenor()==0) break;
            }

           while (vect_antrenor[poz_ant_sters].NrCursantiAntrenor()>0)
               {
                 unsigned short i=0;
                 while (i<vect_antrenor.size())
                   {
                    if(i!=poz_ant_sters)
                      {
                        vect_antrenor[i].MutaCursant(vect_antrenor[poz_ant_sters].ReturnCursant());
                        vect_antrenor[poz_ant_sters].StergeC(0);
                        if (vect_antrenor[poz_ant_sters].NrCursantiAntrenor()==0) break;
                      }
                     i++;
                    }
               }
         }
vect_antrenor.erase(vect_antrenor.begin()+poz_ant_sters);
}
void Bazin::StergeCursant()
{
   system("CLS");
   cout<<"Cursantii bazinului sunt:"<<endl;
   cout<<endl;
   short x=1;
   for (unsigned int i=0; i<vect_antrenor.size();i++)
       {
           vect_antrenor[i].AfiseazaCursantpentruSters(x);
           x=x+vect_antrenor[i].NrCursantiAntrenor();
       }

   cout<<endl;
   cout<<"Selectati numarul cursantului de sters: ";
   short n;
   cin>>n;
   while (n>x)
            {
              cout<<endl;
              cout<<"Optiune incorecta, va rog reintroduceti numarul cursantului : ";
              cin>>n;
             }
   for (unsigned int i=0; i<vect_antrenor.size();i++)
        if (vect_antrenor[i].NrCursantiAntrenor()<n)
                 n=n-vect_antrenor[i].NrCursantiAntrenor();
            else
            {
               vect_antrenor[i].StergeC(n);
               break;
            }
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
void Bazin::ExportAntrenori(ofstream &out)
{
    for (unsigned short i=0;i<vect_antrenor.size();i++)
        out<<vect_antrenor[i].Get_nume_antrenor()<<" "<<vect_antrenor[i].Get_prenume_antrenor()<<" "<<vect_antrenor[i].Get_id_antrenor()<<endl;
}
void Bazin::ImportAntrenori(string n, string p, short i)
{
   vect_antrenor.push_back(Antrenor(n,p,i));
}
void Bazin::ExportCursant(ofstream &out)
{
    for (unsigned short i=0;i<vect_antrenor.size();i++)
        vect_antrenor[i].ExportC(out);
}
void Bazin::ExportCursantiPotentiali(ofstream &out)
{
    for (unsigned short i=0;i<vect_cursant_potential.size();i++)
        out<<vect_cursant_potential[i].Get_nume_cursant_potential()<<" "<<vect_cursant_potential[i].Get_prenume_cursant_potential()<<" "<<vect_cursant_potential[i].Get_email_cursant_potential()<<" "<<vect_cursant_potential[i].Get_tel_cursant_potential()<<endl;
}
void Bazin::ImportCursantiPotentiali(string n, string p, string e, string t)
{
   vect_cursant_potential.push_back(CursPotential(n,p,e,t));
}
void Bazin::ImportCursanti(string n, string p, short c, short nrlinie)
{
   //for (unsigned short i=0;i<vect_antrenor.size();i++)
        vect_antrenor[nrlinie].ImportC(n,p,c);
}

Bazin::~Bazin()
{
    //dtor
}
