#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_FISH_H
#define SDDS_FISH_H
#include "Pet.h"
#include <ostream>
using namespace std;

namespace sdds 
{
	class Fish : public Pet
	{
		const double cBaseFee = 1.00;
		const double cFishFee = 2.00;
		const double fFishFee = 0.10;
		const double rFishFee = 0.50;

	public:
		// Constructor
		Fish(const char* name, int initialAge = 0);

		// Feed the pet
		void feed();

		// Resets the pet's health
		void reSpawn();

		// Increments the pet's age
		Fish& operator++(int);

		// Clones the pet
		Fish& operator=(const Fish& other);
	};
	std::ostream& operator<<(std::ostream& ostr, const Fish& f);
}
#endif // !SDDS_FISH_H
