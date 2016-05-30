#include "Country.h"
#include <cstdlib>
#include <iostream>

using namespace std;

int Country::humans()
{
    return vectorofhumans.size();
}

int Country::zombies()
{
    return vectorofzombies.size();
}

int Country::cure()
{
    return _cure;
}

void Country::changehumantozombie(std::vector<Human *>::iterator humanopponent)
{
    //delete (*humanopponent);
    vectorofhumans.erase(humanopponent);
    int r=rand()%10+1;
    if(r<=8) vectorofzombies.push_back(new CommonZombie);
    if(r==9) vectorofzombies.push_back(new SuicideZombie);
    if(r==10) vectorofzombies.push_back(new BerserkZombie);
}

Country::Country(unsigned int population, int sl, int ml, int zl)
{
    _cure=10000;
    _humanpower=rand()%11-5;
    _humanagility=rand()%11-5;
    _environment=rand()%7-3;//od-3 do 3 roznicy w spreadvirus
    _scientists=0; _soldiers=0; _commons=0;
    _sciencelevel=sl;
    _militarylevel=ml;
    int r, h=population-zl, c=h-sl-ml;
    for(int i=0; i<c; i++)
    {
        vectorofhumans.push_back(new CommonHuman);
        _commons++;
    }
    for(int i=0; i<sl; i++)
    {
        r=rand()%vectorofhumans.size();
        vectorofhumans.insert(vectorofhumans.begin()+r, new ScienceHuman);
        _scientists++;
    }
    for(int i=0; i<ml; i++)
    {
        r=rand()%vectorofhumans.size();
        vectorofhumans.insert(vectorofhumans.begin()+r, new MilitaryHuman);
        _soldiers++;
    }

    for(int i=0; i<zl; i++)
    {
        int r=rand()%10+1;
        if(r<=8) vectorofzombies.push_back(new CommonZombie);
        if(r==9) vectorofzombies.push_back(new SuicideZombie);
        if(r==10) vectorofzombies.push_back(new BerserkZombie);
    }
}

void Country::description()
{
    cout<<"Vectorofhumans: "<<humans()<<"  Vectorofzombies: "<<zombies()<<endl
        <<"Scientists: "<<_scientists<<"  Soldiers: "<<_soldiers<<"  Commons: "<<_commons<<endl
        <<"Cure progress (0 means ready): "<<_cure<<endl;
}

void Country::showeveryone()
{
    cout<<"HUMANS"<<endl;
    std::vector<Human *>::iterator it=vectorofhumans.begin();
    while(it!=vectorofhumans.end())
    {
        (*it)->description();
        it++;
    }
    cout<<endl<<"ZOMBIES"<<endl;
    std::vector<Zombie *>::iterator ite=vectorofzombies.begin();
    while(ite!=vectorofzombies.end())
    {
        (*ite)->description();
        ite++;
    }
}

void Country::fight()
{
    std::vector<Human *>::iterator humanopponent=vectorofhumans.begin()+rand()%vectorofhumans.size();
    std::vector<Zombie *>::iterator zombieopponent=vectorofzombies.begin()+rand()%vectorofzombies.size();
    int humanattack=(*humanopponent)->attack()+_humanpower;
    int humandodge=(*humanopponent)->dodgechance()+_humanagility;
    while(1)
    {
        if(rand()%2==0)
        {
            if((*zombieopponent)->tryattack() && rand()%100+1<=humandodge)
            {
                changehumantozombie(humanopponent);
                //cout<<"Zombie won in first move"<<endl;
                break;
            }
        }
        if(rand()%100+1<=(*humanopponent)->attackchance() && !((*humanopponent)->isdead()))
        {
            (*zombieopponent)->damage(humanattack);
            if((*zombieopponent)->isdead())
            {
                //delete (*zombieopponent);
                vectorofzombies.erase(zombieopponent);
                if((*zombieopponent)->who()==1)
                {
                    //cout<<"BOMBER"<<endl;
                    std::vector<Human *>::iterator it=humanopponent;
                    it-=2; int kills=rand()%4+2;
                    while(it>vectorofhumans.begin() && it<vectorofhumans.end() && kills)
                    {
                        changehumantozombie(it);
                        it++; kills--;
                    }
                }
                //cout<<"Human won"<<endl;
                break;
            }
        }
        if(!((*zombieopponent)->isdead()) && (*zombieopponent)->tryattack() && rand()%100+1>humandodge)
        {
            changehumantozombie(humanopponent);
            //cout<<"Zombie won"<<endl;
            break;
        }
    }
}

void Country::spreadvirus(int i)
{
    int days=_environment+4;
    if(i%(days)==0)
    {
        std::vector<Human *>::iterator ite=vectorofhumans.begin()+rand()%vectorofhumans.size();
        changehumantozombie(ite);
    }
}

bool Country::searchforcure()
{
    std::vector<int> scientistsvector;
    scientistsvector.clear();
    std::vector<Human *>::iterator it=vectorofhumans.begin();
    while(it!=vectorofhumans.end())
    {
        if((*it)->who()==1) scientistsvector.push_back((*it)->intelligence());
        it++;
    }
    unsigned int i=0;
    do
    {
        if(scientistsvector.size()!=0 && _cure>0 && rand()%5==0)//25% szans ze zrobiono postep
            _cure-=scientistsvector[rand()%scientistsvector.size()];
        if(_cure<0) _cure=0;
        i++;
    }while(i<(scientistsvector.size()/10));
    if(_cure>0) return false;
    else return true;
}

void Country::curesomezombies()
{
    for(int i=0; i<rand()%5+5; i++)//leczenie zombiaków, min 5 naraz (obszarowo rozpylany lek)
    {
        if(vectorofzombies.size())
        {
            std::vector<Zombie *>::iterator ite=vectorofzombies.begin()+rand()%vectorofzombies.size();
            delete *ite;
            vectorofzombies.erase(ite);
            vectorofhumans.push_back(new CommonHuman);
        }
    }
}

