#include "Human.h"
#include <iostream>

using namespace std;

string CommonHuman::description()
{
	return "Common Human nr: "+to_string(humanID())+"  Health: "+to_string(humanHP())+"\n"
        +"Attack: "+to_string(_attack)+"  Attack chance: "+to_string(_attackChance)+"  Dodge chance: "+to_string(_dodgeChance)+"\n";
}

string ScienceHuman::description()
{
	return "Science Human nr: "+to_string(humanID())+"  Health: "+to_string(humanHP())+"\n"
        +"Intelligence: "+to_string(_intelligence)+"\n";
}

string MilitaryHuman::description()
{
	return "Military Human nr: "+to_string(humanID())+"  Health: "+to_string(humanHP())+"\n"
        +"Attack: "+to_string(_attack)+"  Attack chance: "+to_string(_attackChance)+"  Dodge chance: "+to_string(_dodgeChance)+"\n";
}
