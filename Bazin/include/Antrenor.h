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
        void AdaugaCursant();
        void AfiseazaCursant();

    protected:

    private:
        string nume_ant,prenume_ant;
        short id=0;
        vector<Cursant> vect_cursant;
};

#endif // ANTRENOR_H
