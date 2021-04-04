#ifndef FUNCTIONS
#define FUNCTIONS

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <ctime>
#include <vector>

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
    int attack;
    int defense;
    int speed;
};

struct infostruct //use this struct tempalte to pass game status into / out of save file
{
    string name;
    int seed;
    int turn; // the number of iterations of rng the character is currently in
    int health;
    int hunger;
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
int rng ();

#endif