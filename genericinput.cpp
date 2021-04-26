#include "functions.h"

void genericinput(string input, infostruct character)
{
    // universal commands
    if (input == "save" || input == "quit")
    {
        savegame(character);
        cout << "\nThank you for playing RNG ADVENTURE!\n";
        exit(EXIT_SUCCESS);
    }
    if (input == "help")
    {
        cout << "\nCommands:\n\nGeneral\n";
        cout << "> save / quit: saves and quits the game\n";
        cout << "> help: shows a list of available commands\n";
        cout << "> about: about the game\n";
        cout << "\nInventory\n";
        cout << "> weapon: details of your current weapon\n";
        cout << "> head: details of your current head armor\n";
        cout << "> chest: details of your current chest armor\n";
        cout << "> leg: details of your current leg armor\n";
        cout << "> boots: details of your current boots\n\n";
    }
    if (input == "about")
    {
        cout << "This is a text-based adventure game and the player \nhave to go into the infinite dungeon as deep as possible.\n";  
        cout << "Player needs to fight with monsters which will appear \nin the dungeon and boss monsters will appear every ten battles. \nThere are some special events as well. Some of them may give the player blesses/curses and some of them sell the player equipment.\n"; 
        cout << "Player has to make different decisions such as battling,\n using items during each battle to survive in the dungeon. Also,\n player can get rewards like items, food and weapons (rare) after every battle.\n\n";
    }
    //
    // view character info
    if (input == "weapon")
    {
        if (character.currentweapon.name == "0")
            cout << "\nNo armor equipped\n\n";
        else
        {
            cout << "\nName: "<<character.currentweapon.name << endl;
            cout << "Damage: " << character.currentweapon.damage << endl;
            cout << "Enchantment: " << character.currentweapon.effect << endl << endl; 
        }
    }
    if (input == "head")
    {
        if (character.head.name == "0")
            cout << "\nNo armor equipped\n\n";    
        else
        {    
            cout << "\nName: "<< character.head.name << endl;
            cout << "Defense: " << character.head.defense << endl;
            cout << "Enchantment: " << character.head.effect << endl << endl; 
        }
    }
    if (input == "chest")
    {
        if (character.chest.name == "0")
            cout << "\nNo armor equipped\n\n";
        else
        {
            cout << "\nName: "<<character.chest.name << endl;
            cout << "Defense: " << character.chest.defense << endl;
            cout << "Enchantment: " << character.chest.effect << endl << endl; 
        }
    }
    if (input == "leg")
    {
        if (character.leg.name == "0")
            cout << "\nNo armor equipped\n\n";
        else
        {
            cout << "\nName: "<<character.leg.name << endl;
            cout << "Defense: " << character.leg.defense << endl;
            cout << "Enchantment: " << character.leg.effect << endl << endl;
        } 
    }
    if (input == "boots")
    {
        if (character.boots.name == "0")
            cout << "\nNo armor equipped\n\n";
        else
        {
            cout << "\nName: "<<character.boots.name << endl;
            cout << "Defense: " << character.boots.defense << endl;
            cout << "Enchantment: " << character.boots.effect << endl;
        } 
    }


}