#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Fish.h"
using namespace std;

namespace sdds
{
	Fish::Fish(const char* name, int initialAge) : Pet(name, initialAge, cFishFee)
	{
	}

};