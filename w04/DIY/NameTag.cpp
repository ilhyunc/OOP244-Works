#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

#include "NameTag.h"

using namespace std;
namespace sdds {

	void NameTag::setEmpty() {

		m_name = nullptr;
		m_extensionNum = 0;
	}

	void NameTag::deallocate() {

		if (m_name)
		{
			delete[] m_name;
			setEmpty();
		}
	}

	NameTag::NameTag() {

		setEmpty();
	}

	NameTag::~NameTag() {

		deallocate();
	}

	NameTag::NameTag(const char* name) {
		m_name = nullptr;
		set(name, NULL);
	}

	NameTag::NameTag(const char* name, int eNumber) {
		m_name = nullptr;
		set(name, eNumber);
	}

	void NameTag::set(const char* name, int eNumber) {

		deallocate();
		if (name)
		{
			int length = strlen(name);
			m_name = new char[length + 1];
			strcpy(m_name, name);

			if (length > 40) {
				m_name[40] = '\0';
			}
			m_extensionNum = eNumber;
		}
	}

	void NameTag::print() {

		if (m_name == nullptr || (m_extensionNum != 0 && (m_extensionNum < 10000 || m_extensionNum > 99999)))
		{
			cout << "EMPTY NAMETAG!" << endl;
		}
		else
		{
			int width = 0;

			if (strlen(m_name) <= 20)
			{
				width = 20;
			}
			else if (strlen(m_name) > 20)
			{
				width = 40;
			}

			cout.setf(ios::left);
			cout << "+";
			cout.width(width + 2);
			cout.fill('-');
			cout.unsetf(ios::left);
			cout << "+" << endl;

			cout.setf(ios::left);
			cout << "|";
			cout.width(width);
			cout.fill(' ');
			cout << ' ';
			cout << " |" << endl;

			cout.setf(ios::left);
			cout << "| ";
			cout.width(width);
			cout << m_name;
			cout << "|" << endl;

			cout << "|";
			cout.width(width);
			cout.fill(' ');
			cout << ' ';
			cout << " |" << endl;

			cout << "| ";
			cout << "Extension: ";
			cout.width(width - 11);
			if (m_extensionNum == 0)
			{
				cout << "N/A";
			}
			else
			{
				cout << m_extensionNum;
			}
			cout << "|" << endl;

			cout << "| ";
			cout.width(width - 1);
			cout.fill(' ');
			cout << ' ';
			cout << " |" << endl;

			cout << "+";
			cout.width(width + 2);
			cout.fill('-');
			cout.unsetf(ios::left);
			cout << "+" << endl;
		}
	}

	NameTag& NameTag::read() {
		setEmpty();

		
		return *this;
	}
}
