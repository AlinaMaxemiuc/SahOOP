#include "PionAlb.h"

//a reprezinta pozitia initiala si b pozitia pe care mutam piesa
PionAlb::PionAlb(int a,int b):Piese(a,b,"Alb")
{
    this->Simbol="p";
    this->Tip="Pion Alb";
}
void PionAlb::MutaPion(int aDest, int bDest)
{
    if(ValideazaMutare(aDest,bDest)==true && ValideazaMutarePion(aDest,bDest)==true)
        Muta(aDest,bDest);
}
void PionAlb::AtacPion(int aDest,int bDest)
{
    if(ValideazaMutare(aDest,bDest)==true && ValideazaAtacPion(aDest,bDest)==true)
        Atac(aDest,bDest);
}
bool PionAlb::ValideazaMutarePion(int aDest,int bDest)
{
    int aDest1=aDest-A;
    int bDest1=bDest-B;
    if(bDest1==2 && aDest1==0 && Mutat==false){
        return true;
    }
    else if(bDest1==1 && aDest1==0){
        return true;
    }
    cout<<"Nu puteti muta in acest fel pionul."<<endl;
    return false;
}
bool PionAlb::ValideazaAtacPion(int aDest,int bDest)
{
    int aDest1=aDest-A;
    int bDest1=bDest-B;
    if(bDest1==1 && aDest1==-1 && Mutat==false){
        return true;
    }
    else if(bDest1==1 && aDest1==+1){
        return true;
    }
    cout<<"Nu puteti muta in acest fel pionul."<<endl;
    return false;
}
void PionAlb::IncearcaMutare(int aDest,int bDest)
{
    MutaPion(aDest,bDest);
    AtacPion(aDest,bDest);
}
