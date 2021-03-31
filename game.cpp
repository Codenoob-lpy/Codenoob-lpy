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
    int mana;
    double crit;
    
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
    mana = readstruct.mana;
    crit = readstruct.crit;
    //


    
    return 0;
}