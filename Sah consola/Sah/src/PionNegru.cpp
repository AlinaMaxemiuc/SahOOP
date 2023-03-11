#include "PionNegru.h"


PionNegru::PionNegru(int a,int b):Piese(a,b,"Negru")
{
    this->Simbol="P";
    this->Tip="Pion Negru";
}
bool PionNegru::MutaPion(int aDest, int bDest)
{
    if(ValideazaMutare(aDest,bDest)==true && ValideazaMutarePion(aDest,bDest)==true)
      {
          Muta(aDest,bDest);
          return true;
      }
    return false;
}
bool PionNegru::AtacPion(int aDest,int bDest)
{
    if(ValideazaMutare(aDest,bDest)==true && ValideazaAtacPion(aDest,bDest)==true)
        {
            Atac(aDest,bDest);
            return true;
        }
    return false;
}
bool PionNegru::ValideazaMutarePion(int aDest,int bDest)
{
    int aDest1=aDest-A;
    int bDest1=bDest-B;
    if(bDest1==-2 && aDest1==0 && Mutat==false){
        return true;
    }
    else if(bDest1==-1 && aDest1==0){
        return true;
    }
    return false;
}
bool PionNegru::ValideazaAtacPion(int aDest,int bDest)
{
    int aDest1=aDest-A;
    int bDest1=bDest-B;
    if(bDest1==-1 && aDest1==-1 && Mutat==false){
        return true;
    }
    else if(bDest1==-1 && aDest1==+1){
        return true;
    }
    return false;
}
void PionNegru::IncearcaMutare(int aDest,int bDest)
{
    if(MutaPion(aDest,bDest)){
        return ;
    }
    else if(AtacPion(aDest,bDest)){
        return ;
    }
    else
    {
        cout<<"Nu puteti muta in acest fel pionul."<<endl;
    }
}
