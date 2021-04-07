#include "functions.h"

void genericinput(string input, infostruct character)
{
    // universal commands
    if (input == "save" || input == "quit")
    {
        savegame(character);
        exit(EXIT_SUCCESS);
    }
    if (input == "help")
    {
        cout << "Commands:\n\nGeneral";
        cout << "> save / quit: saves and quits the game\n";
        cout << "> help: shows a list of available commands\n\nInventory\n";
        cout << "> weapon: details of your current weapon\n";
        cout << "> head: details of your current head armor\n";
        cout << "> chest: details of your current chest armor\n";
        cout << "> leg: details of your current leg armor\n";
        cout << "> boots: details of your current boots\n";
    }
    //
    // view character info
    if (input == "weapon")
    {
        if (character.currentweapon.name == "0")
            cout << "No armor equipped\n";
        else
        {
            cout << "Name: "<<character.currentweapon.name << endl;
            cout << "Damage: " << character.currentweapon.damage << endl;
            cout << "Enchantment: " << character.currentweapon.effect << endl; 
        }
    }
    if (input == "head")
    {
        if (character.head.name == "0")
            cout << "No armor equipped\n";    
        else
        {    
            cout << "Name: "<< character.head.name << endl;
            cout << "Defense: " << character.head.defense << endl;
            cout << "Enchantment: " << character.head.effect << endl; 
        }
    }
    if (input == "chest")
    {
        if (character.chest.name == "0")
            cout << "No armor equipped\n";
        else
        {
            cout << "Name: "<<character.chest.name << endl;
            cout << "Defense: " << character.chest.defense << endl;
            cout << "Enchantment: " << character.chest.effect << endl; 
        }
    }
    if (input == "leg")
    {
        if (character.leg.name == "0")
            cout << "No armor equipped\n";
        else
        {
            cout << "Name: "<<character.leg.name << endl;
            cout << "Defense: " << character.leg.defense << endl;
            cout << "Enchantment: " << character.leg.effect << endl;
        } 
    }
    if (input == "boots")
    {
        if (character.boots.name == "0")
            cout << "No armor equipped\n";
        else
        {
            cout << "Name: "<<character.boots.name << endl;
            cout << "Defense: " << character.boots.defense << endl;
            cout << "Enchantment: " << character.boots.effect << endl;
        } 
    }


}