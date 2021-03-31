#ifndef FUNCTIONS
#define FUNCTIONS

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
using namespace std;


struct infostruct //use this struct tempalte to pass game status into / out of save file
{
    string name;
    int seed;
    int turn; // the number of iterations of rng the character is currently in
    int health;
    int hunger;
    int mana;
    double crit;
};
//add components here
void welcome();
void newcharacter();
infostruct readsavefile();

#endif