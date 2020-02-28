#ifndef CURSANTPOTENTIAL_H
#define CURSANTPOTENTIAL_H
#include <iostream>

using namespace std;


class CursantPotential
{
    public:
        CursantPotential();
        CursantPotential(string,string,string,double);
        virtual ~CursantPotential();
        string Get_nume_cursant_potential() {return nume;}
        string Get_prenume_cursant_potential() {return prenume;}
        string Get_email_cursant_potential() {return email;}
        double Get_tel_cursant_potential() {return tel;}

    protected:

    private:
        string nume,prenume,email;
        double tel;

};

#endif // CURSANTPOTENTIAL_H
