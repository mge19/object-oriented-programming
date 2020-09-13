#include "myDynamicArray.h"
using namespace std;
template<typename T>
myDynamicArray<T>::myDynamicArray()
{
	size=0;
	capacity=5;
	array=new T[capacity];
	cout<<"new array of capacity="<<capacity<<" has been created"<<endl;
}
template<typename T>
int myDynamicArray<T>::getcapacity(){return capacity;}
template<typename T>
int myDynamicArray<T>::getsize(){return size;}
template<typename T>
T* myDynamicArray<T>::gethead(){return array;}
template<typename T>
void myDynamicArray<T>::add(T x)
{
	if(size>capacity)
	{
		T* temp=new T[capacity];
		for(int i=0;i<size;i++){temp[i]=array[i];}
		array=new T[2*capacity];
		for(int i=0;i<capacity;i++){array[i]=temp[i];}
		capacity*=2;
		delete temp;
		cout<<"Array resized "<<capacity<<endl;
	}
	array[size]=x;
	size++;
}
template<typename T>
T myDynamicArray<T>::remove()
{
	if(size==0){throw "Cannot remove from empty array";}
	else
	{
		resize_array();
		int x=array[size-1];
		T* temp=new T[capacity];
		for(int i=0;i<size-1;i++){temp[i]=array[i];}
		array=new T[capacity];
		for(int i=0;i<size-1;i++){array[i]=temp[i];}
		size--;
		delete temp;
		return x;
	}
}
template<typename T>
void myDynamicArray<T>::resize_array()
{
	if(size<capacity/2)
	{
		capacity/=2;
		T* temp=new T[capacity];
		for(int i=0;i<size;i++){temp[i]=array[i];}
		array=new T[capacity];
		for(int i=0;i<size;i++){array[i]=temp[i];}
		delete temp;
		cout<<"Array resized "<<capacity<<endl;		
	}
}
template<typename T>
myDynamicArray<T>::~myDynamicArray()
{
	cout<<"a dynamic array has been destroyed"<<endl;
	delete array;
}
template<typename T>
void myDynamicArray<T>::print()
{
	for(int i=0;i<size;i++){cout<<array[i]<<endl;}
}
