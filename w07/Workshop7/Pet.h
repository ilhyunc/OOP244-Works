#ifndef SDDS_PET_H_
#define SDDS_PET_H_

#include <iostream>

namespace sdds 
{
	class Pet 
	{
		const double cBaseFee = 1.00;
		const double fBaseFee = 0.00;
		const double rBaseFee = 0.25;

		char m_petName[21]; // pet name
		int m_originAge; // pet's original age
		int m_currentAge; // pet's current age
		int m_numFeeds; // number of feedings today
		int m_numCleanings; // number of cleanings today
		int m_numHugs; // number of hugs today
		double m_totalAmount; // total charge for this pet
		double m_healthLevel; // health level of the pet

	protected:
		// gets the number of Feeds, Grooming and Hugs for this pet
		int getNumFeed();
		int getNumGroomings();
		int getNumHugs();

		// adds an incremental $ value to the amount being charged to the customer for this pet
		void addAmount(double amount);

		// applies an incremental delta (+/-) to the health level for this pet
		void healthLevel(double value);

	public:

		Pet();

		// constructs a pet object with name, optional initial age, and optional incremental fee
		Pet(const char* petName, int age = 0, double fee = 0.0);

		// increments the number of feedings the pet has received by 1
		void feed();

		// increments the number of groomings the pet has received by 1
		void groom();

		// increments the number of hugs the pet has received by 1
		void hug();

		// check the pet's Health level
		bool isLive() const;

		// pay the total charges owed by the customer and reset total charges back to $0
		std::ostream& payBalance(std::ostream& ostr);

		// provides a means to respawn a pet which is no longer alive
		void reSpawn(const char* petName, int age = 0, double fee = 0.0);

		// move to the next day: increment the age of the pet by 1 day if it is alive
		Pet& operator++(int);

		// clone a pet
		Pet& operator=(const Pet& other);

		//display
		std::ostream& display(std::ostream& ostr) const;

	};
	// helper function
	std::ostream& operator<<(std::ostream& ostr, const Pet& pet);
}
#endif // PET_H_