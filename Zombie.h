#pragma once
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class Zombie
{
    static int _zombieCounter;
    int _zombieID, _zombieHP;
public:
    Zombie():_zombieID(_zombieCounter++), _zombieHP(100) {}
    int zombieID() { return _zombieID; }
    int zombieHP() { return _zombieHP; }
    void damage(int dmg) { _zombieHP-=dmg; }
    bool isDead() { return _zombieHP>0? false : true; }
    virtual int attackChance()=0;
    virtual int who()=0;//0-CommonZombie 1-SuicideZombie 2-BerserkZombie
    virtual bool tryAttack()=0;

    virtual string description()=0;
};

class CommonZombie : public Zombie
{
    int _attackChance;
public:
    CommonZombie():Zombie(), _attackChance(rand()%20+10) {}
    int attackChance() { return _attackChance; }
    virtual int who() { return 0; }
    virtual bool tryAttack();

    virtual string description();
};

class SuicideZombie : public Zombie
{
    int _attackChance;
public:
    SuicideZombie():Zombie(), _attackChance(rand()%4+1) {}
    int attackChance() { return _attackChance; }
    virtual int who() { return 1; }
    virtual bool tryAttack();

    virtual string description();
};

class BerserkZombie : public Zombie
{
    int _attackChance, _attackCount, _resistChance;
public:
    BerserkZombie():Zombie(), _attackChance(rand()%20+10), _attackCount(rand()%3+1), _resistChance(rand()%10+15) {}
    int attackChance() { return _attackChance; }
    int attackCount() { return _attackCount; }
    virtual int who() { return 2; }
    virtual bool tryAttack();

    virtual string description();
};
