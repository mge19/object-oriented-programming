/************************************
*BLG252E-Object Oriented Programming*
*Homework-1                         *
*Mehmet Gencay Ertürk - 150130118   *
************************************/    
#include "CivilRegistry.h"
#include <list>
#include <cstring>
#include <iostream>
using namespace std; 
void CivilRegistry::insertCitizen(const Citizen& c)
{
	if(c.getHasApp()) wApp.push_back(c);
	else wOutApp.push_back(c);
}
int CivilRegistry::removeCitizen(int x)
{
	if(x==0)
	{
		if(wApp.empty()) {return 0;} //0 if list is empty
		else
		{
			list<Citizen>::iterator it=wApp.begin(),min=wApp.begin();
			it++;
			while(it!=wApp.end()) //Earliest citizen is being searched.
			{
				if(it->getAppTime().getDate()<=min->getAppTime().getDate())
				{
					if(strcmp(it->getSlot(),min->getSlot())<0 || (strcmp(it->getSlot(),min->getSlot())==0 && it->getAppTime()<min->getAppTime())) {min=it;}
				}
				it++;
			}
			cout<<min->getName();
			wApp.erase(min);
			return 1;
		}
	}
	else if(x==1)
	{
		if(wOutApp.empty()) {return 0;} //0 if list is empty
		else
		{
			list<Citizen>::iterator it=wOutApp.begin(),min=wOutApp.begin();
			it++;
			while(it!=wOutApp.end()) //Earliest citizen is being searched.
			{
				if(it->getAppTime()<min->getAppTime()) {min=it;}
				it++;
			}
			cout<<min->getName();
			wOutApp.erase(min);
			return 1;
		}
	}
}
