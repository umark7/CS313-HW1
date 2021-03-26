#pragma once
#include "DLL2_node.h"
#include "DLL2.h"
#include <iostream>
#include <string>
using namespace std;


	//constructor
	template <class T>
	DLL2<T>::DLL2() {
		first = last = nullptr;
		count = 0;
	}

	template <class T>
	void DLL2<T>::print() {
		DLL2_node<T>* current;
		current = first;

		while (current != nullptr) {
			cout << current->info << " ";
			current = current-> next;
		}
	}
	
	template <class T>
	void DLL2<T>::insertNode(const T& newItem){
		//creating the new node
		DLL2_node<T>* newNode;
		newNode = new DLL2_node<T>;
		newNode->info = newItem;
       
	    //if its an empty list
		if (first == nullptr) {
			first = last = newNode;
		}
	    else{ //adding nodes 
			newNode->next = first;
			first->prev = newNode;
		    first = newNode;
		    count++;
	    }
		
	} 
	
	template <class T>
	void DLL2<T>::shift(){
		
		DLL2_node<T>* newLast;
		DLL2_node<T>* newFirst;
		
		newLast = last->prev; 
		newFirst = last;	
	
		last->next = first;
		first->prev = last;
		last->prev = nullptr;
		newLast->next = nullptr;
		
		first = newFirst;
		last = newLast;
			
	}

	template <class T>
	int DLL2<T>::length() {
		return count;
	}

	/*template<typename T>
	void DLL2<T>::initializeList() {
		destroyList();
	}*/
	
	template <class T>
	bool DLL2<T>::isEmptyList() const {
		return (first == nullptr);
	};
