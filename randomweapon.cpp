#include "functions.h"

weapon randomweapon(int rngoutput, int turn, int level)
{
    char vowel[] = {'a','e', 'i', 'o', 'u'};
    string suffix[] = {"'s",""};
    string types[] = {"sword","spear","lance","shortsword", "longsword", "dagger", "axe", "waraxe", "hammer", "katana", "flail", "bat", "stick", "staff", "whip", "saber", "cutlass"};
    string effects[] = {"none", "none", "none", "none", "none", "none", "none", "none", "none", "none", "none", "none", "none", "blessed", "cursed", "epic", "broken", "ancient", "weak", "legendary"};
    weapon result;
    
    srand(rngoutput);
    

    int stringsize = rand() % 10 + 1;
    string name;
    int damage;
    string effect;
    srand(rngoutput);
    for (int i = 0; i < stringsize; i++)
    {
        char x;
        if (i == 0)
        {
            x = 'A' + rand() % 26;    
        }
        
        else if ((i+1) % 3 == 0)
        {
            x = vowel[rand() % 4];    
        }
        
        else
        {
            x = 'a' + rand() % 26;    
        }       
        name += x;       
    }
    string type =  types[rand() % 16];
    string s = suffix[rand() % 2];
    if (s == "'s")
        name = name + s + '_' + type; 
    else
        name = type + "_of_" + name;
    double formula = (rand() % 5) * level * 0.75 + turn;
    damage = (int)formula;
    effect =  effects[rand() % 19];
    
    result.name = name;
    result.damage = damage;
    result.effect = effect;



    return result;
}