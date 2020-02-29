#ifndef CURSPOTENTIAL_H
#define CURSPOTENTIAL_H
#include <iostream>

using namespace std;


class CursPotential
{
    public:
        CursPotential();
        virtual ~CursPotential();
        CursPotential(string,string,string,string);
        string Get_nume_cursant_potential() {return nume;}
        string Get_prenume_cursant_potential() {return prenume;}
        string Get_email_cursant_potential() {return email;}
        string Get_tel_cursant_potential() {return tel;}

    protected:

    private:
        string nume,prenume,email,tel;

};

#endif // CURSPOTENTIAL_H
