#include "Human.h"
#include <iostream>

using namespace std;

void CommonHuman::description()
{
    cout<<"Common Human nr: "<<humanID()<<"  Health: "<<humanHP()<<endl
        <<"Attack: "<<_attack<<"  Attack chance: "<<_attackchance<<"  Dodge chance: "<<_dodgechance<<endl;
}

void ScienceHuman::description()
{
    cout<<"Science Human nr: "<<humanID()<<"  Health: "<<humanHP()<<endl
        <<"Intelligence: "<<_intelligence<<endl;
}

void MilitaryHuman::description()
{
    cout<<"Military Human nr: "<<humanID()<<"  Health: "<<humanHP()<<endl
        <<"Attack: "<<_attack<<"  Attack chance: "<<_attackchance<<"  Dodge chance: "<<_dodgechance<<endl;
}
