#ifndef CAL_H
#define CAL_H

#include "Piese.h"

class Cal:Piese
{
    public:
        Cal(int a,int b,string culoare);
        void MutaCal(int aDest,int bDest);
        void AtacCal(int aDest,int bDest);
        bool ValideazaMutareCal(int aDest,int bDest);
        bool ValideazaAtacCal(int aDest,int bDest);
        void IncearcaMutare(int aDest,int bDest);
};

#endif // CAL_H
