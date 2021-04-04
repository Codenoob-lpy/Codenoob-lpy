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
    int getmaxhealth;
    double getcrit;
    double getlevel;
    double getspeed;
    weapon getweapon;
    armor gethead;
    armor getchest;
    armor getleg;
    armor getboots;
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
            getmaxhealth = stoi(line);
        if (linenumber == 6)
            getcrit = stod(line);
        if (linenumber == 7)
            getlevel = stod(line);
        if (linenumber == 8)
            getspeed = stod(line);
        if (linenumber == 9)
        {
            istringstream s(line);
            string temp;
            for (int i = 0; i <3; i++)
            {
                s >> temp;
                if (i == 0)
                    getweapon.name = temp;
                if (i == 1)
                    getweapon.damage = stoi(temp);
                if (i == 2)
                    getweapon.effect = temp;
            }
        }
        if (linenumber == 10)
        {
            if (!line.empty())
            {
                istringstream s(line);
                string temp;
                for (int i = 0; i <4; i++)
                {
                    s >> temp;
                    if (i == 0)
                        gethead.name = temp;
                    if (i == 1)
                        gethead.type = temp;
                    if (i == 2)
                        gethead.defense = stoi(temp);
                    if (i == 3)
                        gethead.effect = temp;
                }
            }
            
        }
        if (linenumber == 11)
        {
            if (!line.empty())
            {
                istringstream s(line);
                string temp;
                for (int i = 0; i <4; i++)
                {
                    s >> temp;
                    if (i == 0)
                        getchest.name = temp;
                    if (i == 1)
                        getchest.type = temp;
                    if (i == 2)
                        getchest.defense = stoi(temp);
                    if (i == 3)
                        getchest.effect = temp;
                }
            }
            
        }
        if (linenumber == 12)
        {
            if (!line.empty())
            {
                istringstream s(line);
                string temp;
                for (int i = 0; i <4; i++)
                {
                    s >> temp;
                    if (i == 0)
                        getleg.name = temp;
                    if (i == 1)
                        getleg.type = temp;
                    if (i == 2)
                        getleg.defense = stoi(temp);
                    if (i == 3)
                        getleg.effect = temp;
                }
            }
            
        }
        if (linenumber == 13)
        {
            if (!line.empty())
            {
                istringstream s(line);
                string temp;
                for (int i = 0; i <4; i++)
                {
                    s >> temp;
                    if (i == 0)
                        getboots.name = temp;
                    if (i == 1)
                        getboots.type = temp;
                    if (i == 2)
                        getboots.defense = stoi(temp);
                    if (i == 3)
                        getboots.effect = temp;
                }
            }
            
        }
        
        linenumber++;
    }

    infostruct returnthis;
    returnthis.name = getname;
    returnthis.seed = getseed;
    returnthis.turn = getturn; // the number of iterations of rng the character is currently in
    returnthis.health = gethealth;
    returnthis.hunger = gethunger;
    returnthis.maxhealth = getmaxhealth;
    returnthis.crit = getcrit;
    returnthis.level = getlevel;
    returnthis.speed = getspeed;
    returnthis.currentweapon = getweapon;
    returnthis.head = gethead;
    returnthis.chest = getchest;
    returnthis.leg = getleg;
    returnthis.boots = getboots;


    fin.close();

    return returnthis;
}