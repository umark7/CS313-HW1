#pragma once
#include "DLL2_node.h" 
#include <iostream>
#include <string>
using namespace std;

template<class T>
class DLL2 {

protected:
	int count;
	DLL2_node<T>* first;
	DLL2_node<T>* last;

public:
	DLL2 ();

	void print();		
	
	void insertNode(const T& newItem);
	
	void shift();

	int length();

	void initializeList();

	bool isEmptyList() const;
	
}; 
