#include "functions.h"

monster monster_spawner(int turn, int rngoutput){
    monster current;
    char vowel[] = {'a','e', 'i', 'o', 'u'};
    int stringsize = rand() % 10 + 1;
    current.name;
    current.attack = 10;
    current.defense = 0;
    current.speed = 1; 
    current.health = 10;   
    srand(rngoutput);
    for (int i = 0; i < stringsize; i++)
    {
        char x;
        if (i == 0)
        {
            x = 'A' + rand() % 26;    
        }
        
        else if (i % 3 == 0)
        {
            x = vowel[rand() % 4];    
        }
        
        else
        {
            x = 'a' + rand() % 26;    
        }       
        current.name += x;       
    }
    cout << current.name;
    if ( turn % 10 != 0){   // weak monster
        current.attack += (turn / 10) * 10 + turn % 10;
        current.defense += turn % 10;
        current.speed += turn+turn/10;
        current.health += turn / 10 * 10 + 10 + turn % 10; 
        
    } else {
        current.attack += 20 * (turn / 10);
        current.defense += (turn / 10) * 10;
        current.speed += 10 * (turn / 10);
        current.health += 30 * (turn / 10);
    }
    return current;
}