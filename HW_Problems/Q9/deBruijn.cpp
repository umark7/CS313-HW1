#include <iostream>
#include <math.h>
#include <time.h>
#include <iostream>
#include <stdlib.h>  
#include <ctime>
#include <cstdlib>
#include <vector>
#include <chrono>
#include <bits/stdc++.h>
#include "node.h"
#include "LL_Type.h"
#include "LL_Iterator.h"
using namespace std;
using namespace std::chrono;

 //creates a vector of vectors with all possible combinations - code from geeks from geeks
 void Combin(vector<vector<int> >& ans,vector<int>& tmp, int n, int left, int k)
{
    // Pushing this vector to a vector of vector
    if (k == 0) {
        ans.push_back(tmp);
        return;
    }
  
    // i iterates from left to n. First time
    // left will be 1
    for (int i = left; i <= n; ++i)
    {
        tmp.push_back(i);
        Combin(ans, tmp, n, i + 1, k - 1);
  
        // Popping out last inserted element
        // from the vector
        tmp.pop_back();
    }
}
  
// Prints all combinations of size k of numbers
// from 1 to n.
vector<vector<int> > makeCombin(int n, int k)
{
    vector<vector<int> > ans;
    vector<int> tmp;
    Combin(ans, tmp, n, 1, k);
    return ans;
}
  
 //checks if one combination is equal to another 
 bool IsEqual(int* arr1 ,vector<int> vals, int n){
 	bool isequal= true;
 	for(int i =0; i<n; i++){
 		if(arr1[i]!=vals[i]) isequal= false;
	 }
	 return isequal;
 }
 
 //deBruijn sequence for alphabet k & subsequences of length n
    
 bool isDeBruijn(int *arr , int k, int n, int size){
 	int n1 = n;
 	int k1 = k;
 	bool itAppears = false;
 	bool onlyOnce = false;
 	bool DeBruijn = true;
 	
	vector<vector<int> > vals = makeCombin(n1, k1);	
	//checking if each comb in the arr is equal to one comb in the vector with no reppetition
	for(int i=0; i< vals.size(); i++){
		for(int j=0; j<size; j++){
			if(itAppears==false && IsEqual(arr+j,vals[i],n1)==true){
				itAppears=true;
				onlyOnce =true;
			} 
			else if(IsEqual(arr+j,vals[i],n1) && itAppears){
				onlyOnce = false;
			}
 			
		 }
		DeBruijn = DeBruijn && itAppears && onlyOnce;	
	 }
	 return DeBruijn;
  }
 
 bool isListEqual(	node<T>* current, vector<int> vals, int n){
 	int n1 = n;
 	bool isequal= true;
 	for(int i =0; i<n1; i++){
 		if(current->info!=vals[i]) isequal= false;
 		current = current->next;
	 }
	 return isequal;
 	
 }
 
 bool islinkedlistDB( const LL_Type<T>& list, int k, int n){
 	int n1=n;
 	int k1=k;
 	node<T>* current;
 	bool itAppears = false;
 	bool onlyonce = false;
 	bool DeBruijn = true;
	
 	vector<vector<int> > vals = makeCombin(n1, k1);
	//checking if each comb in the arr is equal to one comb in the vector with no reppetition
	for(int i=0; i< vals.size(); i++){
		current = list.first;
		for(int j=0; j<list.count; j++){
			current = current->next;
			
			if(itAppears==false && isListEqual(current,vals[i],n1)==true){
				itAppears=true;
				onlyonce =true;
			} 
			else if(isListEqual(current, vals[i],n1) && itAppears){
				onlyonce = false;
			}
 			
		 }
		DeBruijn = DeBruijn && itAppears && onlyonce;		
	 }
 	return DeBruijn;
 	
 }
 
 
 
 //function that generates a 5% probability
 bool probability(){
 	int x;
 	x= rand() % 100;
 	if (x < 5)
 		return true; 
	 
 }
 

 
 int main(){
 	int n = 2, k = 2; 
    bool isArrDeBruijn = false;
    int arr [100];
    int newArr[100+n];
    LL_Type<int> listA;
    LL_Type<int> listB;
    node<T>* current;
    
    
    
    srand(time(0));  // Initialize random number generator.
     
    for(int i=0;i<100;i++){
    	arr[i] = rand() % 2; //fill in array
  	}
  	for(int i=0;i<100;i++)
  		newArr[i]=arr[i];
  	for(int i=100;i<100+n;i++)
  		newArr[i]=arr[i%100];
  		
  
  	
  	for (int i = 0; i < 100; i++){
  		listA.insert(rand() % 2);
  	}
  
  	listB.CopyList(listA);
  	for (int i = 0; i < n; i++){
  		current->next = listA.first;
  		listB.insertLast(current);
  		LL_Iterator::current++;
    }
  	
    // Get starting timepoint
    auto start = high_resolution_clock::now();
	
	while(!isDeBruijn(NewArr,k,n,100)){
	//change each spot with 5% probability
	for(int i=0;i<100;i++){
		if(probability){
			if(arr[i]==0){
				arr[i]=1;
			}
			else arr[i]=0;
		}
	}
	//copy changed array to new array
	for(int i=0;i<100;i++)
  		newArr[i]=arr[i];
  	for(int i=100;i<100+n;i++)
  		newArr[i]=arr[i%100];

	if(isDeBruijn(newarr,k,n,100)) break;

	}
	
	// Get ending timepoint
    auto stop = high_resolution_clock::now();
    
    auto duration = duration_cast<microseconds>(stop - start);
  
    cout << "Time taken by array function: "
         << duration.count() << " microseconds" << endl;
	
	//Get starting timepoint
   auto start = high_resolution_clock::now();

	while(!islinkedlistDB(listA,k,n)){
		node<int>* current;
		current = listA.first;
		//change each spot with 5% probability
		while (current != nullptr) {
			if(probability){
				if (current->info == 0) {
					current->info =1;
			    }
			else {
				 current->info = 0;
			}
		}
		LL_Iterator::current++;
	}
	listB.CopyList(listA);
  	for (int i = 0; i < n; i++){
  		current = listA.first;
  		listB.insertLast(current);
  		LL_Iterator::current++;
    }
    }
    
	//Get ending timepoint
    auto stop = high_resolution_clock::now();
    
    auto duration = duration_cast<microseconds>(stop - start);
  
    cout << "Time taken by linked list function: "
         << duration.count() << " microseconds" << endl;
	
	
       

  return 0;  

 	
 }
