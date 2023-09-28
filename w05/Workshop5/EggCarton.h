#ifndef SDDS_EGGCARTON_H
#define SDDS_EGGCARTON_H
#include <iostream>
using namespace std;

namespace sdds {

	const int RegularEggWieght = 50;
	const int JumboEggWieght = 75;

	class EggCarton {
		int m_size;
		int m_noOfEggs;
		bool m_isJumbo;;
		void setBroken();
		ostream& displayCarton(int size, int noOfEggs, bool jumbo, ostream& ostr)const;

	public:
		EggCarton(int size = 6, int noOfEggs = 0, bool jumboSize = false);

		ostream& display(ostream& ostr = cout) const;
		istream& read(istream& istr = cin);
		
		// Type Conversion Operator overloads
		operator bool() const;
		operator int() const;
		operator double() const;

		//Unary Operator overloads
		EggCarton& operator--();
		EggCarton& operator++();
		EggCarton operator--(int);
		EggCarton operator++(int);

		//Binary Member Operators
		EggCarton& operator=(int value);
		EggCarton& operator+=(int value);
		EggCarton& operator+=(EggCarton& right);
		bool operator==(const EggCarton& right) const;
	};

	int operator+(int left, const EggCarton& right);
	ostream& operator<<(ostream& ostr, const EggCarton& right);
	istream& operator>>(istream& istr, EggCarton& right);

}
#endif