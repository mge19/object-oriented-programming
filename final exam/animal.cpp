#include "animal.h"
#include "myDynamicArray.cpp"
#include <iostream>
using namespace std;
animal::animal(string x,int y,int z):name(x),legLength(y),legCount(z)
animal::animal(int y,int z):legLength(y),legCount(z)
myDynamicArray<leg> animal::get_legs(){return legs;}
string animal::getname() const{return name;}
