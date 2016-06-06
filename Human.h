#pragma once
#include <cstdlib>
#include <string>

using namespace std;

class Human
{
    static int _humanCounter;
    int _humanID, _humanHP;
public:
    Human():_humanID(_humanCounter++), _humanHP(100) {}
    int humanID() { return _humanID; }
    int humanHP() { return _humanHP; }
    int isDead() { return _humanHP>0? false:true; }
    void damage(int dmg) { _humanHP-=dmg; }
    virtual int attack()=0;
    virtual int attackChance()=0;
    virtual int dodgeChance()=0;
    virtual int intelligence()=0;
    virtual int who()=0;// 0-Common 1-Scientist 2-Soldier

    virtual string description()=0;
};

class CommonHuman : public Human
{
    int _attack, _attackChance, _dodgeChance;
public:
    CommonHuman():Human(), _attack(rand()%10+30), _attackChance(rand()%10+50), _dodgeChance(rand()%10+50) {}
    int attack() { return _attack; }
    int attackChance() { return _attackChance; }
    int dodgeChance() { return _dodgeChance; }
    int intelligence() { return 0; }//nigdy sie nie wykona
    virtual int who() { return 0; }

    virtual string description();
};

class ScienceHuman : public CommonHuman
{
    int _intelligence;
public:
    ScienceHuman():CommonHuman(), _intelligence(rand()%100+1) {}
    int intelligence() { return _intelligence; }
    virtual int who() { return 1; }

    virtual string description();
};

class MilitaryHuman : public Human
{
    int _attack, _attackChance, _dodgeChance;
public:
    MilitaryHuman():Human(), _attack(rand()%10+50), _attackChance(rand()%10+65), _dodgeChance(rand()%10+65) {}
    int attack() { return _attack; }
    int attackChance() { return _attackChance; }
    int dodgeChance() { return _dodgeChance; }
    int intelligence() { return 0; }//nigdy sie nie wykona
    virtual int who() {return 2; }

    virtual string description();
};
