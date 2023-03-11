#include "TablaJoc.h"

#include "PionAlb.h"
#include "PionNegru.h"
#include "Regina.h"
#include "Rege.h"
#include "Tura.h"
#include "Nebun.h"
#include "Cal.h"

using namespace std;

PatratMutare TablaJoc::tablaJoc[8][8];

TablaJoc::TablaJoc()
{
    for(int a=0; a<8; a++)
    {
        for(int b=0; b<8; b++)
        {
            tablaJoc[a][b].A=a;
            tablaJoc[a][b].B=b;
            tablaJoc[a][b].coordonate=Piese::Coord(a,b);
        }
    }
}
void TablaJoc::PrintJoc()
{
    for(int b=7; b>-1; b--)
    {
        cout<<b+1<<"|";
        for(int a=0; a<8; a++)
        {
            PatratMutare patratMutare=tablaJoc[a][b];
            patratMutare.eOcupat ? cout<<patratMutare.Ocupat->Simbol<<"|":cout<<" "<<"|";
        }
        cout<<endl;
    }
    cout<<" |a|b|c|d|e|f|g|h|"<<endl;
}
void TablaJoc::StartJoc()
{
    string coordi;
    while(coordi!="q")
    {
        cout<<"\nObservatie:    Daca doriti sa iesiti din program tastati q la ambele cerinte ce se afiseaza."<<endl;
        cout<<"\nSelecteaza piesa (de  forma: a2): "<<endl;
        cin>>coordi;
        auto indexari=Piese::Indexare(coordi);
        Piese* piese=TablaJoc::tablaJoc[get<0>(indexari)][get<1>(indexari)].Ocupat;
        cout<<"Introduceti o miscare (de forma: a4): "<<endl;
        cin>>coordi;
        indexari=Piese::Indexare(coordi);
        if(piese->Tip=="Regina")
            piese->IncearcaMutare(get<0>(indexari),get<1>(indexari));
        else if(piese->Tip=="Tura")
                piese->IncearcaMutare(get<0>(indexari),get<1>(indexari));
        else if(piese->Tip=="Nebun")
                piese->IncearcaMutare(get<0>(indexari),get<1>(indexari));
        else if(piese->Tip=="Rege")
                piese->IncearcaMutare(get<0>(indexari),get<1>(indexari));
        else if(piese->Tip=="Cal")
                piese->IncearcaMutare(get<0>(indexari),get<1>(indexari));
        else if(piese->Tip=="Pion Alb")
                piese->IncearcaMutare(get<0>(indexari),get<1>(indexari));
        else if(piese->Tip=="Pion Negru")
                piese->IncearcaMutare(get<0>(indexari),get<1>(indexari));
        PrintJoc();
    }
}
