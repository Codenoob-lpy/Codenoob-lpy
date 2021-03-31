#include "functions.h"


void readsavefile(string playername)
{
    string filename = playername + ".txt";
    ifstream fin;
	fin.open(filename);
    if ( fin.fail() )
    {
        exit(1);
    }

    int linenumber = 0;
    string line;
    while ( getline(fin, line) )
    {
        if (linenumber == 0)
            string name = line;
        if (linenumber == 2)
            int seed = stoi(line);
        if (linenumber == 2)
            int turn = stoi(line);
        if (linenumber == 3)
            int health = stoi(line);
        if (linenumber == 4)
            int hunger = stoi(line);
        if (linenumber == 5)
            int mana = stoi(line);
        if (linenumber == 6)
            double crit = stoi(line);
        linenumber++;
    }


    fin.close();
    
}