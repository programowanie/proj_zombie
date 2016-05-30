#include "Zombie.h"
#include <iostream>

using namespace std;

void CommonZombie::description()
{
    cout<<"Common Zombie nr: "<<zombieID()<<"  Health: "<<zombieHP()<<endl
        <<"Attack chance: "<<_attackchance<<endl;
}

void SuicideZombie::description()
{
    cout<<"Suicide Zombie nr: "<<zombieID()<<"  Health: "<<zombieHP()<<endl
        <<"Attack chance: "<<_attackchance<<endl;
}

void BerserkZombie::description()
{
    cout<<"Berserk Zombie nr: "<<zombieID()<<"  Health: "<<zombieHP()<<endl
        <<"Attack chance: "<<_attackchance<<"  Attack count: "<<_attackcount<<"  Resist chance: "<<_resistchance<<endl;
}

bool CommonZombie::tryattack()
{
    if(rand()%100+1<=_attackchance) return true;
    else return false;
}

bool SuicideZombie::tryattack()
{
    if(rand()%100+1<=_attackchance) return true;
    else return false;
}

bool BerserkZombie::tryattack()
{
    bool atk=false;
    for(int i=0; i<_attackcount; i++)
    {
        if(rand()%100+1<=_attackchance) atk=true;
    }
    return atk;
}
