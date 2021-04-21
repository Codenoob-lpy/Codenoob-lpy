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

    while (character.health > 0)
    {
        int rng = RNG(character.seed, character.turn);
        cout << rng << endl; // debug
        status(character);
        character = event(rng, character);
        character.maxhealth += (int)(character.level) * 0.4;         
        character.health += (int)(character.level) * 0.4;
        if (character.health >= character.maxhealth)
            character.health = character.maxhealth;

        character.turn++;
    }
    if (character.health <= 0)
    {
        int score = (int) (character.level * character.turn);
        cout << "YOU DIED!!!\nScore: " << score << endl;
        string temp = character.name + ".txt";
        char * removefile = new char [temp.length() + 1];
        strcpy(removefile, temp.c_str());
        remove(removefile);


        delete[] removefile;
        cout << "Thank you for playing RNG ADVENTURE!\n"; 
        
    }
    
    return 0;
}