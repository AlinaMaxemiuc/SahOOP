#ifndef PIONNEGRU_H
#define PIONNEGRU_H

#include "Piese.h"

class PionNegru:Piese
{
    public:
        PionNegru(int a,int b);
        bool MutaPion(int aDest,int bDest);
        bool AtacPion(int aDest,int bDest);
        void IncearcaMutare(int aDest,int bDest);
        bool ValideazaMutarePion(int aDest,int bDest);
        bool ValideazaAtacPion(int aDest,int bDest);
};

#endif // PIONNEGRU_H
