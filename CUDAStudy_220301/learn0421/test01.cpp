#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <typeinfo>

using namespace std;


void myMalloc(void* ptr, int size) {
	// cout << "Addr in func before malloc1: " << ptr << endl;
  	ptr = malloc(size);
  	// cout << "Addr in func after malloc1: " << ptr << endl;
  	return;
}

void myMalloc2(void** ptr, int size) {
	// cout << "Addr in func before malloc2: " << *ptr << endl;
  	*ptr = malloc(size);
  	// cout << "Addr in func after malloc2: " << *ptr << endl;
  	return;
}


int main()
{
	int* ptr = (int*)malloc(sizeof(int));
	cout << "Addr in main: " << ptr << endl;
	cout << "Addr in main: " << *ptr << endl;
	cout << "Addr in main: " << &ptr << endl;
	cout<<"========================"<<endl;


	myMalloc(ptr, 4*sizeof(int));
	cout << "Addr in main after func1: " << ptr << endl;
	cout << "Addr in main after func1: " << *ptr << endl;
	cout << "Addr in main after func1: " << &ptr << endl;

	myMalloc2((void**)&ptr, 4*sizeof(int));
	cout<<"========================"<<endl;
	cout << "Addr in main after func2: " << ptr << endl;
	cout << "Addr in main after func2: " << *ptr << endl;
	cout << "Addr in main after func2: " << &ptr << endl;
}