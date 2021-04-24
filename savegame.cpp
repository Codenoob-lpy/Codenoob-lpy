#include "functions.h"

void savegame(infostruct character)
{
    
    string filename = character.name + ".txt";
    ofstream newfile (filename);
    newfile << character.name << endl;
    newfile << character.seed << endl;
    newfile << character.turn << endl;
    newfile << character.health << endl;
    newfile << character.coins << endl;
    newfile << character.maxhealth << endl;
    newfile << character.crit << endl;
    newfile << character.level << endl;
    newfile << character.speed << endl;
    //equipment
    newfile << character.currentweapon.name << " " << character.currentweapon.damage << " " << character.currentweapon.effect << endl;
    //format: "armor_name type(e.g. head(means helmet)) defense effect" example: "abc_chestplate chest 1 none"
    newfile << character.head.name << " " << character.head.type << " " << character.head.defense << " " << character.head.effect << endl;
    newfile << character.chest.name << " " << character.chest.type << " " << character.chest.defense << " " << character.chest.effect << endl;
    newfile << character.leg.name << " " << character.leg.type << " " << character.leg.defense << " " << character.leg.effect << endl;
    newfile << character.boots.name << " " << character.boots.type << " " << character.boots.defense << " " << character.boots.effect << endl;
    //end of equipment
    //
}