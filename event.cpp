#include "functions.h"

infostruct event(int rng, infostruct character)
{
    if (rng % 2 == 0) // random wep
    {
        weapon loot = randomweapon(rng, character.turn, character.level);
        cout << "You came across a chest and found " << loot.name << ". It does " << loot.damage << " damage.\nDo you want to discard your current weapon and use " << loot.name << "?\n";
        if (loot.effect != "none")
        {
            cout << "Enchantment: " << loot.effect;
        }
        
        string input;
        while (input != "n" && input != "N" && input != "Y" && input != "y")
        {
            
            genericinput(input, character);
            cout << "Type Y/N and press enter: ";
            cin >> input;
        }
        if (input == "Y" || input == "y" )
        {
            character.currentweapon = loot;
            character.level += 0.25;
        }

    }
    if (rng % 2 == 1) // random armor
    {
        armor loot = randomarmor(rng, character.turn, character.level);
        cout << "You came across a chest and found " << loot.name << ". It has " << loot.defense << " defense.\nDo you want to discard your current " << loot.type << " armor and use " << loot.name << "?\n";
        if (loot.effect != "none")
        {
            cout << "Enchantment: " << loot.effect;
        }
        
        string input;
        while (input != "n" && input != "N" && input != "Y" && input != "y")
        {
            
            genericinput(input, character);
            cout << "Type Y/N and press enter: ";
            cin >> input;
        }
        if (input == "Y" || input == "y" )
        {
            if (loot.type == "head")
                character.head = loot;
            if (loot.type == "chest")
                character.chest = loot;
            if (loot.type == "leg")
                character.leg = loot;
            if (loot.type == "boots")
                character.boots = loot;
            
            character.level += 0.25;
        }

    }

    return character;
}