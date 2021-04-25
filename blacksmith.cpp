#include "functions.h"



infostruct blacksmith (infostruct character, int rngoutput)
{
    srand(rngoutput);
    string name;
    int stringsize = rand() % 10 + 1;
    char vowel[] = {'a','e', 'i', 'o', 'u'};
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
    int price = rand() % 100;
    cout << "You encounter a blacksmith named " << name << endl;
    cout << name << ": Hello adventurer! I can reforge your weapon to make it more powerful.\nDo you want to reforge your current weapon for " << price << " coins?\n";
    cout << "\nName: "<<character.currentweapon.name << endl;
    cout << "Damage: " << character.currentweapon.damage << endl;
    cout << "Enchantment: " << character.currentweapon.effect << endl;
    string input;
    while (input != "n" && input != "N" && input != "Y" && input != "y")
    {
            
            genericinput(input, character);
            cout << "Type Y/N and press enter: ";
            cin >> input;
    }
    if (input == "Y" || input == "y" )
    {
        if (price <= character.coins)
        {
        character.currentweapon.damage += rand() % 40 + 10;
        character.currentweapon.effect == "reforged";
        character.coins -= price;

        cout << "\nName: "<< character.currentweapon.name << endl;
        cout << "Damage: " << character.currentweapon.damage << endl;
        cout << "Enchantment: " << character.currentweapon.effect << endl;
        
        cout << "There you go! Good luck!\n";
        }
        else
            cout << name << ": Sorry, but I need enough coins to make a living. Good luck to you!\nYou say goodbye to the blacksmith.\n";


    }




    

    return character;
}