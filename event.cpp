#include "functions.h"

infostruct event(int rng, infostruct character)
{
    if (rng <= 350000 && rng > 300000) // random wep
    {
        weapon loot = randomweapon(rng, character.turn, character.level);
        string name = loot.name;
        replace( name.begin(), name.end(), '_', ' ');
        cout << "You came across a chest and found " << name << ". It does " << loot.damage << " damage.\nDo you want to discard your current weapon and use " << name << "?\n";
        if (loot.effect != "none")
        {
            cout << "Enchantment: " << loot.effect << endl;
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
    if (rng <= 650000 && rng > 550000) // random armor
    {
        armor loot = randomarmor(rng, character.turn, character.level);
        string name = loot.name;
        replace( name.begin(), name.end(), '_', ' ');
        cout << "You came across a chest and found " << name << ". It has " << loot.defense << " defense.\nDo you want to discard your current " << loot.type << " armor and use " << name << "?\n";
        if (loot.effect != "none")
        {
            cout << "Enchantment: " << loot.effect << endl;
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
    if (rng <= 100000 && rng > 50000) // heal to full health
    {
        cout << "You encounter a well. The water looks unusually pure. Do you want to drink it?\n";
        string input;
        while (input != "n" && input != "N" && input != "Y" && input != "y")
        {
            
            genericinput(input, character);
            cout << "Type Y/N and press enter: ";
            cin >> input;
        }
        if (input == "Y" || input == "y" )
        {
            character.health = character.maxhealth;
        }
    }

    return character;
}