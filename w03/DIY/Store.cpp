#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

#include "Store.h"

using namespace std;
namespace sdds
{
	void Store::setStore(const char* sName, int no) {

		setEmpty();
		if (sName && sName[0] != '\0' && no > 0 && no < MAX_NUM_TOYS)
		{
			strncpy(m_sName, sName, MAX_SNAME);
			m_noOfToys = no;
		}
		else
		{
			setEmpty();
		}
	}

	void Store::setToys(const char* tname, int sku, double price, int age) {

		if (m_addToys < m_noOfToys)
		{
			m_toy[m_addToys].addToys(tname, sku, price, age);
			m_addToys++;
		}
	}

	void Store::display()const {

		if (m_sName[0] == '\0')
		{
			cout << "Invalid Store" << endl;
		}
		else
		{
			cout.fill('*');
			cout.width(60);
			cout << '*' << endl;
			cout << m_sName << endl;
			cout.width(60);
			cout << '*' << endl;
			cout << "List of the toys" << endl;

			cout.fill(' ');
			cout.width(30);
			cout << "SKU";
			cout.width(10);
			cout << "Age";
			cout.width(11);
			cout << "Price";
			cout.width(10);
			cout << "Sale" << endl;
			for (int i = 0; i < m_addToys; i++)
			{
				cout << "Toy[" << i + 1 << "] :";
				m_toy[i].display();
			}

		}
	}

	void Store::find(int sku) {

		for (int i = 0; i < m_addToys; i++)
		{
			if (m_toy[i].checkSku(sku))
			{
				m_toy[i].isSale(true);
				m_toy[i].calSale();
			}
		}
	}

	void Store::setEmpty() {

		m_sName[0] = '\0';
		m_noOfToys = 0;
		m_addToys = 0;
		for (int i = 0; i < MAX_NUM_TOYS; i++)
		{
			m_toy[i] = Toys();
		}
	}


};