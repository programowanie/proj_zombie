#include "Country.h"
#include <cstdlib>
#include <iostream>

using namespace std;

int Country::humans()
{
    return vectorOfHumans.size();
}

int Country::zombies()
{
    return vectorOfZombies.size();
}

int Country::cure()
{
    return _cure;
}

void Country::changeHumanToZombie(std::vector<Human *>::iterator humanOpponent)
{
    vectorOfHumans.erase(humanOpponent);
    int r=rand()%10+1;
    if(r<=8) vectorOfZombies.push_back(new CommonZombie);
    if(r==9) vectorOfZombies.push_back(new SuicideZombie);
    if(r==10) vectorOfZombies.push_back(new BerserkZombie);
}

Country::Country(unsigned int population, int sl, int ml, int zl)
{
    _cure=10000;
    _humanPower=rand()%11-5;
    _humanAgility=rand()%11-5;
    _environment=rand()%7-3;//od-3 do 3 roznicy w spreadVirus
    _scientists=0; _soldiers=0; _commons=0;
    _scienceLevel=sl;
    _militaryLevel=ml;
    int r, h=population-zl, c=h-sl-ml;
    for(int i=0; i<c; i++)
    {
        vectorOfHumans.push_back(new CommonHuman);
        _commons++;
    }
    for(int i=0; i<sl; i++)
    {
        r=rand()%vectorOfHumans.size();
        vectorOfHumans.insert(vectorOfHumans.begin()+r, new ScienceHuman);
        _scientists++;
    }
    for(int i=0; i<ml; i++)
    {
        r=rand()%vectorOfHumans.size();
        vectorOfHumans.insert(vectorOfHumans.begin()+r, new MilitaryHuman);
        _soldiers++;
    }

    for(int i=0; i<zl; i++)
    {
        int r=rand()%10+1;
        if(r<=8) vectorOfZombies.push_back(new CommonZombie);
        if(r==9) vectorOfZombies.push_back(new SuicideZombie);
        if(r==10) vectorOfZombies.push_back(new BerserkZombie);
    }
}

string Country::description()
{
    return "Vectorofhumans: "+to_string(humans())+"  Vectorofzombies: "+to_string(zombies())+"\n"
        +"Scientists: "+to_string(_scientists)+"  Soldiers: "+to_string(_soldiers)+"  Commons: "+to_string(_commons)+"\n"
        +"Cure progress (0 means ready): "+to_string(_cure)+"\n";
}

string Country::showEveryone()
{
    string text="";
    text+="HUMANS \n";
    std::vector<Human *>::iterator it=vectorOfHumans.begin();
    while(it!=vectorOfHumans.end())
    {
        text+=(*it)->description();
        it++;
    }
    text+="\nZOMBIES \n";
    std::vector<Zombie *>::iterator ite=vectorOfZombies.begin();
    while(ite!=vectorOfZombies.end())
    {
        text+=(*ite)->description();
        ite++;
    }
    return text;
}

void Country::fight(fstream &output, int outputInfo)
{
    std::vector<Human *>::iterator humanOpponent=vectorOfHumans.begin()+rand()%vectorOfHumans.size();
    std::vector<Zombie *>::iterator zombieOpponent=vectorOfZombies.begin()+rand()%vectorOfZombies.size();
    int humanAttack=(*humanOpponent)->attack()+_humanPower;
    int humanDodge=(*humanOpponent)->dodgeChance()+_humanAgility;
    if(outputInfo) output<<"Fight between \n"<<(*humanOpponent)->description()<<"and \n"<<(*zombieOpponent)->description();
    while(1)
    {
        if(rand()%2==0)
        {
            if((*zombieOpponent)->tryAttack() && rand()%100+1<=humanDodge)
            {
                changeHumanToZombie(humanOpponent);
                output<<"Zombie won in first move \n"; if(outputInfo) output<<"\n";
                break;
            }
        }
        if(rand()%100+1<=(*humanOpponent)->attackChance() && !((*humanOpponent)->isDead()))
        {
            (*zombieOpponent)->damage(humanAttack);
            if((*zombieOpponent)->isDead())
            {
                vectorOfZombies.erase(zombieOpponent);
                if((*zombieOpponent)->who()==1)
                {
                    output<<"BOMBED \n";
                    std::vector<Human *>::iterator it=humanOpponent;
                    it-=2; int kills=rand()%4+2;
                    while(it>vectorOfHumans.begin() && it<vectorOfHumans.end() && kills)
                    {
                        changeHumanToZombie(it);
                        it++; kills--;
                    }
                }
                output<<"Human won \n"; if(outputInfo) output<<"\n";
                break;
            }
        }
        if(!((*zombieOpponent)->isDead()) && (*zombieOpponent)->tryAttack() && rand()%100+1>humanDodge)
        {
            changeHumanToZombie(humanOpponent);
            output<<"Zombie won \n"; if(outputInfo) output<<"\n";
            break;
        }
    }
}

void Country::spreadVirus(int i, fstream &output)
{
    int days=_environment+4;
    if(i%(days)==0)
    {
        std::vector<Human *>::iterator ite=vectorOfHumans.begin()+rand()%vectorOfHumans.size();
        changeHumanToZombie(ite);
        output<<"One random human turned to zombie \n";
    }
}

bool Country::searchForCure(fstream &output)
{
    std::vector<int> scientistVector;
    scientistVector.clear();
    std::vector<Human *>::iterator it=vectorOfHumans.begin();
    while(it!=vectorOfHumans.end())
    {
        if((*it)->who()==1) scientistVector.push_back((*it)->intelligence());
        it++;
    }
    unsigned int i=0;
    do
    {
        if(scientistVector.size()!=0 && _cure>0 && rand()%5==0)//25% szans ze zrobiono postep
            _cure-=scientistVector[rand()%scientistVector.size()];
        if(_cure<0) _cure=0;
        i++;
    }while(i<(scientistVector.size()/10));
    output<<"Cure progress: "<<to_string(_cure)<<"\n";
    if(_cure>0) return false;
    else return true;
}

void Country::cureSomeZombies(fstream &output)
{
    int r=rand()%5+5;
    for(int i=0; i<r; i++)//leczenie zombiaków, min 5 naraz (obszarowo rozpylany lek)
    {
        if(vectorOfZombies.size())
        {
            std::vector<Zombie *>::iterator ite=vectorOfZombies.begin()+rand()%vectorOfZombies.size();
            delete *ite;
            vectorOfZombies.erase(ite);
            vectorOfHumans.push_back(new CommonHuman);
        }
    }
    output<<to_string(r)<<" Zombies cured \n";
}

