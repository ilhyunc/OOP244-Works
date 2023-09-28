#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

#include "Pet.h"

using namespace std;

namespace sdds
{
	// no argument constructor
	Pet::Pet()
	{
		m_petName[0] = '\0';
		m_originAge = -1;
		m_currentAge = -1;
		m_numFeeds = 0;
		m_numCleanings = 0;
		m_numHugs = 0;
		m_totalAmount = 0.0;
		m_healthLevel = -1.0;
	}

	// constructor
	Pet::Pet(const char* petName, int age, double fee)
	{
		strncpy(m_petName, petName, 21);
		m_originAge = age;
		m_currentAge = age;
		m_totalAmount = fee;
		m_healthLevel = 1.0;
		isLive();
	}

	// increments the number of feedings the pet has received by 1
	void Pet::feed()
	{
		if (isLive())
			m_numFeeds++;
	}

	// increments the number of cleanings the pet has received by 1
	void Pet::groom()
	{
		if (isLive())
			m_numCleanings++;
	}

	// increments the number of hugs the pet has received by 1
	void Pet::hug()
	{
		if (isLive())
			m_numHugs++;
	}

	bool Pet::isLive() const
	{
		return (m_healthLevel < 0.0 || m_healthLevel > 2.0);
	}

	// pay the total charges owed by the customer and reset total charges back to $0
	std::ostream& Pet::payBalance(std::ostream& ostr)
	{
		if (m_totalAmount > 0.0)
		{
			ostr << ">> Balance of $" << m_totalAmount << " has been paid for " << m_petName << endl;
			m_totalAmount = 0.0;
		}

		return ostr;
	}

	// provides a means to respawn a pet which is no longer alive
	void Pet::reSpawn(const char* petName, int age, double fee)
	{
		m_healthLevel = 1.0;
		m_currentAge = m_originAge;
		m_numCleanings = 0;
		m_numFeeds = 0;
		m_numHugs = 0;
		m_totalAmount += rBaseFee;
	}

	// move to the next day: increment the age of the pet by 1 day if it is alive
	Pet& Pet::operator++(int)
	{
		if (isLive())
		{
			m_currentAge++;
			m_numFeeds = 0;
			m_numCleanings = 0;
			m_numHugs = 0;
		}
		return *this;
	}

	// clone a pet
	Pet& Pet::operator=(const Pet& other)
	{
		char temp[21];
		strcpy(temp, other.m_petName);
		strcpy(m_petName, temp);
		strcat(m_petName, "(C)");
		m_originAge = other.m_originAge;
		m_currentAge = other.m_currentAge;
		m_numFeeds = other.m_numFeeds;
		m_numCleanings = other.m_numCleanings;
		m_numHugs = other.m_numHugs;
		m_totalAmount = 0;
		m_healthLevel = other.m_healthLevel;

		return *this;
	}

	// gets the number of Feeds, Grooming and Hugs for this pet
	int Pet::getNumFeed()
	{
		return m_numFeeds;
	}
	int Pet::getNumGroomings()
	{
		return m_numCleanings;
	}
	int Pet::getNumHugs()
	{
		return m_numHugs;
	}

	// adds an incremental $ value to the amount being charged to the customer for this pet
	void Pet::addAmount(double amount)
	{
		m_totalAmount += amount;
	}

	// applies an incremental delta (+/-) to the health level for this pet
	void Pet::healthLevel(double delta)
	{
		m_healthLevel += delta;
	}

	std::ostream& Pet::display(std::ostream& ostr) const
	{
		ostr << "** Generic Pet **" << endl;
		ostr << "   Name: " << m_petName << "; ";
		ostr << m_currentAge << " days old" << endl;
		ostr << "   Feeds, Cleans, Hugs: ";
		ostr << m_numFeeds << ", " << m_numCleanings << ", " << m_numHugs << endl;
		ostr.setf(ios::fixed);
		ostr.precision(2);
		ostr << "   Charges: $" << m_totalAmount << endl;
		ostr << "   Health : " << m_healthLevel;
		if (m_healthLevel == 1.0)
		{
			ostr << " (Ideal)";
		}
		else if (m_healthLevel > 1.0 && m_healthLevel <= 2.0)
		{     
			ostr << " (Over Nurtured)";
		}
		else if (m_healthLevel < 1.0 && m_healthLevel >= 0.0)
		{
			ostr << " (Under Nurtured)";
		}
		else {
			ostr << " (PERISHED)";
		}
		ostr << endl;

		return ostr;
	}

	// helper function
	std::ostream& operator<<(std::ostream& ostr, const Pet& pet)
	{
		return pet.display(ostr);
	}
}
//------------------------------------------


