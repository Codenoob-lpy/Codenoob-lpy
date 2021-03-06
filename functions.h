#ifndef FUNCTIONS
#define FUNCTIONS

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <ctime>
#include <vector>
#include <random>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;




struct item
{
    string name;
    int amount;

};

struct weapon
{
    string name;
    int damage;
    string effect;
};

struct armor
{
    string name;
    string type;
    int defense;
    string effect;
};

struct monster
{
    string name;
    string type;
    int attack;
    int defense;
    int speed;
    int health;
};

struct infostruct //use this struct tempalte to pass game status into / out of save file
{
    string name;
    int seed;
    int turn; // the number of iterations of rng the character is currently in
    int health;
    int coins;
    int maxhealth;
    double crit;
    double level;
    double speed;
    weapon currentweapon;
    armor head;
    armor chest;
    armor leg;
    armor boots;
};
//add components here
void welcome();
void newcharacter();
infostruct readsavefile();
void savegame(infostruct character);
int RNG (int seed, int turn);
monster monster_spawner(int turn, int rngoutput);
weapon randomweapon(int rngoutput, int turn, int level);
armor randomarmor(int rngoutput, int turn, int level);
infostruct event(int rng, infostruct character);
void genericinput(string input, infostruct character);
void status(infostruct character);
infostruct blacksmith (infostruct character, int rng);

#endif