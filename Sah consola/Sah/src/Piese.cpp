#include "Piese.h"
#include "Regina.h"

using namespace std;


Piese::Piese(int aIndex,int bIndex,string culoare):A(aIndex),B(bIndex),Culoare(culoare),Coordonate(Coord(A,B)),PatratMutare(&TablaJoc::tablaJoc[A][B])
{
    this->PatratMutare->eOcupat=true;
    this->PatratMutare->Ocupat=this;
}
string Piese::Coord(int aIndex,int bIndex)
{
    string coordonate;
    switch(aIndex)
    {
    case 0:
        coordonate+="a";
        break;
    case 1:
        coordonate+="b";
        break;
    case 2:
        coordonate+="c";
        break;
    case 3:
        coordonate+="d";
        break;
    case 4:
        coordonate+="e";
        break;
    case 5:
        coordonate+="f";
        break;
    case 6:
        coordonate+="g";
        break;
    case 7:
        coordonate+="h";
        break;
    }
    return coordonate+=to_string(bIndex+1);
}
tuple<int, int>Piese::Indexare(string coordonate)
{
    char aChar=coordonate[0];
    int a=0;
    char bChar=coordonate[1];
    int b=bChar-'1'; //indexul este -1, deoarece in sah indexarea incepe de la 0
    switch(aChar)
    {
    case 'a':
        a=0;
        break;
    case 'b':
        a=1;
        break;
    case 'c':
        a+=2;
        break;
    case 'd':
        a+=3;
        break;
    case 'e':
        a+=4;
        break;
    case 'f':
        a+=5;
        break;
    case 'g':
        a+=6;
        break;
    case 'h':
        a+=7;
        break;
    }
    return make_tuple(a,b);
}
void Piese::Muta(int a,int b)
{
    this->PatratMutare->eOcupat=false;
    this->PatratMutare->Ocupat=nullptr;
    this->B=b;
    this->A=a;
    this->Coordonate=Coord(a,b);
    this->PatratMutare=&TablaJoc::tablaJoc[a][b];
    this->PatratMutare->eOcupat=true;
    this->PatratMutare->Ocupat=this;
    this->Mutat=true;
}
void Piese::Muta(string coordonate)
{
    this->PatratMutare->eOcupat=false;
    this->PatratMutare->Ocupat=nullptr;
    int a=get<0>(Indexare(coordonate));
    int b=get<1>(Indexare(coordonate));
    this->A=a;
    this->B=a;
    this->Coordonate=coordonate;
    this->PatratMutare=&TablaJoc::tablaJoc[a][b];
    this->PatratMutare->eOcupat=true;
    this->PatratMutare->Ocupat=this;
    this->Mutat=true;

}
bool Piese::ValideazaMutare(int aDest,int bDest)
{
    int aDest1=aDest-A;
    int bDest1=bDest-B;
    if(this->Tip=="Tura"&&(aDest1!=0 && bDest1!=0))
    {
        cout<<"Nu se poate muta tura in acest mod.";
        return false;
    }
    else if(this->Tip=="Nebun" &&(abs(aDest1)!=abs(bDest1)))
    {
        cout<<"Nu se poate muta nebunul in acest mod.";
        return false;
    }
    else if(this->Tip=="Rege"&&(abs(aDest1)>1 || abs(bDest1)>1))
    {
        cout<<"Nu se poate muta regele in acest mod.";
        return false;
    }
    if(A+aDest1>7 || B+bDest1>7 || B+bDest1<0 || A+aDest1<0)
    {
        cout<<"Ati depasit tabla de joc!"<<endl;
        return false;
    }
    else if((aDest1!=0 && bDest1!=0)&&(abs(aDest1)!=abs(bDest1)))
    {
        cout<<"Miscare invalida/neliniara."<<endl;
        return false;
    }
    else if(Cauta(aDest1,bDest1)==true){
        return true;
    }
    else
        {
            return false;
        }
}
void Piese::Capturat()
{
    this->PatratMutare->Ocupat=nullptr;
    this->PatratMutare->eOcupat=false;
    this->eCapturat=true;
}
void Piese::Atac(int a,int b)
{
    this->PatratMutare->eOcupat=false;
    this->PatratMutare->Ocupat=nullptr;
    this->B=b;
    this->A=a;
    this->Coordonate=Coord(a,b);
    TablaJoc::tablaJoc[a][b].Ocupat->Capturat();
    this->PatratMutare=&TablaJoc::tablaJoc[a][b];
    this->PatratMutare->eOcupat=true;
    this->PatratMutare->Ocupat=this;
    this->Mutat=true;
}
void Piese::IncearcaMutare(int aDest,int bDest)
{
    if(ValideazaMutare(aDest,bDest)==true)
        TablaJoc::tablaJoc[aDest][bDest].eOcupat ? Atac(aDest,bDest):Muta(aDest,bDest);
}
bool Piese::Cauta(int aDest,int bDest)
{
    int aDest1=aDest-this->A;
    int bDest1=bDest-this->B;
    int aDirectie;
    int bDirectie;
    bool mutaA=false;
    bool mutaB=false;
    if(aDest1!=0)
    {
        aDirectie=aDest1>0 ? +1:-1;
        mutaA=true;
    }
    if(bDest1!=0)
    {
        bDirectie=bDest1 >0 ? +1:-1;
        mutaB=true;
    }
    if(mutaA==true && mutaB==false)
    {
        for(int i=A+aDirectie;i*aDirectie<aDest*aDirectie;i=i+aDirectie)
        {
            if(TablaJoc::tablaJoc[i][B].eOcupat==true)
                return false;
        }
        return true;
    }
    if(mutaA==false && mutaB==true)
    {
        for(int i=B+bDirectie;i*bDirectie<bDest1*bDirectie;i=i+bDirectie)
        {
            if(TablaJoc::tablaJoc[A][i].eOcupat==true)
                return false;
        }
        return true;
    }
    if(mutaA==true && mutaB==true)
    {
        int j=B+A;
        for(int i=A+aDirectie;i*aDirectie<aDest*aDirectie;i=i+aDirectie)
        {
            if(TablaJoc::tablaJoc[i][j].eOcupat==true)
                return false;
            j=j+bDirectie;
        }
        return true;
    }
    return false;
}
