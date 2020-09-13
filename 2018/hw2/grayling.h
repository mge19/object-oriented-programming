#include <iostream>
#include <string>
using namespace std;
class Grayling{
	protected:
		short age;
		string name,mutated_to;
		char gender;
		bool alive,mutant;
		double mpi,mp,mutate_at;
	public:
		virtual void aging(){return;}
		virtual void givebirth(){return;}
		virtual void print(){return;}
};
class Grayling1:public Grayling
{
	public:
		Grayling1(){alive=false;}
		Grayling1(char x,string y)
		{
			gender=x;
			name=y;
			age=0;
			alive=true;
			mutant=false;
			mpi=0.3;
			mp=0;
			mutate_at=0.6;
			mutated_to=" ";
		}
		Grayling1(const Grayling1& g1,char x,string y)
		{
			gender=x;
			name=y;
			age=g1.age;
			alive=g1.alive;
			mutant=g1.mutant;
			mpi=g1.mpi;
			mp=g1.mp;
			mutate_at=g1.mutate_at;
			mutated_to=g1.mutated_to;
		}
		void print()
		{
			cout<<"Grayling 1";
			if(mutant){cout<<" Mutated to:"<<mutated_to;}
			cout<<" -> Age:"<<age<<" Name:"<<name<<" Gender:"<<gender<<" MPI:"<<mpi*100<<" MP:"<<mp*100<<" Mutate at:"<<mutate_at*100<<endl;
		}
		void aging()
		{
			if(alive)
			{
				age+=1;
				mp+=mpi;
				cout<<"AGING: ";
				print();
				if(age==4)
				{		
					cout<<name<<" is dead because of AGING!"<<endl;
					alive=false;
				}
				if(mp==mutate_at)
				{
					mpi=0.4;
					mutated_to="Grayling 2";
					mutant=true;
					mutate_at=0.8;
					mp=0;
					cout<<"Mutated TO:"<<mutated_to<<endl;
				}
			}
			else{cout<<"Trying to AGING BUT "<<name<<" is not alive"<<endl;}
		}
		void givebirth()
		{
			if(!alive){cout<<"Trying to GIVE BIRTH BUT "<<name<<" is not alive"<<endl;}
			else if(gender=='m'){cout<<"Trying to GIVE BIRTH BUT "<<name<<" has not ability to give birth."<<endl;}
			else
			{
				if(mutant){cout<<name<<" gave birth to 1 offsprings."<<endl;}
				else {cout<<name<<" gave birth to 2 offsprings."<<endl;}
			}
		}
};
class Grayling2:public Grayling
{
	public:
		Grayling2(){alive=false;}
		Grayling2(char x,string y)
		{
			gender=x;
			name=y;
			age=0;
			alive=true;
			mutant=false;
			mpi=0.4;
			mp=0;
			mutate_at=0.8;
			mutated_to=" ";
		}
		Grayling2(const Grayling2& g1,char x,string y)
		{
			gender=x;
			name=y;
			age=g1.age;
			alive=g1.alive;
			mutant=g1.mutant;
			mpi=g1.mpi;
			mp=g1.mp;
			mutate_at=g1.mutate_at;
			mutated_to=g1.mutated_to;
		}
		void print()
		{
			cout<<"Grayling 2";
			if(mutant){cout<<" Mutated to:Grayling 3";}
			cout<<" -> Age:"<<age<<" Name:"<<name<<" Gender:"<<gender<<" MPI:"<<mpi*100<<" MP:"<<mp*100<<" Mutate at:"<<mutate_at*100<<endl;
		}
		void aging()
		{
			if(alive)
			{
				age+=1;
				mp+=mpi;
				cout<<"AGING: ";
				print();
				if(age==3)
				{
					cout<<name<<" is dead because of AGING!"<<endl;
					alive=false;
				}
				if(mp==mutate_at)
				{
					mpi=0.5;
					mutate_at=1;
					mutated_to="Grayling 3";
					mutant=true;
					mp=0;
					cout<<"Mutated TO:"<<mutated_to<<endl;
				}
			}
			else {cout<<"Trying to AGING BUT "<<name<<" is not alive"<<endl;}
		}
		void givebirth()
		{
			if(!alive){cout<<"Trying to GIVE BIRTH BUT "<<name<<" is not alive"<<endl;}
			else if(gender=='m'){cout<<"Trying to GIVE BIRTH BUT "<<name<<" has not ability to give birth."<<endl;}
			else
			{
				if(mutant)
				{
					alive=false;
					cout<<"Trying to GIVE BIRTH BUT "<<name<<" is not alive."<<endl;
				}
				else {cout<<name<<" gave birth to 1 offsprings."<<endl;}
			}
		}	
};
class Grayling3:public Grayling
{
	public:
		Grayling3(){alive=false;}
		Grayling3(char x,string y)
		{
			gender=x;
			name=y;
			age=0;
			alive=true;
			mutant=false;
			mpi=0.5;
			mp=0;
			mutate_at=1;
			mutated_to=" ";
		}
		Grayling3(const Grayling3& g1,char x,string y)
		{
			gender=x;
			name=y;
			age=g1.age;
			alive=g1.alive;
			mutant=g1.mutant;
			mpi=g1.mpi;
			mp=g1.mp;
			mutate_at=g1.mutate_at;
			mutated_to=g1.mutated_to;
		}
		void print()
		{
			cout<<"Grayling 3 -> Age:"<<age<<" Name:"<<name<<" Gender:"<<gender<<" MPI:"<<mpi*100<<" MP:"<<mp*100<<" Mutate at:"<<mutate_at*100<<endl;
		}
		void aging()
		{
			if(alive)
			{
				age+=1;
				mp+=mpi;
				cout<<"AGING: ";
				print();
				if(mp==mutate_at)
				{	
					alive=false;
					cout<<name<<" is dead because of HIGH MUTATION RATE!"<<endl;
				}
			}
			else {cout<<"Trying to AGING BUT "<<name<<" is not alive"<<endl;}
		}
		void givebirth()
		{
			if(gender=='m'){cout<<"Trying to GIVE BIRTH BUT "<<name<<" has no ability to give birth."<<endl;}
			else
			{
				alive=false;
				cout<<"Trying to GIVE BIRTH BUT "<<name<<" is not alive."<<endl;
			}
		}	
};
