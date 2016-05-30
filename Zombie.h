#pragma once
#include <cstdlib>
#include <iostream>

using namespace std;

class Zombie
{
    static int _zombiecounter;
    int _zombieID, _zombieHP;
public:
    Zombie():_zombieID(_zombiecounter++), _zombieHP(100) {}
    int zombieID() { return _zombieID; }
    int zombieHP() { return _zombieHP; }
    void damage(int dmg) { _zombieHP-=dmg; }
    bool isdead() { return _zombieHP>0? false : true; }
    virtual int attackchance()=0;
    virtual int who()=0;//0-CommonZombie 1-SuicideZombie 2-BerserkZombie
    virtual bool tryattack()=0;

    virtual void description()=0;
};

class CommonZombie : public Zombie
{
    int _attackchance;
public:
    CommonZombie():Zombie(), _attackchance(rand()%20+10) {}
    int attackchance() { return _attackchance; }
    virtual int who() { return 0; }
    virtual bool tryattack();

    virtual void description();
};

class SuicideZombie : public Zombie
{
    int _attackchance;
public:
    SuicideZombie():Zombie(), _attackchance(rand()%4+1) {}
    int attackchance() { return _attackchance; }
    virtual int who() { return 1; }
    virtual bool tryattack();

    virtual void description();
};

class BerserkZombie : public Zombie
{
    int _attackchance, _attackcount, _resistchance;
public:
    BerserkZombie():Zombie(), _attackchance(rand()%20+10), _attackcount(rand()%3+1), _resistchance(rand()%10+15) {}
    int attackchance() { return _attackchance; }
    int attackcount() { return _attackcount; }
    virtual int who() { return 2; }
    virtual bool tryattack();

    virtual void description();
};
