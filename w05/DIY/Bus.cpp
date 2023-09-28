#include "Bus.h"

using namespace std;
namespace sdds
{
	Bus::Bus(int seats, int passengers)
	{
		if (seats % 2 == 0 && seats >= 10 && seats <= 40 && passengers >= 0 && passengers <= seats)
		{
			m_seats = seats;
			m_passengers = passengers;
		}
		else
		{
			m_seats = -1;
		}
	}

	Bus::~Bus() 
	{
		m_seats = -1;
	}

	istream& Bus::read(istream& istr)
	{
		int seats, passengers;
		istr >> seats;
		istr.ignore();

		istr >> passengers;
		istr.ignore();

		if (seats % 2 == 0 &&
			seats >= 10 && seats <= 40 &&
			passengers >= 0 && passengers <= seats) {
			m_seats = seats;
			m_passengers = passengers;
		}
		else 
		{
			m_seats = -1;
		}

		return istr;
	}

	// Display function
	void Bus::drawBus(int seats, int noOfPassengers, ostream& ostr) const
	{
		int i, p;
		ostr.fill('_');
		ostr.width((static_cast<std::streamsize>(seats / 2)) * 3 + 4);
		ostr << "_";
		ostr << endl << "| ";
		for (i = 0, p = -1; i < (seats / 2); i++, ostr << "[" << ((p += 2) < noOfPassengers ? '2' : ((p == noOfPassengers) ? '1' : ' ')) << "]");
		ostr << "|_\\_" << endl;
		ostr << "| ";
		ostr.fill(' ');
		ostr.width(((static_cast<std::streamsize>(seats / 2)) * 3 - 14) / 2);
		ostr << " " << "Seneca College";
		ostr.width(static_cast<std::streamsize>(((seats / 2) * 3 - 14) / 2) + (seats % 4 != 0));
		ostr << " " << "    )" << endl;
		ostr << "`---OO";
		ostr.fill('-');
		ostr.width((static_cast<std::streamsize>(seats / 2)) * 3 - 5);
		ostr << "-" << "O---'" << endl;
		ostr.setf(ios::fixed);
		ostr.precision(2);
		ostr << "Total Fare Price: " << double(*this) << endl;
	}

	ostream& Bus::display(ostream& ostr) const
	{
		if (bool(*this)) {
			drawBus(m_seats, m_passengers, ostr);
		}
		else {
			ostr << "Out of service!" << endl;
		}
		return ostr;
	}

	Bus::operator bool() const 
	{
		return m_seats > 0; // returns true if the bus is in service
	}
	Bus::operator int() const 
	{
		return bool(*this) ? m_passengers : -1;
		// return number of passengers
	}
	Bus::operator double() const 
	{
		return bool(*this) ? (m_passengers * ticketPrice) : -1.0;
		// return total fare
	}

	// Unary Operator overloads:
	bool Bus::operator--() 
	{
		bool minus = false;
		if (bool(*this) && m_passengers > 0)
		{
			m_passengers--;
			minus = true;
		}
		return minus;
	}

	bool Bus::operator++() 
	{
		bool plus = false;
		if (bool(*this) && (m_passengers < m_seats))
		{
			m_passengers++;
			plus = true;
		}
		return plus;
	}

	bool Bus::operator--(int) 
	{
		bool minus = false;
		if (bool(*this) && m_passengers > 0) 
		{
			m_passengers--;
			minus = true;
		}
		return minus;
	}

	bool Bus::operator++(int) 
	{
		bool plus = false;
		if (bool(*this) && (m_passengers < m_seats))
		{
			m_passengers++;
			plus = true;
		}
		return plus;
	}

	// Binary Member Operators
	Bus& Bus::operator=(int value) 
	{
		if (value > m_seats)
		{
			m_seats = -1;
		}
		else 
		{
			m_passengers = value;
		}
		return *this;
	}

	Bus& Bus::operator+=(int value) 
	{
		if (bool(*this)) 
		{
			m_passengers += value;
			if (m_passengers > m_seats)
			{
				m_seats = -1;
			}
		}
		return *this;
	}

	Bus& Bus::operator+=(Bus& right) 
	{
		if (bool(*this) && bool(right)) 
		{
			int space = m_seats - m_passengers;
			if (right.m_passengers <= space) 
			{
				m_passengers += right.m_passengers;
				right.m_passengers = 0;
			}
			else 
			{
				m_passengers = m_seats;
				right.m_passengers -= space;
			}
		}
		return *this;
	}

	bool Bus::operator==(const Bus& right) const 
	{
		bool equal = false;
		if (bool(*this) && bool(right) &&
			m_passengers == right.m_passengers) 
		{
			equal = true;
		}
		return equal;
	}

	int operator+(int left, const Bus& right) 
	{
		int value = left;
		if (bool(right)) 
		{
			value = left + int(right);
		}
		return value;
	}
	ostream& operator<<(ostream& ostr, const Bus& right) 
	{
		return right.display(ostr);
	}
	istream& operator>>(istream& istr, Bus& right) 
	{
		return right.read(istr);
	}
}