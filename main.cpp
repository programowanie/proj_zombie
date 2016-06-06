#include "Zombie.h"
#include "Human.h"
#include "Country.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <fstream>

using namespace std;

int Zombie::_zombieCounter=1;
int Human::_humanCounter=1;

std::vector<int> numbers;
void simulateCountry(int population, int scientists, int soldiers, int zombies, int outputInfo);
void fileLoad();
    fstream output;

int main(int argc, char const *argv[])
{
    int ii=atoi(argv[1]), info=atoi(argv[2]);
    srand(time(NULL));
    fileLoad();
    output.open("output.txt", ios::out | ios::trunc);
    int index=0;
    for(int i=0; i<ii; i++)
    {
        simulateCountry(numbers[index], numbers[index+1], numbers[index+2], numbers[index+3], info);
        index+=4;
    }

}

void simulateCountry(int population, int scientists, int soldiers, int zombies, int outputInfo)
{
    Country c(population, scientists, soldiers, zombies);
    cout<<c.description();
    output<<"NEW COUNTRY NEW SIMULATION \n"<<c.description();
    int i=0;
    while(c.humans()>0 && c.zombies()>0)
    {
        i++;
        c.fight(output, outputInfo);
        if(c.searchForCure(output))
        {
            if(rand()%2==0) c.cureSomeZombies(output);//50% szans na leczenie
        }
        if(c.humans()) c.spreadVirus(i, output);
    }
    string text="";
    text="After "+to_string(i)+" days: \n"+to_string(c.humans())+" Humans, "+to_string(c.zombies())+" Zombies. \n"
        +"Cure progress was: "+to_string(c.cure())+" (0 means ready) \n"
        +"------------------------------------------------------------------------------------------------------------ \n";
    cout<<text;
    output<<text;
}

void fileLoad()
{
    fstream file("input.txt", ios::in);
    int n;
    while(file >> n)
    {
        numbers.push_back(n);
    }
}
