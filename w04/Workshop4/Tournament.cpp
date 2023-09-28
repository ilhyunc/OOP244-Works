#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

#include "Tournament.h"
#include "SoccerTeam.h"

using namespace std;
namespace sdds
{
	void Tournament::setTournament(const char* name, int noOfteam, const SoccerTeam* soccer)
	{
		if (name == nullptr || strlen(name) == 0 || noOfteam <= 0 || soccer == nullptr)
		{
			setEmpty();
		}
		else
		{
			m_num = noOfteam;
			m_name = new char[strlen(name) + 1];
			strcpy(m_name, name);
			m_soccer = new SoccerTeam[noOfteam + 1];
			for (int i = 0; i < noOfteam; i++)
			{
				m_soccer[i] = soccer[i];
			}
		}
	}

	void Tournament::setEmpty()
	{
		m_name = nullptr;
		m_num = 0;
		m_soccer = nullptr;
	}

	bool Tournament::isEmpty() const
	{
		return (m_name != nullptr) && (m_soccer != nullptr) && (m_num > 0);
	}

	Tournament& Tournament::match(const SoccerTeam* ls)
	{
		for (int i = 0; i < m_num - 1; i++) {
			if (m_soccer[i].m_noFouls < m_soccer[i + 1].m_noFouls) 
			{
				m_soccer[i + 1].m_noFouls *= 2;
				m_soccer[i + 1].m_fines *= 1.2;
				m_soccer[i].m_goals += 1;
			}
			else if (m_soccer[i + 1].m_noFouls > MAX_FOUL) 
			{
				setEmpty();
			}
		}
    		return *this;// TODO: insert return statement here
	}

	Tournament::Tournament(const char* name, int noOfteam, const SoccerTeam* soccer)//=========================================
	{
		//
		setTournament(name, noOfteam, soccer);
	}

	std::ostream& Tournament::display() const
	{
		if (isEmpty())//---------
		{
			cout << "Tournament name:" << m_name << endl;
			cout << "list of the teams" << endl;
			cout.width(45);
			cout.fill(' ');
			cout << "Fines";
			cout.width(10);
			cout.fill(' ');
			cout << "Fouls";
			cout.width(10);
			cout.fill(' ');
			cout << "Goals" << endl;
			for (int i = 0; i < m_num; i++)
			{
				cout << "Team[" << i + 1 << "]" << " :";
				m_soccer[i].display();
			}
		}
		else
		{
			cout << "Invalid Tournament";
		}

		return cout;// TODO: insert return statement here
	}

	Tournament::Tournament()
	{
		setEmpty();
	}

	Tournament::~Tournament()
	{
		delete[] m_name;
		delete[] m_soccer;
	}
}
