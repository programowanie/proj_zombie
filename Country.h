#pragma once
#include "Human.h"
#include "Zombie.h"
#include <vector>

using namespace std;

class Country
{
    std::vector<Human *> vectorofhumans;
    std::vector<Zombie *> vectorofzombies;
    int _humanpower, _humanagility, _sciencelevel, _militarylevel, _environment;
    int _scientists, _soldiers, _commons;
    int _cure;
public:
    Country(unsigned int population, int sl, int ml, int zl);
    int humans();
    int zombies();
    int cure();
    void changehumantozombie(std::vector<Human *>::iterator humanopponent);
    void fight();
    void spreadvirus(int i);
    bool searchforcure();
    void curesomezombies();

    void description();
    void showeveryone();
};
