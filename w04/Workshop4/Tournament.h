#ifndef SDDS_TOURNAMENT_H_
#define SDDS_TOURNAMENT_H_

#include "SoccerTeam.h"
#include <iostream>

namespace sdds
{
	struct SoccerTeam;
	class Tournament
	{
		char* m_name;//points to a dynamically allocated Cstring
		int m_num;//size of the dynamically allocated array of soccer team. It should be more then zero.
		SoccerTeam* m_soccer = nullptr;//pointer to the dynamically allocated array of soccerTeam
	
	public:
		void setTournament(const char* name, int noOfteam, const SoccerTeam* soccer);
		void setEmpty();
		bool isEmpty() const;
		Tournament& match(const SoccerTeam* ls);
		std::ostream& display() const;	

		Tournament(const char* name, int noOfteam, const SoccerTeam* soccer);
		Tournament();
		~Tournament();

	};

}
#endif