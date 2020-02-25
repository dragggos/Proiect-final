#ifndef BAZIN_H
#define BAZIN_H
#include <vector>
#include "Antrenor.h"
#include "Cursant.h"

using namespace std;

class Bazin
{
    public:
        Bazin();
        virtual ~Bazin();
        void AdaugaAntrenor();
        void AfiseazaCursantiAntrenor();


    protected:

    private:
        vector<Antrenor> vect_antrenor;


};

#endif // BAZIN_H
