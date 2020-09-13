/************************************
*BLG252E-Object Oriented Programming*
*Homework-1                         *
*Mehmet Gencay Ertürk - 150130118   *
************************************/    
#include <iostream>
#include "Citizen.h"
#include <cstring>
using namespace std;
Citizen::Citizen(char** a,bool b,Time* c)
{
	idNo=new char[3];
	strcpy(idNo,a[0]);
	name=new char[strlen(a[1])];
	strcpy(name,a[1]);
	surname=new char(strlen(a[2]));
	strcpy(surname,a[2]);	
	hasApp=b;
	appTime=c;
	appSlot=new char[9];
	strcpy(appSlot,a[4]);
}
Time Citizen::getAppTime() const
{
	return *appTime;
}
Citizen::~Citizen()
{
	delete name;
	delete surname;
	delete idNo;
	delete appTime;
	delete appSlot;
}
char* Citizen::getName() const
{
	return name;
}
char* Citizen::getSlot() const
{
	return appSlot;
}
bool Citizen::getHasApp() const
{
	return hasApp;
}
