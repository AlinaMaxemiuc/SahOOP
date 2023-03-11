#ifndef TABLAJOC_H
#define TABLAJOC_H

#include <iostream>
//#include "PatratMutare.h"
#include "Piese.h"

class PatratMutare;
using namespace std;

class TablaJoc
{
    public:
        static PatratMutare tablaJoc[8][8];
        TablaJoc();
        static void PrintJoc();
        static void StartJoc();
};

#endif // TABLAJOC_H
