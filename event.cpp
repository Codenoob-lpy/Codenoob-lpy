#include "functions.h"

infostruct event(int rng, infostruct character)
{
    if (rng <= 200000 && rng > 0) // random wep
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
    else if (rng <= 1000000 && rng > 800000) // random armor 
    // suggest to change upper limitation to 1000000 - 0 = 1000000 and lower to 1000000 - 200000 = 800000
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
    else if (rng <= 300000 && rng > 200000) // heal to full health
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
    else if (rng <= 800000 && rng > 750000)
    {
        character = blacksmith(character, rng);
    }
    else if (rng <= 750000 && rng > 700000)
    {
        cout << "You see an angel. She seems welcome to new comer and asks you a question." << endl;
        cout << '"' << "I can help you to enhance your speed and max health." << '"';
        character.maxhealth += character.level / 10;
        character.speed += character.level / 20; 
    }
    else if (rng <= 400000 && rng > 300000)
    {
        cout << "You see a demon. He uses a knife to stabs your arm." << endl;
        cout << '"' << "You are really unlucky to meet me. " << '"';
        character.health = character.health * 0.5;
    } 
    else if (rng <= 450000 && rng > 400000)
    {
        string input;
        int price;
        cout << "You see a travelling merchant. He seems welcome to new customer." << endl;
        cout << '"' << "Anything that you want to buy?. Armors or weapons? " << '"' << endl;
        cout << "Tips: Please type 'armors' or 'weapons' if you want to buy\n";
        cout << "Type 'n' if you do not want to buy anything: ";
        cin >> input;
        while (input != "armors" && input != "weapons" && input != "n")
        {
            cin >> input;
        }
        genericinput(input, character);
        
        if (input == "weapons"){
            weapon product = randomweapon(rng, character.turn, character.level);
            cout << "Here you are! It is a " << product.effect << ' '<< product.name << " and it can deal " << product.damage << endl;
            if (product.effect == "cursed"){
                cout << "It is cheap and is worth 2 coins\n";
                price = 2;
            }else if (product.effect == "blessed"){
                cout << "It is a bit expensive and is worth 5 coins\n";
                price = 5;
            }else if (product.effect == "epic"){
                cout << "It is a bit expensive and is worth 10 coins\n";
                price = 10;
            }else if (product.effect == "legendary"){
                cout << "It is the most expensive and is worth 20 coins\n";
                price = 20;
            }else if (product.effect == "broken"){
                cout << "It is not expensive at all and is worth 1 coin\n";
                price = 1;
            }
            cout << "Will you buy this weapon?" << endl;
            cout << "Tips: Please type 'y' if you want, other wise type 'n' :" << endl;
            cin >> input;
            while (input != "y" && input != "n"){
                genericinput(input, character);
                cout << "Tips: Please type 'y' if you want, other wise type 'n' :" << endl;
                cin >> input;
            }
        } else if (input == "armors"){
            armor product = randomarmor(rng, character.turn, character.level);
            string name = product.name;
        }
        
        
        
        
    }else{
        monster current_monster = monster_sponsor(character.turn, rng);
        cout << "You meet a monster " << current_monster.name << "!!!";
        
    }

    return character;
}