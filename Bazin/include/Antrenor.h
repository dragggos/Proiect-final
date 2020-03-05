#ifndef ANTRENOR_H
#define ANTRENOR_H
#include <iostream>
#include <vector>
#include "Cursant.h"

using namespace std;

class Antrenor
{
    public:
        Antrenor();
        Antrenor(string,string,short);
        virtual ~Antrenor();
        void CreazaCursant(string, string, short);
        void AfiseazaCursant();
        void AfiseazaCursantpentruSters(short);
        void StergeC(short);
        bool VerificaDispAntrenor();
        string Get_nume_antrenor() {return nume;}
        string Get_prenume_antrenor() {return prenume;}
        short Get_id_antrenor() {return id;}
        short NrCursantiAntrenor();
        Cursant ReturnCursant();
        void MutaCursant(Cursant);


    protected:

    private:
        string nume,prenume;
        short id=0;
        vector<Cursant> vect_cursant;


};

#endif // ANTRENOR_H
