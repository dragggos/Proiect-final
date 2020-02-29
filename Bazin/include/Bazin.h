#ifndef BAZIN_H
#define BAZIN_H
#include <vector>
#include "Antrenor.h"
#include "Cursant.h"
#include "CursantPotential.h"

using namespace std;

class Bazin
{
    public:
        Bazin();
        virtual ~Bazin();
        void AdaugaAntrenor();
        void AdaugaCursant();
        void AfiseazaCursant();
        void StergeAntrenor();
        void VizCursantiPotentiali();



    protected:

    private:
        vector<Antrenor> vect_antrenor;
        vector<CursantPotential> vect_cursant_potential;


};

#endif // BAZIN_H
