#include "functions.h"


infostruct readsavefile()
{
    string playername;
    cout << "Enter character name: ";
    cin >> playername;
    string filename = playername + ".txt";
    ifstream fin;
	fin.open(filename);
    if ( fin.fail() )
    {
        exit(1);
    }

    int linenumber = 0;
    string line;
    
    string getname;
    int getseed;
    int getturn;
    int gethealth;
    int gethunger;
    int getmana;
    double getcrit;
    while ( getline(fin, line) )
    {
        if (linenumber == 0)
            getname = line;
        if (linenumber == 2)
            getseed = stoi(line);
        if (linenumber == 2)
            getturn = stoi(line);
        if (linenumber == 3)
            gethealth = stoi(line);
        if (linenumber == 4)
            gethunger = stoi(line);
        if (linenumber == 5)
            getmana = stoi(line);
        if (linenumber == 6)
            getcrit = stod(line);
        linenumber++;
    }

    infostruct returnthis;
    returnthis.name = getname;
    returnthis.seed = getseed;
    returnthis.turn = getturn; // the number of iterations of rng the character is currently in
    returnthis.health = gethealth;
    returnthis.hunger = gethunger;
    returnthis.mana = getmana;
    returnthis.crit = getcrit;


    fin.close();

    return returnthis;
}