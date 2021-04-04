#include <iostream>
#include "functions.h"
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
using namespace std;

void newcharacter()
{
    string name;
    cout << "Character name: ";
    cin >> name;
    string newfilename =  name + ".txt";
    ofstream newfile (newfilename);

    int health = 100;
    int hunger = 100;     //shd start from 100 ? it would be better to make reduction
    int mana = 20;
    double crit = 0;
    
    newfile << name << endl;
    newfile << health << endl;
    newfile << hunger << endl;
    newfile << crit << endl;

    newfile << "inventory slots: 10 starting from the next line" << endl;


}