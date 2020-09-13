#pragma once
#include <iostream>
#include <string>
#include "myDynamicArray.h"
#include "leg.h"
using namespace std;
class animal{
	private:
		myDynamicArray<leg> legs;
		string name;
	public:
		int legLength,legCount;
		virtual void outputvoice()=0;
		animal(string x,int y,int z);
		animal(int y,int z);
		myDynamicArray<leg> get_legs();
		string getname() const;
};

