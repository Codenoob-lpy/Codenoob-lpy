#include "functions.h"


void newcharacter()
{
    cout << "Character name: ";
    string newname;
    cin >> newname;
    string newfilename =  newname + ".txt";
    int newseed;
    string input;
    cout << "Enter seed (enter 'r' for random seed): ";
    cin >> input;
    if (input == "r")
    {
        srand(time(0));
        newseed = rand() % 999999;
    }
    else
        newseed = stoi(input);
    
    ofstream newfile (newfilename);

    int health = 100;
    double crit = 10;
    int newturn = 0; // the number of iterations of rng the character is currently in
    int newhealth = 100;
    int newcoins = 50;
    int newmaxhealth = 100;
    double newcrit = 3;
    double level = 1;   // do we have any exp system?
    double speed = 10;   // would be better to start at 5
    
    newfile << newname << endl;
    newfile << newseed << endl;
    newfile << newturn << endl;
    newfile << newhealth << endl;
    newfile << newcoins << endl;
    newfile << newmaxhealth << endl;
    newfile << newcrit << endl;
    newfile << level << endl;
    newfile << speed << endl;
    //equipment
    newfile << "wooden_sword 12 none"<< endl; // weapon
    //format: "armor_name type(e.g. head(means helmet)) defense effect" example: "abc_chestplate chest 1 none"
    newfile << "0 0 0 0" << endl; // head 
    newfile << "0 0 0 0" << endl; // chest 
    newfile << "0 0 0 0" << endl; // leg
    newfile << "0 0 0 0" << endl; // boots
    //end of equipment
    //
     



    newfile.close();
    
}