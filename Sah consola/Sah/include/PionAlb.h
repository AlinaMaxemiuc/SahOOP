#ifndef PIONALB_H
#define PIONALB_H

#include "Piese.h"

class PionAlb:Piese
{
    public:
        PionAlb(int a,int b);
        void MutaPion(int aDest,int bDest);
        void AtacPion(int aDest,int bDest);
        void IncearcaMutare(int aDest,int bDest);
        bool ValideazaAtacPion(int aDest,int bDest);
        bool ValideazaMutarePion(int aDest,int bDest);
};

#endif // PIONALB_H
