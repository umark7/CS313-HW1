#pragma once
#include "node.h"
#include <iostream>
#include <string>
using namespace std;


template<class T>
class LL_Iterator {
private:
	node<T>* current;

public:
	//constructors
	LL_Iterator() {	current = nullptr; }
	LL_Iterator(node<T>* ptr) { current = ptr; }

	//operator overloads
	T operator*() {
		return current->info;
	}
	LL_Iterator<T> operator++() {
		current = current->link;
		return *this;
	}
	bool operator==(const LL_Iterator<T>& right) const {
		return (current == right.current);
	}
	bool operator!=(const LL_Iterator<T>& right) const {
		return (current != right.current);
	}
};



