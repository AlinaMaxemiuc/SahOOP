#include "Cal.h"

Cal::Cal(int a,int b,string culoare):Piese(a,b,culoare)
{
    this->Simbol="C";
    this->Tip="Cal";
}
bool Cal::ValideazaMutareCal(int aDest,int bDest)
{
    int aDest1=aDest-A;
    int bDest1=bDest-B;
    if(A+aDest1>7 || B+bDest1>7 || B+bDest1<0 || A+aDest1<0)
    {
        cout<<"Ati depasit tabla de joc!"<<endl;
        return false;
    }
    else if((abs(aDest1)!=2 || abs(bDest1)!=1) && (abs(bDest1)!=2|| abs(aDest1)!=1))
    {
        cout<<"Calul nu poate fi mutat in acest fel."<<endl;
        return false;
    }
    else
    {
        return true;
    }
}
void Cal::MutaCal(int aDest,int bDest)
{
    if(ValideazaMutareCal(aDest,bDest)==true)
        TablaJoc::tablaJoc[aDest][bDest].eOcupat ? Atac(aDest,bDest):Muta(aDest,bDest);
}
void Cal::IncearcaMutare(int aDest,int bDest)
{
    MutaCal(aDest,bDest);
}
