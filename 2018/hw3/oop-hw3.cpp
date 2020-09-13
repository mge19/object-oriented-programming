/************************************
*BLG252E-Object Oriented Programming*
*Homework-1                         *
*Mehmet Gencay Ertürk - 150130118   *
************************************/    
#include <iostream>
using namespace std;
class Money{
	int lira,kurus;
	public:
		Money(){}
		Money(int l,int k);
		bool operator<(const Money& m);
		bool operator>(const Money& m);
		bool operator==(const Money& m);
		int getlira();
		void setlira(int sayi);
		int getkurus();
		void setkurus(int sayi);
};
int Money::getlira(){return lira;}
int Money::getkurus(){return kurus;}
void Money::setlira(int sayi){lira=sayi;}
void Money::setkurus(int sayi)
{
	kurus=sayi%100;
	lira+=sayi/100;
}
Money::Money(int l,int k)
{
	try
	{
		if(l<0){throw l;}
	}
	catch(int l){cerr<<"The amount of money can not be below zero!"<<endl;}
	lira=l+k/100;
	kurus=k%100;
}
bool Money::operator==(const Money& m)
{
	return (lira == m.lira) && (m.lira == m.kurus);
}
bool Money::operator<(const Money& m)
{
	if (lira != m.lira) return lira < m.lira;
	else if(kurus != m.kurus) return kurus < m.kurus;
	else return !(*this == m);
}
bool Money::operator>(const Money& m)
{
   return !(*this < m) && !(*this == m);
}
template<typename T> class genericArray
{
	int length;
	public:
		T* elements;
		T total;
		T sum();
		~genericArray();
		genericArray(int number);
};
template<typename T> genericArray<T>::~genericArray(){delete elements;}
template<typename T> genericArray<T>::genericArray(int number)
{
	elements=new T[number];
	length=number;
}
template<> Money genericArray<Money>::sum()
{
	Money result(0,0);
	for(int i=0;i<length;i++)
	{
		result.setlira(result.getlira()+elements[i].getlira());
		result.setkurus(result.getkurus()+elements[i].getkurus());
	}
	cout<<"The total amount for money objects array is "<<result.getlira()<<" lira "<<result.getkurus()<<" kurus."<<endl;
	if(result>Money(100,0))
	{
		result.setlira(result.getlira()+5);
		cout<<"You have won 5 TL bonus, your new amount is "<<result.getlira()<<" lira "<<result.getkurus()<<" kurus."<<endl;
	}
	return result;
}
template<> int genericArray<int>::sum()
{
	int result=0;
	for(int i=0;i<length;i++){result+=elements[i];}
	cout<<"The total of integer array is "<<result<<endl;
	if(result>100)
	{
		result+=5;
		cout<<"You have won 5 points bonus new total is "<<result<<endl;
	}
	return result;
}
template<> double genericArray<double>::sum()
{
	double result=0;
	for(int i=0;i<length;i++){result+=elements[i];}
	cout<<"The total of double array is "<<result<<endl;	
	if(result>100)
	{
		result+=5;
		cout<<"You have won 5 points bonus new total is "<<result<<endl;
	}
	return result;
}
int main()
{
	genericArray<int> m1(5);
	genericArray<double> m2(5);
	genericArray<Money> m3(5);
	Money d(-1,89);
	Money a(10,124);
	Money b(10,5);
	Money c(43,7);
	Money k(50,97);
	Money m(10,20);
	m3.elements[0]=a;
	m3.elements[1]=b;
	m3.elements[2]=c;
	m3.elements[3]=k;
	m3.elements[4]=m;
	m2.elements[0]=12.5;
	m2.elements[1]=11.6;
	m2.elements[2]=13.9;
	m2.elements[3]=23.7;
	m2.elements[4]=130.7;
	m1.elements[0]=1;
	m1.elements[1]=2;
	m1.elements[2]=5;
	m1.elements[3]=9;
	m1.elements[4]=90;
	m3.total=m3.sum();
	m2.total=m2.sum();
	m1.total=m1.sum();
	getchar();
	return 0;
}
