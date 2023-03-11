#include <iostream>
#include <string>
#include<tuple>
#include<vector>
#include<bits/stdc++.h>

#include "Piese.h"
#include "TablaJoc.h"
#include "PatratMutare.h"
#include "PionAlb.h"
#include "PionNegru.h"
#include "Regina.h"
#include "Rege.h"
#include "Tura.h"
#include "Nebun.h"
#include "Cal.h"

using namespace std;

int main()
{
    PionAlb a(0,1);
    PionAlb b(1,1);
    PionAlb c(2,1);
    PionAlb d(3,1);
    PionAlb e(4,1);
    PionAlb f(5,1);
    PionAlb g(6,1);
    PionAlb h(7,1);
    Tura t(0,0,"Alb");
    Cal cl(1,0,"Alb");
    Nebun n(2,0,"Alb");
    Regina q(3,0,"Alb");
    Rege k(4,0,"Alb");
    Nebun n1(5,0,"Alb");
    Cal cl1(6,0,"Alb");
    Tura t1(7,0,"Alb");

    PionNegru A(0,6);
    PionNegru B(1,6);
    PionNegru C(2,6);
    PionNegru D(3,6);
    PionNegru E(4,6);
    PionNegru F(5,6);
    PionNegru G(6,6);
    PionNegru H(7,6);
    Tura T(0,7,"Negru");
    Cal CL(1,7,"Negru");
    Nebun N(2,7,"Negru");
    Regina Q(3,7,"Negru");
    Rege K(4,7,"Negru");
    Nebun N1(5,7,"Negru");
    Cal CL1(6,7,"Negru");
    Tura T1(7,7,"Negru");

    TablaJoc::PrintJoc();
    TablaJoc::StartJoc();

    return 0;
}
