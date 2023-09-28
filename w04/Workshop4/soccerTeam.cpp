#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

#include "SoccerTeam.h"

using namespace std;
namespace sdds {
	void SoccerTeam::setTeam(const SoccerTeam& team)
	{
		setName(team.m_teamName);
		setFine(team.m_fines, team.m_noFouls);
	}

	void SoccerTeam::setName(const char* tname)
	{
		if (tname && tname[0] != '\0')
		{
			strcpy(m_teamName, tname);
		}
		else
		{
			m_teamName[0] = '\0';
		}
	}

	void SoccerTeam::setFine(double fines, int foul)
	{
		if (fines >= 0.0 && foul >= 0)
		{
			m_fines = fines;
			m_noFouls = foul;
			m_goals = 0;
		}
		else
		{
			setEmpty();
		}
	}

	void SoccerTeam::setEmpty()
	{
		m_teamName[0] = '\0';
		m_noFouls = -1;
		m_fines = -1.0;
		m_goals = 0;
	}

	bool SoccerTeam::isEmpty() const
	{
		return ((m_teamName[0] == '\0') || (m_fines < 0) || (m_noFouls < 0) || (m_noFouls > MAX_FOUL));//------------------
	}

	void SoccerTeam::calFines()
	{
		m_fines *= 1.2;
	}

	int SoccerTeam::fouls() const
	{
		return m_noFouls;
	}

	SoccerTeam::SoccerTeam()
	{
		setEmpty();
	}

	SoccerTeam::SoccerTeam(const char* tname, double fines, int foul)
	{
		setName(tname);
		setFine(fines, foul);
	}

	std::ostream& SoccerTeam::display() const
	{
		if (!isEmpty())
		{
			cout.width(30);
			cout.fill(' ');
			cout.setf(ios::left);
			cout << m_teamName;

			cout.width(6);
			cout.setf(ios::fixed);// double type ÀÏ¶§
			cout.precision(2);
			cout.fill(' ');
			cout.unsetf(ios::left);
			cout << m_fines;

			
			cout.width(6);
			cout.fill(' ');
			cout << m_noFouls;

			cout.width(10);
			cout.fill(' ');
			cout.unsetf(ios::left);

			if (m_goals > 0)
			{
				cout << m_goals << "w" << endl;
			}
			else
			{
				cout << m_goals << endl;
			}
		}
		else
		{
			cout << "Invalid Team";
		}

		return cout;// TODO: insert return statement here
	}

}