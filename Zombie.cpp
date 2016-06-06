#include "Zombie.h"
#include <iostream>

using namespace std;

string CommonZombie::description()
{
    return "Common Zombie nr: "+to_string(zombieID())+"  Health: "+to_string(zombieHP())+"\n"
        +"Attack chance: "+to_string(_attackChance)+"\n";
}

string SuicideZombie::description()
{
    return "Suicide Zombie nr: "+to_string(zombieID())+"  Health: "+to_string(zombieHP())+"\n"
        +"Attack chance: "+to_string(_attackChance)+"\n";
}

string BerserkZombie::description()
{
    return "Berserk Zombie nr: "+to_string(zombieID())+"  Health: "+to_string(zombieHP())+"\n"
        +"Attack chance: "+to_string(_attackChance)+"  Attack count: "+to_string(_attackCount)+"\n";
}

bool CommonZombie::tryAttack()
{
    if(rand()%100+1<=_attackChance) return true;
    else return false;
}

bool SuicideZombie::tryAttack()
{
    if(rand()%100+1<=_attackChance) return true;
    else return false;
}

bool BerserkZombie::tryAttack()
{
    bool atk=false;
    for(int i=0; i<_attackCount; i++)
    {
        if(rand()%100+1<=_attackChance) atk=true;
    }
    return atk;
}
