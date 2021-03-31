#include "functions.h"


void newcharacter()
{
    cout << "Character name: ";
    string newname;
    cin >> newname;
    string newfilename =  newname + ".txt";
    int newseed;
    cout << "Enter seed (leave empty for random seed): ";
    cin >> newseed;
    ofstream newfile (newfilename);

    int newturn = 0; // the number of iterations of rng the character is currently in
    int newhealth = 100;
    int newhunger = 0;
    int newmana = 20;
    double newcrit = 0;
    
    newfile << newname << endl;
    newfile << newseed << endl;
    newfile << newturn << endl;
    newfile << newhealth << endl;
    newfile << newhunger << endl;
    newfile << newmana << endl;
    newfile << newcrit << endl;

    newfile << "inventory slots: 10 starting from the next line" << endl;



    newfile.close();
    
}