#pragma once
#include "LL_Iterator.h"
#include "node.h"
#include <iostream>
#include <string>
using namespace std;

template<class T>
class LL_Type {
//protected:
	/*int count;
	node<T>* first;
	node<T>* last;*/

public:
	int count;
	node<T>* first;
	node<T>* last;
	
	//constructor
	LL_Type() {
		first = last = nullptr;
		count = 0;
	}

	void print() {
		node<T>* current;
		current = first;

		while (current != nullptr) {
			cout << current->info << " ";
			current = current->link;
		}
	}

	int length() {
		return count;
	}

	T front() {
		assert(first != nullptr);
		return first->info;
	}

	T back() {
		assert(last != nullptr);
		return last->info;
	}

	void destroyList() {
		node<T>* temp;

		while (first != nullptr) {
			temp = first;
			first = first->link;
			delete temp;
		}
		last = nullptr;
		count = 0;
	}

	void initializeList() {
		destroyList();
	}

	bool isEmptyList() const {
		return (first == nullptr);
	}

	//returns an iterator to the first node in the list
	LL_Iterator<T> begin() {
		LL_Iterator<T> temp(first);
		return temp;
	}
	//returns an iterator to the last node in the list
	LL_Iterator<T> end() {
		LL_Iterator<T> temp(last);
		return temp;
	}

	//copies the list, position by position
	void copyList(const LL_Type<T>& otherList) {
		node<T>* newNode;
		node<T>* current;

		//empty our list if it is not empty already
		if (first != nullptr) {
			destroyList();
		}

		if (otherList.first == nullptr) {
			first = last = nullptr;
			count = 0;
		}
		else {
			current = otherList.first;
			count = otherList.count;

			first = new node<T>;
			first->info = current->info;
			first->link = nullptr;

			last = first;

			current = current->link;

			while (current != nullptr) {
				newNode = new node<T>;
				newNode->info = current->info;
				newNode->link = nullptr;

				last->link = newNode;
				last = newNode;

				current = current->link;
			}
		}
	}

	~LL_Type() {
		destroyList();
	}

	//copy constructor
	LL_Type(const LL_Type<T>& otherList) {
		first = nullptr;
		copyList(otherList);
	}
	//assignment operator
	const LL_Type<T>& operator=(const LL_Type<T>& otherList) {
		if (this != &otherList) {
			copyList(otherList);
		}
		return *this;
	}

	virtual bool search(const T& searchItem) const = 0;
	virtual void insertFirst(const T& newItem) = 0;
	virtual void insertLast(const T& newItem) = 0;
	virtual void deleteNode(const T& deleteItem) = 0;
};




