#pragma once
#include "DLL1_node.h"
#include "DLL1.h"
#include <iostream>
#include <string>

	//constructor
	
	template <class T>
	DLL1<T>::DLL1() {
		first = last = nullptr;
		count = 0;
	}
	
	template <class T>
	void DLL1<T>::print() {
		DLL1_node<T>* current;
		current = first;

		while (current != nullptr) {
			cout << "appointment begins" << current->begin << " ";
			cout << "app end" << current->end << " ";
			current = current-> next;
		}
	}
    
	template <class T> 
	int DLL1<T>::length() {
		return count;
	}

	
	template <class T>
	void DLL1<T>::insert(const T& day, const T& begin, const T& end ){
		//creating the new node
		DLL1_node<T>* newNode;
		newNode = new DLL1_node<T>; 
		newNode->day = day;
		newNode->begin = begin;
		newNode->end = end;
		
       
	    //if its an empty list
		if (last == nullptr) {
			first = last = newNode;
			count++;
		}
	    else if(count == 1){//inserting after the first node
	    		first->next = newNode;
	    		newNode->prev=first;
	    		newNode->next = nullptr;
	    		last=newNode;
		}
		else if(!IsAfter(newNode,first)){	//  case of app is before first node
		       first->prev = newNode;
		       newNode->next = first;
		       newNode->prev = nullptr;
			   count++; 
	        }
		
		else{//inserting in the middle of the list
			
			DLL1_node<T>* current;
			current = first;
			
			while(current->next!= nullptr){
				if(IsAfter(newNode,current) && IsTimeAfter(newNode,current)){//check is app is after and there is time
					DLL1_node<T>* holder;
					holder=current->prev;
					holder->next=newNode;
					newNode->next=current;
					current ->prev=newNode;
					newNode-> prev=holder;
					count++;
					break;
				}
				else if(!IsAfter(newNode,current)){current=current->next;}//if its not after keep check rest
				
				else if(current->next = nullptr){//reached end of list 
						if(current->day == 4 && !IsTimeAfter(newNode,current)){ //check if its friday & time avillability
							double x = AppLength(newNode);
						    newNode->day = 0;//start new list with first app on monday 9am
		                    newNode->begin = 9;
		                    newNode->end = 9 + x;
			            }
			            else if(current->day <= 4 && IsTimeAfter(newNode,current) ){//if there is avilable app add to end of list
			            	    current->next = newNode;
			            	    newNode->prev = current;
			            	    newNode->next = nullptr; 
			            	    count++;
			            	}
				        
				}
				if(IsApptaken(newNode,current)){
					
					// while(something) do current = current next
					NextApp(newNode,current->next);
					
					current->next = newNode;
					newNode->next = current->next;
					current->prev = newNode;
					current->next->prev = newNode;
					count++;
					
				}
	    }
        }
    }
    
    template <class T>
	void DLL1<T>::deleteAppointment(const T& day, const T& begin){
		DLL1_node<T>* current;
		DLL1_node<T>* trailCurrent;
		bool found;

		if (first == nullptr) {
			cout << "Can't delete from an empty list." << endl;
		}
		else {
			 //delet if there is only one node
			if(count == 1 ){
				current = first;
				delete current;
				first = last = nullptr;	
			}
			
			if (first->day == day && first->begin == begin) {   //if found in first spot
				current = first;
				first = first->next;
				first->prev = nullptr;
				count--;

				if (first == nullptr) last = nullptr; //if the list has only one node
				else delete current;
			}
			else {
				found = false;
				trailCurrent = first;

				current = first->next;

				while (current != nullptr && !found) {
					if (current->day != day && current->begin != begin) {
						trailCurrent = current;
						current = current->next;
					}
					else {
						found = true;
					}
				}

				if (found) {//take care of prev ptr
					trailCurrent->next = current->next;
					current->next->prev = trailCurrent;
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
    
    template <class T>
	bool DLL1<T>::IsAfter(DLL1_node<T>* appA, DLL1_node<T>* appB){
		if (appA->day < appB->day) return false; // if A is before B
		else if(appA->day > appB->day)return true; //if A is after B
		else { return appA->begin >= appB->end;}// if a begins after bB
		}
	
	
	//Is length of appA less than or = to time left in day
	template <class T>
	bool DLL1<T>::IsTimeAfter(DLL1_node<T>* appA, DLL1_node<T>* appB){
		if((AppLength(appA)) <= (17-(appB->end))) return true; 
	}
	
	template <class T>
	double DLL1<T>::TimeBetween(DLL1_node<T>* appA, DLL1_node<T>* appB){
		double x;
		x= (appB->begin - appA->end );
		return x;
	}
    
    template <class T>
	double DLL1<T>::AppLength(DLL1_node<T>* appA){
    	double x;
    	x = (appA->end)-(appA->begin);
    	return x;
	}
	
	//checks if app is taken	
	template <class T>
	bool DLL1<T>::IsApptaken(DLL1_node<T>* appA, DLL1_node<T>* appB){
		if(appA->day == appB->day && appA->begin == appB->begin){
			return true;
		}
	}
	
	//changes the details of app A to be inserted in next avilable app
	template <class T>
	void DLL1<T>::NextApp(DLL1_node<T>* appA, DLL1_node<T>* appB ){//check time for taken app & day
		//if next avilable app is right after current node
			if((TimeBetween(appA,appB)>= AppLength(appA)) || IsTimeAfter(appA,appA)){
				appA->begin = appA->end;
				appA->end = appA->begin + AppLength(appA);
			}
		//if no avilable app after current node
			else if(TimeBetween(appA,appB) < AppLength(appA)|| !IsTimeAfter(appA,appA) && appA->day < appB->day){
				if(appA->day+1 < appB->day){
					appA->day = appA->day+1;
					appA->begin = 9;
					appA->end = 9 + AppLength(appA);
				}
				else if( appA->day+1 == appB->day){
					if(appB->end -9 >= AppLength(appA)){
						appA->day = appA->day+1;
						appA->begin = 9;
						appA->end = 9 + AppLength(appA);
					}
					
					
				}
				
			}
	};
		
		
				


