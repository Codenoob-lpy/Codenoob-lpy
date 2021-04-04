#include "functions.h"

// this func can be used for generating a random number
// the number can be used for deciding what event will happen 
// eg what item will be dropped , whether player will encounter special event or not, 
// will player make a critical hit, etc 
int rng (){
    srand((unsigned) time(0));  
    int randomNumber;
    randomNumber = (rand() % 100);
    return randomNumber;
}

