#pragma once
#include <cstdlib>

using namespace std;

class Human
{
    static int _humancounter;
    int _humanID, _humanHP;
public:
    Human():_humanID(_humancounter++), _humanHP(100) {}
    int humanID() { return _humanID; }
    int humanHP() { return _humanHP; }
    int isdead() { return _humanHP>0? false:true; }
    void damage(int dmg) { _humanHP-=dmg; }
    virtual int attack()=0;
    virtual int attackchance()=0;
    virtual int dodgechance()=0;
    virtual int intelligence()=0;
    virtual int who()=0;// 0-Common 1-Scientist 2-Soldier

    virtual void description()=0;
};

class CommonHuman : public Human
{
    int _attack, _attackchance, _dodgechance;
public:
    CommonHuman():Human(), _attack(rand()%10+30), _attackchance(rand()%10+50), _dodgechance(rand()%10+50) {}
    int attack() { return _attack; }
    int attackchance() { return _attackchance; }
    int dodgechance() { return _dodgechance; }
    int intelligence() { return 0; }//nigdy sie nie wykona
    virtual int who() { return 0; }

    virtual void description();
};

class ScienceHuman : public CommonHuman
{
    int _intelligence;
public:
    ScienceHuman():CommonHuman(), _intelligence(rand()%100+1) {}
    int intelligence() { return _intelligence; }
    virtual int who() { return 1; }

    virtual void description();
};

class MilitaryHuman : public Human
{
    int _attack, _attackchance, _dodgechance;
public:
    MilitaryHuman():Human(), _attack(rand()%10+50), _attackchance(rand()%10+65), _dodgechance(rand()%10+65) {}
    int attack() { return _attack; }
    int attackchance() { return _attackchance; }
    int dodgechance() { return _dodgechance; }
    int intelligence() { return 0; }//nigdy sie nie wykona
    virtual int who() {return 2; }

    virtual void description();
};
