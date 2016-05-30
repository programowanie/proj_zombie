#include "Zombie.h"
#include "Human.h"
#include "Country.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <fstream>

using namespace std;

int Zombie::_zombiecounter=1;
int Human::_humancounter=1;

std::vector<int> numbers;
void simulatecountry(int population, int scientists, int soldiers, int zombies);
void fileload();

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int n=atoi(argv[1]);
    fileload();
    int index=0;
    for(int i=0; i<n; i++)
    {
        simulatecountry(numbers[index], numbers[index+1], numbers[index+2], numbers[index+3]);
        index+=4;
    }

}

void simulatecountry(int population, int scientists, int soldiers, int zombies)
{
    Country c(population, scientists, soldiers, zombies);
    c.description();
    int i=0;
    while(c.humans()>0 && c.zombies()>0)
    {
        i++;
        c.fight();
        if(c.searchforcure())
        {
            if(rand()%2==0) c.curesomezombies();//50% szans na leczenie
        }
        if(c.humans()) c.spreadvirus(i);
    }
    cout<<"After "<<i<<" days left:"<<endl
        <<c.humans()<<" Humans,  "<<c.zombies()<<" Zombies."<<endl
        <<"Cure progress was: "<<c.cure()<<"  (0 means ready)"<<endl
        <<"------------------------------------------------------"<<endl;
}

void fileload()
{
    fstream file("input.txt", ios::in);
    int n;
    while(file >> n)
    {
        numbers.push_back(n);
    }
}
