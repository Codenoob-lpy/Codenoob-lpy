#include "functions.h"

monster monster_sponser(){
    monster current;
    char vowel[] = {'a','e', 'i', 'o', 'u'};
    int stringsize = rand() % 10 + 1;
    int turn = 26;
    current.name;
    current.attack = 10;
    current.defense = 0;
    current.speed = 1; 
    current.health = 10;    srand(123340);
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
    if ( turn % 10 != 0){   
        current.attack = (turn / 10) * 10 + turn % 10;
        current.defense = turn % 10;
        current.speed += turn;
        
    }
}