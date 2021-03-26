#pragma once
#include "DLL1_node.h" 
#include <iostream>
#include <string>
using namespace std;

template <class T>
class DLL1 {

protected:
	int count;
	DLL1_node<T>* first;
	DLL1_node<T>* last;
	
public:
	DLL1();
	void print();
	int length();
	void insert(const T& day, const T& begin, const T& end );
	void deleteAppointment(const T& day, const T& begin);
	bool IsAfter(DLL1_node<T>* appA, DLL1_node<T>* appB);
	bool IsTimeAfter(DLL1_node<T>* appA, DLL1_node<T>* appB);
	double TimeBetween(DLL1_node<T>* appA, DLL1_node<T>* appB);
	double AppLength(DLL1_node<T>* appA);
	bool IsApptaken(DLL1_node<T>* appA, DLL1_node<T>* appB);
	void NextApp(DLL1_node<T>* appA,DLL1_node<T>* appB );
	
};
	
	
