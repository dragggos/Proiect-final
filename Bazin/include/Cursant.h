#ifndef CURSANT_H
#define CURSANT_H
#include <iostream>

using namespace std;

class Cursant
{
    public:
        Cursant();
        Cursant(string,string, short);
        virtual ~Cursant();
        string Get_nume_cursant() {return nume;}
        string Get_prenume_cursant() {return prenume;}
        short Get_categorie_cursant() {return categorie;}


    protected:

    private:
        string nume, prenume;
        short categorie;
};

#endif // CURSANT_H
