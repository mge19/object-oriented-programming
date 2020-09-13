//BLG252E-Object Oriented Programming
//Homework-2
//Mehmet Gencay Ertürk-150130118
/*Necessary Descriptions:
Person class has two string attributes:Name and surname.
Person class has also getter and setters for name and surname. 
Owner and Courier classes are derived publicly from Person class.
Owner class has a double ownership attribute and a setter for it.
Owner class has two constructors:An empty constructor with no parameters for convenience and a constructor with two string parameters which define name and surname of base Person.
Courier class has a string vehicle attribute and a getter for it
Courier class has two constructors:An empty constructor with no parameters for convenience and a constructor with three string parameters which define name,surname and vehicle type.
Courier class also has a overloaded Boolean == operator which checks equality for all string parameters.
Transportation capacity of couriers are 10kg for bicycles,35 kg for motorcycles and 200kg for cars.
Vehicle of any courier can only be "car","bicycle" or "motorcycle" otherwise program terminates.
Business class has name and address strings,couriers and owners arrays and counters for them.
Business class has a constructor with two string parameters for name and address and a owner array parameter and an integer parameter for number of owners.
Couriers can be hired or fired.
When a couriers are hired or fired, courier array is reallocated and counters are updated.
Courier hire and fire functions takes a constant courier parameter.
When couriers are fired, couriers that are in right of found courier are shifted by one unit left.
If a courier which is equal to passes courier cannot be found in couriers array,an error message is printed.
Business class has an array index operator which returns courier at relative index in couriers array.
Business class has functions for listing owners and couriers.
Paranthesis operator of business class prints name,address,owners and couriers.
"calculate_shipment_capacity" method of Business class calculates the total transportation capacity of couriers.
Provided main function is used for test the code.
*/
#include <bits/stdc++.h>
using namespace std;
class Person{
	private:
		string name,surname; 
	public:
		const string& getname(); 
		const string& getsurname();
		void setname(const string& str);
		void setsurname(const string& str);
};
class Owner:public Person{
	private:
		double ownership; 
	public: 
		Owner(); 
		void setownership(double x);
		Owner(const string& str1,const string& str2);
};
class Courier:public Person{
	private:
		string vehicle;
	public:
		Courier();
		const string& getvehicle();
		Courier(const string& str1,const string& str2,const string& str3);
		bool operator==(Courier& c);
};
class Business{
	private:
		string name,address;
		Courier* couriers;
		Owner* owners;
		int number_of_couriers,number_of_owners;
	public:
		Business(const string& str1,const string& str2,Owner* ows,int size);
		void hire_courier(const Courier& c);
		void fire_courier(Courier& c);
		void list_couriers();
		void list_owners();
		int calculate_shipment_capacity();
		void operator()();
		const Courier& operator[](int index);
		~Business();
};
const string& Person::getname(){return name;}
const string& Person::getsurname(){return surname;}
void Person::setname(const string& str){name=str;}
void Person::setsurname(const string& str){surname=str;}
Owner::Owner(){}
Owner::Owner(const string& str1,const string& str2)
{
	setname(str1);
	setsurname(str2);
}
void Owner::setownership(double x){ownership=x;}
Courier::Courier(){}
Courier::Courier(const string& str1,const string& str2,const string& str3)
{
	if(str3!="car" && str3!="bicycle" && str3!="motorcycle")
	{
		cout<<"Error! Invalid vehicle type."<<endl;
		exit(1);
	}
	setname(str1);
	setsurname(str2);
	vehicle=str3;
}
const string& Courier::getvehicle(){return vehicle;}
bool Courier::operator==(Courier& c)
{
	return (getname()==c.getname()) && (getsurname()==c.getsurname()) && (vehicle==c.vehicle);
}
Business::Business(const string& str1,const string& str2,Owner* ows,int size)
{
	name=str1;
	address=str2;
	number_of_couriers=0;
	number_of_owners=size;
	owners=new Owner[number_of_owners];
	copy(ows,ows+number_of_owners,owners);
	double x=100.0/number_of_owners;
	for(int i=0;i<number_of_owners;i++){owners[i].setownership(x);}
}
void Business::hire_courier(const Courier& c)
{
	if(number_of_couriers==0)
	{
		couriers=new Courier;
		couriers[0]=c;
	}
	else
	{
		Courier* temp=new Courier[number_of_couriers];
		copy(couriers,couriers+number_of_couriers,temp);
		couriers=new Courier[number_of_couriers+1];
		copy(temp,temp+number_of_couriers,couriers);
		couriers[number_of_couriers]=c;
		delete[] temp;
	}
	number_of_couriers++;
}
void Business::fire_courier(Courier& c)
{
	int number=0;
	for(int i=0;i<number_of_couriers;i++)
	{
		if(couriers[i]==c)
		{
			for(int j=i;j<number_of_couriers-1;j++){couriers[j]=couriers[j+1];}
			number++;
		}
	}
	if(number==0)
	{
		cout<<"Error! Given courier not found."<<endl;
		return;
	}
	number_of_couriers-=number;
	Courier* temp=new Courier[number_of_couriers];
	copy(couriers,couriers+number_of_couriers,temp);
	couriers=new Courier[number_of_couriers];
	copy(temp,temp+number_of_couriers,couriers);
	delete[] temp;
}
int Business::calculate_shipment_capacity()
{
	int result=0;
	for(int i=0;i<number_of_couriers;i++)
	{
		if(couriers[i].getvehicle()=="bicycle"){result+=10;}
		else if(couriers[i].getvehicle()=="motorcycle"){result+=35;}
		else{result+=200;}
	}
	return result;
}
void Business::list_couriers()
{
	for(int i=0;i<number_of_couriers;i++){cout<<couriers[i].getname()<<" "<<couriers[i].getsurname()<<" "<<couriers[i].getvehicle()<<endl;}
}
void Business::list_owners()
{
	for(int i=0;i<number_of_owners;i++){cout<<owners[i].getname()<<" "<<owners[i].getsurname()<<endl;}
}
void Business::operator()()
{
	cout<<name<<" "<<address<<endl;
	list_owners();
	list_couriers();
}
const Courier& Business::operator[](int index)
{
	if(index>=number_of_couriers || index<0)
	{
		cout<<"Error! Invalid index."<<endl;
		exit(1);
	}
	return couriers[index];
}
Business::~Business()
{
	delete[] owners;
	delete[] couriers;
}
int main()
{
	Owner o1 = Owner("Owner_name1", "surname1");
    Owner o2 = Owner("Owner_name2", "surname2");
    Owner* owner_arr = new Owner[2];
    owner_arr[0] = o1;
    owner_arr[1] = o1;
	Business atlas = Business("Atlas", "Maslak Istanbul/Turkey", owner_arr, 2);    
	atlas.list_owners();
	Courier c1 = Courier("Courier", "surname1", "car");
    Courier c2 = Courier("Courier", "surname2", "motorcycle");
    Courier c3 = Courier("Courier", "surname3", "motorcycle");    
    atlas.hire_courier(c1);
    atlas.hire_courier(c2);
    atlas.hire_courier(c3);
    atlas();
    Courier cour=atlas[1];
    atlas.fire_courier(cour);
    atlas.list_couriers();
    cout<<atlas.calculate_shipment_capacity()<<endl;
	getchar();
	return 0;
}
