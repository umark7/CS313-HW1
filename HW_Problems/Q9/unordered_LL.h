#pragma once
#include "LL_Type.h"
#include <iostream>
#include <string>
using namespace std;

template<class T>
class unorderedLL : public LL_Type<T> {
private:
	//because this is REALLY A TEMPLATE, it doesn't have access to the variables unless we use THIS 
	//or we do the following
	using LL_Type<T>::first;
	using LL_Type<T>::last;
	using LL_Type<T>::count;

public:
	bool search(const T& searchItem) const {
		node<T>* current;
		bool found = false;

		current = first;
		while (current != nullptr) {
			if (current->info == searchItem) {
				return true;
			}
			else {
				current = current->link;
			}
		}
		return false;
	}

	void insertFirst(const T& newItem) {
		node<T>* newNode;
		newNode = new node<T>;
		newNode->info = newItem;

		newNode->link = first;
		first = newNode;
		count++;

		//if the list were empty then newNode would also be the last node in the list
		if (last == nullptr) {
			last = newNode;
		}
	}

	void insertLast(const T& newItem) {
		node<T>* newNode;
		newNode = new node<T>;
		newNode->info = newItem;
		newNode->link = nullptr;

		//if otherwise empty
		if (first == nullptr) {
			first = last = newNode;
			count++;
		}
		else {
			last->link = newNode;
			last = newNode;
			count++;
		}
	}

	//deleting a node can have several options
	//the list is empty, the first node is to be deleted, a subsequent node is to be deleted, the info is not in the list
	void deleteNode(const T& deleteItem) {
		node<T>* current;
		node<T>* trailCurrent;
		bool found;

		if (first == nullptr) {
			cout << "Can't delete from an empty list." << endl;
		}
		else {
			if (first->info == deleteItem) {   //if found in first spot
				current = first;
				first = first->link;
				count--;

				if (first == nullptr) last = nullptr; //if the list has only one node
				delete current;
			}
			else {
				found = false;
				trailCurrent = first;

				current = first->link;

				while (current != nullptr && !found) {
					if (current->info != deleteItem) {
						trailCurrent = current;
						current = current->link;
					}
					else {
						found = true;
					}
				}

				if (found) {
					trailCurrent->link = current->link;
					count--;
					
					if (last == current) last = trailCurrent; //if deleted node was the last node
					delete current;
				}
				else {
					cout << "Item not found in list." << endl;
				}
			}
		}
	}
};
