#include "functions.h"

armor randomarmor(int rngoutput, int turn, int level)
{
    char vowel[] = {'a','e', 'i', 'o', 'u'};
    string suffix[] = {"'s",""};
    string maintypes[] = {"head", "chest", "leg", "boots"};
    string headtypes[] = {"helmet","hat","headgear","visor"}; 
    string chesttypes[] = {"chestplate", "tunic", "chainmail", "suit"}; 
    string legtypes[] = {"leggings", "pants", "trousers", "shorts",}; 
    string bootstypes[] = {"boots", "shoes"};
    string effects[] = {"none", "none", "none", "none", "none", "none", "none", "none", "none", "none", "none", "none", "none", "blessed", "cursed", "epic", "broken", "ancient", "weak", "legendary"};
    armor result;
    
    srand(rngoutput);
    

    int stringsize = rand() % 10 + 1;
    string name;
    int defense;
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
    string maintype  =  maintypes[rand() % 4];
    string type;
    if (maintype == "head")
        type =  headtypes[rand() % 4];
    if (maintype == "chest")
        type =  chesttypes[rand() % 4];
    if (maintype == "leg")
        type =  legtypes[rand() % 4];
    if (maintype == "boots")
        type =  bootstypes[rand() % 2];
         


    
    string s = suffix[rand() % 2];
    if (s == "'s")
        name = name + s + '_' + type; 
    else
        name = type + "_of_" + name;
    double formula = (rand() % 5) * level * 1.5 + turn * 0.1 ;
    defense = (int)formula;
    effect =  effects[rand() % 19];
    if (effect == "cursed")
        defense /= 1.5;
    if (effect == "blessed")
        defense *= 1.5;
    if (effect == "epic")
        defense *= 2;
    if (effect == "legendary")
        defense *= 4; 
    if (effect == "broken")
        defense /= 4;
    result.name = name;
    result.type = maintype;
    result.defense = defense;    
    result.effect = effect;



    return result;
}