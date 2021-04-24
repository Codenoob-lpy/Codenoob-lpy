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
        character.crit += 2;
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
        cout << '"' << "Anything that you want to buy?. Armor or weapon? " << '"' << endl;
        cout << "Tips: Please type 'armor' or 'weapon' if you want to buy\n";
        cout << "Type 'n' if you do not want to buy anything: ";
        cin >> input;
        while (input != "armor" && input != "weapon" && input != "n")
        {
            cout << "Tips: Please type 'armor' or 'weapon' if you want to buy\n";
            cin >> input;
        }
        genericinput(input, character);
        
        if (input == "weapon"){
            weapon product = randomweapon(rng, character.turn, character.level);
            if (product.effect != "none"){
                cout << "Here you are! It is a " << product.effect << ' '<< product.name << " and it can deal " << product.damage << " damages"<< endl;
            }else {
                cout << "Here you are! It is a " << product.name << " and it can deal " << product.damage << " damages"<< endl;            
            }
            if (product.effect == "cursed"){
                price = 3 * character.level;
                cout << "It is cheap and is worth "<< price << " coins\n";
            }else if (product.effect == "blessed"){
                price = 10 * character.level;
                cout << "It is a bit expensive and is worth "<< price << " coins\n";
            }else if (product.effect == "epic"){
                price = 20 * character.level;
                cout << "It is a bit expensive and is worth "<< price << " coins\n";
            }else if (product.effect == "legendary"){
                price = 50 * character.level;
                cout << "It is the most expensive and is worth "<< price << " coins\n";
            }else if (product.effect == "broken"){
                price = character.level;
                cout << "It is not expensive at all and is worth "<< price << " coins\n";
            }
            cout << "Will you buy this weapon?" << endl;
            cout << "Tips: Please type 'y' if you want, other wise type 'n' :" << endl;
            cin >> input;
            while (input != "y" && input != "n"){
                genericinput(input, character);
                cout << "Tips: Please type 'y' if you want, otherwise type 'n' :" << endl;
                cin >> input;
            }
            if (input == "y"){
                character.currentweapon = product;
                character.coins -= price;
                if (product.effect != "none")
                {
                    cout << "This weapon is " << product.effect << "!" << endl;
                    if (product.effect == "blessed")
                    {
                        character.health += (rand() % 200);
                        character.level *= 1.25;
                        cout << "The blessed weapon empowers you! You feel better!\n";
                    }
                    if (product.effect == "cursed")
                    {
                        character.health -= (rand() % 20);
                        character.level *= 0.8;
                        cout << "The cursed weapon sucks away your life force! You don't feel so good...\n";
                    }
                    
                }

            }else{
                cout << "You start your journey again." << endl;
            }
            genericinput(input, character);
        } else if (input == "armor"){
            armor product = randomarmor(rng, character.turn, character.level);
            if (product.effect != "none"){
                cout << "Here you are! It is a " << product.effect << ' '<< product.type << " armor and it can defense " << product.defense << " damages"<< endl;
            }else{
                cout << "Here you are! It is a " << product.type << " armor and it can defense " << product.defense << " damages"<< endl;
            }
            if (product.effect == "cursed"){
                price = 3 * character.level;
                cout << "It is cheap and is worth "<< price << " coins\n";
            }else if (product.effect == "blessed"){
                price = 10 * character.level;
                cout << "It is a bit expensive and is worth "<< price << " coins\n";
            }else if (product.effect == "epic"){
                price = 20 * character.level;
                cout << "It is a bit expensive and is worth "<< price << " coins\n";
            }else if (product.effect == "legendary"){
                price = 50 * character.level;
                cout << "It is the most expensive and is worth "<< price << " coins\n";
            }else if (product.effect == "broken"){
                price = character.level;
                cout << "It is not expensive at all and is worth "<< price << " coins\n";
            }
            cout << "Will you buy this armor?" << endl;
            cout << "Tips: Please type 'y' if you want, other wise type 'n' :" << endl;
            cin >> input;
            while (input != "y" && input != "n"){
                genericinput(input, character);
                cout << "Tips: Please type 'y' if you want, otherwise type 'n' :" << endl;
                cin >> input;
            }
            if (input == "y"){
                character.coins -= price;
                if (product.type == "head")
                    character.head = product;
                if (product.type == "chest")
                    character.chest = product;
                if (product.type == "leg")
                    character.leg = product;
                if (product.type == "boots")
                    character.boots = product;
                if (product.effect != "none")
                {
                    cout << "This weapon is " << product.effect << "!" << endl;
                    if (product.effect == "blessed")
                    {
                        character.health += (rand() % 200);
                        character.level *= 1.25;
                        cout << "The blessed weapon empowers you! You feel better!\n";
                    }
                    if (product.effect == "cursed")
                    {
                        character.health -= (rand() % 20);
                        character.level *= 0.8;
                        cout << "The cursed weapon sucks away your life force! You don't feel so good...\n";
                    }
                    
                }
                genericinput(input, character);
            }else{
                cout << "You start your journey again." << endl;
            }
            genericinput(input, character);
        } else {
            cout << "You start your journey again." << endl;
        }
    }else{
        monster current_monster = monster_spawner(character.turn, rng);

        int battle_turn = 0;
        int player_defense = character.head.defense + character.chest.defense + character.leg.defense + character.boots.defense;
        if (character.turn % 10 != 0){
            cout << "You meet a monster " << '"' << current_monster.name << '"' << "!!! You have to battle with it!!!" << endl;
        } else {
            cout << "You meet a boss monster " << '"' << current_monster.name << '"' << "!!! You have to battle with it!!!" << endl;
        }
        while (current_monster.health > 0 && character.health > 0 ){
            cout << "Turn " << battle_turn << " begins"<< endl;
            cout << "|monster hp: " << current_monster.health << " | player hp: " << character.health << " |\n";
            if (current_monster.speed > character.speed){
                if (current_monster.attack - player_defense > 0){
                    cout << "It hits you with " << current_monster.attack - player_defense <<" damages." << endl;
                    character.health -= current_monster.attack - player_defense;
                }else{
                    cout << "It hits you but you guard most of the damage because of sufficient defense." << endl;
                    character.health -= 10;
                }
                if (character.health <= 0){
                    break;
                }
                if (rand() % 100 <= character.crit){
                    cout << "Lucky!! You make a critical hit!!" << endl;
                    if (character.currentweapon.damage * 2 - current_monster.defense > 0){
                        cout << "You have dealt " << character.currentweapon.damage * 2 - current_monster.defense << " damages to the monster.\n";
                        current_monster.health -= character.currentweapon.damage * 2 - current_monster.defense;
                    }else{
                        cout << "It guards most of the damage because of sufficient defense." << endl;
                        current_monster.health -= 10;
                    }
                }else {
                    if (character.currentweapon.damage - current_monster.defense > 0){
                        cout << "You have dealt " << character.currentweapon.damage - current_monster.defense << " damages to the monster.\n";
                        current_monster.health -= character.currentweapon.damage - current_monster.defense;
                    }else{
                        cout << "It guards most of the damage because of sufficient defense." << endl;
                        current_monster.health -= 10;
                    }
                }
            } else {
                if (rand() % 100 <= character.crit){
                    cout << "Lucky!! You make a critical hit!!" << endl;
                    if (character.currentweapon.damage * 2 - current_monster.defense > 0){
                        cout << "You have dealt " << character.currentweapon.damage * 2 - current_monster.defense << " damages to the monster.\n";
                        current_monster.health -= character.currentweapon.damage * 2 - current_monster.defense;
                    }else{
                        cout << "It guards most of the damage because of sufficient defense." << endl;
                        current_monster.health -= 10;
                    }

                }else {
                    if (character.currentweapon.damage - current_monster.defense > 0){
                        cout << "You have dealt " << character.currentweapon.damage - current_monster.defense << " damages to the monster.\n";
                        current_monster.health -= character.currentweapon.damage - current_monster.defense;
                    }else{
                        cout << "It guards most of the damage because of sufficient defense." << endl;
                        current_monster.health -= 10;
                    }
                    if (current_monster.health <= 0){
                        break;
                    }
                    if (current_monster.attack - player_defense > 0){
                        cout << "It hits you with " << current_monster.attack - player_defense <<" damages." << endl;
                        character.health -= current_monster.attack - player_defense;
                    }else{
                        cout << "It hits you but you guard most of the damage because of sufficient defense." << endl;
                        character.health -= 10;
                    }
                }
            battle_turn++;
            }

        
        }

    
    }
    return character;
}
