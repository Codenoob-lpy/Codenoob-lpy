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
int RNG (int seed, int turn) // now uses normal distribution. maybe 350000 < rng < 550000 for monster to appear, so they are more common than other events now
{
    mt19937_64 gen ((unsigned) seed);
    gen.discard(turn);
    int temp = gen() % 999999;
    mt19937_64 gen2 (temp);
    gen2.discard(turn);
    normal_distribution<double> dist(500000,150000);    //median = 500000, standard deviation = 150000
    int result = dist(gen2);
    return result;
}
