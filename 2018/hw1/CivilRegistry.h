/************************************
*BLG252E-Object Oriented Programming*
*Homework-1                         *
*Mehmet Gencay Ertürk - 150130118   *
************************************/    
#include "Citizen.h"
#include <list>
class CivilRegistry
{
	private:
		std::list<Citizen> wApp,wOutApp;
	public:
		void insertCitizen(const Citizen& c);
		int removeCitizen(int x);
};
