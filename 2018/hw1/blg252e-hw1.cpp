/************************************
*BLG252E-Object Oriented Programming*
*Homework-1                         *
*Mehmet Gencay Ertürk - 150130118   *
************************************/                          
#include <iostream>
#include <cstring>
#include <cstdlib>
#include "CivilRegistry.h"
using namespace std;
int main()
{
	int c=1;
	CivilRegistry reg;
	FILE* input=fopen("input.txt","a+");
	int x[5];
	fseek(input,52,SEEK_SET); //First line is skipping.
	char** a=new char*[5]; //a[0]=idNo,a[1]=name,a[2]=surname,a[3]=hasApp,a[4]=appSlot x[0]=day x[1]=month x[2]=year x[3]=hour x[4]=minute
	a[0]=new char[3];
	a[1]=new char[15];
	a[2]=new char[15];
	a[3]=new char[5];
	a[4]=new char[11];
	while(!feof(input))
	{
		fscanf(input,"%s\t%s\t%s\t%s\t%d-%d-%d\t%s\t%d.%d\n",a[0],a[1],a[2],a[3],&x[0],&x[1],&x[2],a[4],&x[3],&x[4]);
		if(strlen(a[4])==9) //A '0' is added to avoid confusing in finding earliest citizen.
		{
			for(int i=8;i>=0;i--)
			{
				a[4][i+1]=a[4][i];
			}
			a[4][0]='0';
			for(int i=9;i>=6;i--)
			{
				a[4][i+1]=a[4][i];
			}
			a[4][6]='0';
		}
		else if(strlen(a[4])==10)
		{
			for(int i=9;i>=0;i--)
			{
				a[4][i+1]=a[4][i];
			}
			a[4][0]='0';
		}
		if((strcmp(a[3],"TRUE")==0 && strcmp(a[4],"08.00-08.30")>=0 && strcmp(a[4],"15.30-16.00")<=0) || strcmp(a[3],"FALSE")==0) //appSlot must be between 8.00 and 16.00. hasApp must be "TRUE" or "FALSE".
		{
			if((strcmp(a[3],"TRUE")==0 && memcmp(a[4]+3,"00",2)==0 && memcmp(a[4]+9,"30",2)==0 && strtol(a[4],&a[4]+2,10)==strtol(a[4]+6,&a[4]+8,10)) || (memcmp(a[4]+3,"30",2)==0 && memcmp(a[4]+9,"00",2)==0 && strtol(a[4],&a[4]+2,10)+1==strtol(a[4]+6,&a[4]+8,10)) || strcmp(a[3],"FALSE")==0) //appSlot must be in x.00-x.30 or x.30-(x+1).00 format.
			{
				if((x[2]>=17 && x[2]<=20) && (x[1]>0 && x[1]<=12) && (x[0]>0 && x[0]<=31) && (x[3]>=0 && x[3]<24) && (x[4]>=0 && x[4]<60)) //Valid day,month and year variables.
				{
					Time* t=new Time(x);
					Citizen c(a,strcmp(a[3],"TRUE")==0,t);
					reg.insertCitizen(c);
					delete t; //To avoid from memory leak.
				}
			}
		}
	}
	cout<<"Citizens with an appointment:\n";
	do
	{
		c=reg.removeCitizen(0);
		cout<<endl;
	}while(c!=0);
	cout<<"Citizens without an appointment:\n";
	c=1;
	do
	{
		c=reg.removeCitizen(1);
		cout<<endl;
	}while(c!=0);
	delete[] a; //To avoid from memory leak.
	delete a[0];
	delete a[1];
	delete a[2];
	delete a[3];
	delete a[4];	
	fclose(input);
	getchar();
	return 0;
}
