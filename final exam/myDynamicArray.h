#pragma once
#include <iostream>
template<typename T>
class myDynamicArray{
	private:
		int size,capacity;
		T* array;
		void resize_array();
	public:
		myDynamicArray();
		int getcapacity();
		int getsize();
		T* gethead();
		void add(T x);
		T remove();
		void print();
		~myDynamicArray();
};

