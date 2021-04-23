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
            cout << "You feel a presence of magic within this weapon."<< endl;
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

            if (loot.effect != "none")
            {
                cout << "This weapon is " << loot.effect << "!" << endl;
                if (loot.effect == "blessed")
                {
                    character.health += (rand() % 200);
                    character.level *= 1.25;
                    cout << "The blessed weapon empowers you! You feel better!\n";
                }
                if (loot.effect == "cursed")
                {
                    character.health -= (rand() % 20);
                    character.level *= 0.8;
                    cout << "The cursed weapon sucks away your life force! You don't feel so good...\n";
                }
                
            }
        }

    }
    if (rng <= 850000 && rng > 800000) // random armor 
    // suggest to change upper limitation to 350000 + 500000 = 850000 and lower to 300000 + 500000 = 800000
    // main reason of adjustment is to keep same probability( normal distirbution )
    {
        armor loot = randomarmor(rng, character.turn, character.level);
        string name = loot.name;
        replace( name.begin(), name.end(), '_', ' ');
        cout << "You came across a chest and found " << name << ". It has " << loot.defense << " defense.\nDo you want to discard your current " << loot.type << " armor and use " << name << "?\n";
        if (loot.effect != "none")
        {
            cout << "You feel a presence of magic within this armor."<< endl;
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

            if (loot.effect != "none")
            {
                cout << "This armor is " << loot.effect << "!" << endl;
                if (loot.effect == "blessed")
                {
                    character.health += (rand() % 300);
                    character.maxhealth += (rand() % 30);
                    character.level *= 1.25;
                    cout << "The blessed armor invigorates you! You feel better!\n";
                }
                if (loot.effect == "cursed")
                {
                    character.health -= (rand() % 25);
                    character.level *= 0.8;
                    cout << "The cursed armor weakens you! You don't feel so good...\n";
                }
                
            }
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
            cout << "You feel much better!\n";
        }
    }
    if (rng <= 750000 && rng > 650000)
    {
        character = blacksmith(character, rng);
    }
    if (rng <= 650000 && rng > 550000)
    {
        cout << "You see an elf. He seems welcome to new comer and asks you a question." << endl;
        cout << '"' << "I can help you to enhance your speed and max health." << '"';
        character.maxhealth += 10;
        character.speed += 2; //dont sure that the status too high or what can be adjust
    }
    if (rng <= 850000 && rng > 750000)
    {
        cout << "You see an evil. He seems welcome to new comer." << endl;
        cout << '"' << "You are really unlucky to meet me. " << '"';
        character.health -= 20;
    } 
    return character;
}