#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    int hp1 = 100, hp2 = 100;
    int attack1 = 0, attack2 = 0;
    int randNum;

    srand(time(NULL));  //Update random param

    //Using random number to dicede first attacker

    while(hp1 >= 0 && hp2 >=0)
    {
        randNum = rand();
        if(randNum % 2 == 1)
        {
            attack1 = (int)(5 + 10 * rand() / (RAND_MAX + 1.0));
            attack2 = (int)(5 + 10 * rand() / (RAND_MAX + 1.0));

            hp2 -= attack1;
            hp1 -= attack2;
        }
        else
        {
            attack2 = (int)(5 + 10 * rand() / (RAND_MAX + 1.0));
            attack1 = (int)(5 + 10 * rand() / (RAND_MAX + 1.0));

            hp1 -= attack2;
            hp2 -= attack1;
        }
    }

    cout << "Player1's hp is :" << hp1 << endl;
    cout << "Player2's hp is :" << hp2 << endl;

    return 0;
}