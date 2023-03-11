#ifndef PIESE_H
#define PIESE_H

#include "TablaJoc.h"
#include "PatratMutare.h"
#include <string>
#include <tuple>

using namespace std;

class Piese
{
    public:
        bool Mutat=false;
        int B;
        int A;
        void Capturat();
        bool eCapturat=false;
        bool ValideazaAtac(int aDest,int bDest);
        string Coordonate;
        string Simbol ="U";
        string Tip="U";
        string Culoare;
        PatratMutare* PatratMutare;
        Piese(int aIndex,int bIndex,string culoare);
        void Muta(int a,int b);
        void Atac(int a,int b);
        static string Coord(int aIndex,int bIndex);
        static tuple<int,int>Indexare(string coordonate);
        void Muta(string coordonate);
        virtual void IncearcaMutare(int a,int b);
        bool Cauta(int aDest,int bDest);
        bool ValideazaMutare(int aDest, int bDest);
};

#endif // PIESE_H
