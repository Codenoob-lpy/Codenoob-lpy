#include "functions.h"

void status(infostruct character)
{
    cout << "Turn " << character.turn << "| Lv "<< character.level <<"| HP: " <<  character.health << "/" << character.maxhealth << "| Coins: " << character.coins << "| Dmg: " << character.currentweapon.damage << "| Def: " << character.head.defense + character.chest.defense + character.leg.defense + character.boots.defense << endl;
}