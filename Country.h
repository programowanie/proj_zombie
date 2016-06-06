#pragma once
#include "Human.h"
#include "Zombie.h"
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Country
{
    std::vector<Human *> vectorOfHumans;
    std::vector<Zombie *> vectorOfZombies;
    int _humanPower, _humanAgility, _scienceLevel, _militaryLevel, _environment;
    int _scientists, _soldiers, _commons;
    int _cure;
public:
    Country(unsigned int population, int sl, int ml, int zl);
    int humans();
    int zombies();
    int cure();
    void changeHumanToZombie(std::vector<Human *>::iterator humanOpponent);
    void fight(fstream &output, int outputInfo);
    void spreadVirus(int i, fstream &output);
    bool searchForCure(fstream &output);
    void cureSomeZombies(fstream &output);

    string description();
    string showEveryone();
};
