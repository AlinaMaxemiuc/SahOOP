#ifndef PATRATMUTARE_H
#define PATRATMUTARE_H

#include <string>
#include "Piese.h"
#include "TablaJoc.h"

class Piese;

using namespace std;

class PatratMutare
{
    public:
        PatratMutare();
        virtual ~PatratMutare();
        string coordonate;
        int A;
        int B;
        Piese* Ocupat;
        bool eOcupat=false;
};

#endif // PATRATMUTARE_H
