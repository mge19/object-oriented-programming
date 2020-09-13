/************************************
*BLG252E-Object Oriented Programming*
*Homework-1                         *
*Mehmet Gencay Ertürk - 150130118   *
************************************/    
#include "Time.h"
class Citizen
{
	private:
		char *idNo;
		char *name;
		char *surname;
		Time *appTime;
		char *appSlot;
		bool hasApp;
	public:
		Citizen(char** a,bool b,Time* c);
		Time getAppTime() const;
		~Citizen();
		char* getName() const;
		char* getSlot() const;
		bool getHasApp() const;
};
