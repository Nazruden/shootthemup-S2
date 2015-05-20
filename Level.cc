// Shoot Them Up - Emilie Dao - Benjamin De Pourquery - S2B
// Level.cc

#include "Level.h"
#include <iostream>

using namespace std;

/*** Ctors / Dtors ***/
Level::Level(int num) : _num(num)
{
    _ratio = 1 * (float)_num;
    _length = BASE_LENGTH * _ratio;
}
