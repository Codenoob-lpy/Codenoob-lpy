#include "functions.h"

// this func can be used for generating a random number
// the number can be used for deciding what event will happen 
// eg what item will be dropped , whether player will encounter special event or not, 
// will player make a critical hit, etc 

/*
int rng (){
    srand((unsigned) time(0));  
    int randomNumber;
    randomNumber = (rand() % 100);
    return randomNumber;
}
*/
int rng (int seed, int turn) // can't think of other ways to generate nth number in random sequence (because need to restore when opening a saved game) without for looping all over again, if not suitable then use your rng above
{
    default_random_engine gen ((unsigned) seed);
    gen.discard(turn);
    int result = gen() % 100;
    return result;
}
