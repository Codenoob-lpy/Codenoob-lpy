#include "functions.h"


//cd /mnt/c/Users/chany/Documents/GitHub/engg1340project
int main()
{
    // pass from save file
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
    
    // spash screen
    welcome();
    // 

    //
    string input;
    cout << "Press N to create new character / L to load existing game: ";
    cin >> input;
    while (input != "n" && input != "N" && input != "l" && input != "L")
    {
        cin >> input;
    }
    if (input == "n" || input == "N")
    {
        newcharacter();
        cout << "New character created!!" << endl;
    } 
    //

    //  read save file to initialize character data
    infostruct readstruct = readsavefile();
    name = readstruct.name;
    seed = readstruct.seed;
    turn = readstruct.turn;
    health = readstruct.health;
    hunger = readstruct.hunger;
    maxhealth = readstruct.maxhealth;
    crit = readstruct.crit;
    currentweapon = readstruct.currentweapon;
    head = readstruct.head;
    chest = readstruct.chest;
    leg = readstruct.leg;
    boots = readstruct.boots;
    //


    
    return 0;
}