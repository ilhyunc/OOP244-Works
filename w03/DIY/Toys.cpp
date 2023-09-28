#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

#include "Store.h"
#include "Toys.h"

using namespace std;
namespace sdds
{
	Toys::Toys()
	{
		m_tname[0] = '\0';
		m_sku = 0;
		m_price = 0.0;
		m_age = 0;
		m_onSale = false;
	}

	void Toys::addToys(const char* tname, int sku, double price, int age) {

		if (tname && tname[0] != '\0'  && sku > 9999999 && sku < 100000000 && price > 0.0)
		{
			strncpy(m_tname, tname, MAX_TNAME);
			m_sku = sku;
			m_price = price;
			m_age = age;
		}
	}

	void Toys::isSale(bool sale) {

		m_onSale = sale;
	}

	void Toys::calSale() {

		m_price -= (m_price * 0.2);
	}

	void Toys::display()const {

		if (m_tname[0] != '\0')
		{
			cout.setf(ios::left);
			cout.width(15);
			cout << m_tname;
			cout.unsetf(ios::left);

			cout.width(10);
			cout << m_sku;
			cout.width(6);
			cout << m_age;
			cout.unsetf(ios::right);
			cout.setf(ios::fixed);
			cout.width(12);
			cout.precision(2);
			cout << m_price;

			if (m_onSale)
			{
				cout.width(10);
				cout << "On Sale";
				cout << " " << endl;
			}
			else
			{
				cout.width(8);
				cout << " " << endl;
			}
		}
		else
		{
			cout << "Invalid Toy" << endl;
		}
	}

	bool Toys::checkSku(int sku)	{

		return m_sku == sku && !m_onSale;
	}

}