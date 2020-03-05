#ifndef BAZIN_H
#define BAZIN_H
#include <vector>
#include "Antrenor.h"
#include "Cursant.h"
#include "CursPotential.h"

using namespace std;

class Bazin
{
    public:
        Bazin();
        virtual ~Bazin();
        void Meniu();
        void AdaugaAntrenor();
        void StergeAntrenor();
        void AfiseazaCursantiAntrenor();
        void AdaugaCursant();
        void StergeCursant();
        void VizCursantiPotentiali();



    protected:

    private:
        vector<Antrenor> vect_antrenor;
        vector<CursPotential> vect_cursant_potential;


};

#endif // BAZIN_H
