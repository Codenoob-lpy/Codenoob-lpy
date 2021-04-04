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

    int health = 100;
    int mana = 20;
    double crit = 0;
    int newturn = 0; // the number of iterations of rng the character is currently in
    int newhealth = 100;
    int newhunger = 0;
    int newmaxhealth = 100;
    double newcrit = 0;
    double level = 1;
    double speed = 1;
    
    newfile << newname << endl;
    newfile << newseed << endl;
    newfile << newturn << endl;
    newfile << newhealth << endl;
    newfile << newhunger << endl;
    newfile << newmaxhealth << endl;
    newfile << newcrit << endl;
    newfile << level << endl;
    newfile << speed << endl;
    //equipment
    newfile << "wooden_sword 1 none"<< endl; // weapon
    //format: "armor_name type(e.g. head(means helmet)) defense effect" example: "abc_chestplate chest 1 none"
    newfile << endl; // head 
    newfile << endl; // chest 
    newfile << endl; // leg
    newfile << endl; // boots
    //end of equipment
    //
     



    newfile.close();
    
}