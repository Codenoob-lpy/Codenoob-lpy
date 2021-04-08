#include "functions.h"

void welcome()
{
    ifstream fin;
	fin.open("spoiler.txt");
    string line;
    while ( getline(fin, line) )
    {
        cout << line << endl;
    }
    cout << endl;
    cout << "Welcome to RNG ADVENTURE!" << endl;
    fin.close();
}