#include "functions.h"


//cd /mnt/c/Users/chany/Documents/GitHub/engg1340project
int main()
{
      
    // spash screen
    welcome();
    // 

    //
    string input;
    cout << "Press N to create new character / L to load existing game: ";
    cin >> input;
    while (input != "n" && input != "N" && input != "l" && input != "L")
    {
        if (input == "quit" || input == "exit")
            exit(EXIT_SUCCESS);
        
        cin >> input;
    }
    if (input == "n" || input == "N")
    {
        newcharacter();
        cout << "New character created!!" << endl;
    } 
    //

    //  read save file to initialize character data
    infostruct character = readsavefile();
    
    //

    while (character.health != 0)
    {
        int rng = RNG(character.seed, character.turn);
        status(character);
        character = event(rng, character);
        
        character.turn++;
    }
    
    return 0;
}