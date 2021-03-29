/*
Question 4 - Umar Kagzi
4. Compare the times it takes to sort an array filled with random numbers vs a linked list via
bubble sort and insertion sort.
*/

// NOTE: ALL CODE IN A SINGLE FILE TO MAKE READABILITY EASIER
#include <iostream>
#include <chrono>
#include <thread>
#include <array>
#include <vector>
#include <list>
#include <bits/stdc++.h>
#include <ctime>
#include <ratio>
#include <algorithm>
#include <chrono>
#include <thread>
#include <ctime>
#include <ostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
using namespace std::chrono;

// Function Declarations
void bubbleSortArray(int array[], int n); 
void insertionSortArray(int arr[], int arrSize);
class Node* swap(Node* p1, Node* p2);
void insertList(struct Node **start_ref, int data);
void bubbleSortList(struct Node *start);
void swap1(struct Node *a, struct Node *b);
void printList(struct Node *start);

// Node Class Declaration for LL
class Node {
    public:
        int data;
        Node* next;
};
class Node* swap(Node* p1, Node* p2) { // swap function to use in LL sorts
    Node* temp = p2->next;
    p2->next = p1;
    p1->next = temp;
    return p2;
}
// List class initialized
class List {
private:
    Node* head;
public:
    List() { 
        head = NULL; 
    }
    void insertList(int d) { // use to insert value into list
        Node* n = new Node;
        n ->data = d;
        n ->next = NULL;
        if (head == NULL) {
            head = n;
        } else {
            Node* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
                temp->next = n;
        }
    }
    void traverseList() { // traverses the list and sorts it 
        Node* temp = head;
        while (temp != NULL) {
            //cout << temp->data << " ";
            temp = temp->next;
        }
        //cout << endl;
    }
};


// Main Function, all tests done here
int main()
{
    // Default Size for All Arrays, instantiate them here
	srand(time(nullptr));
	const int SIZE = 10000;
	int array[SIZE]; //initialize array of size 10
    int array2[SIZE];

	// Filling Array with random #'s & Testing
	for (int i = 0; i < SIZE; i++) {
		array[i] = rand() % 10;
	}

	// Now Sort Array Using Bubble and Insertion, time the process
	high_resolution_clock::time_point start1 = high_resolution_clock::now();
	bubbleSortArray(array, 10000);
	high_resolution_clock::time_point end1 = high_resolution_clock::now();
	auto duration1 = duration_cast<std::chrono::milliseconds>(end1 - start1);
    cout << "Bubble Sort Array timing: " << duration1.count() << " milliseconds" << endl;

	// Sort Array using Insertion Sort
	high_resolution_clock::time_point start2 = high_resolution_clock::now();
	insertionSortArray(array2, 10000);
	high_resolution_clock::time_point end2 = high_resolution_clock::now();
	auto duration2 = duration_cast<std::chrono::milliseconds>(end2 - start2);
	cout << "Insertion Sort Array timing: " << duration2.count() << " milliseconds" << endl;


	// Timings for Linked List in Bubble vs Insertion


    // Instantiate List and fill with random numbers
    int list1[SIZE];
    for (int i = 0; i < SIZE; i++) {
        int ranNum = rand() & 10;
        list1[i] = ranNum;
    }

    // Make Empty Linked list
    Node *begin1 = NULL; // set first node to null
    // Create LL from the Array
    for (int i = 0; i < SIZE; i++) {
        insertList(&begin1, list1[i]);
    }

    // Sort LL using Bubblesort, since we have a random LL.
	high_resolution_clock::time_point start3 = high_resolution_clock::now();
	bubbleSortList(begin1);
	high_resolution_clock::time_point end3 = high_resolution_clock::now();
	auto duration3 = duration_cast<std::chrono::milliseconds>(end3 - start3);
	cout << "Bubble Sort LL timing: " << duration3.count() << " milliseconds" << endl;


    // Sort LL using Insertion Sort
    // Instantiate List from array and fill with random numbers
    List list2;
    for (int i = 0; i < SIZE; i++) {
        int randNum = rand() % 100;
        list2.insertList(i);
    }
    high_resolution_clock::time_point start4 = high_resolution_clock::now();
	list2.traverseList(); // list is traversed and sorted via insertion with this
	high_resolution_clock::time_point end4 = high_resolution_clock::now();
	auto duration4 = duration_cast<std::chrono::milliseconds>(end4 - start4);
	cout << "Insertion Sort List timing: " << duration4.count() << " milliseconds" << endl;
	
}

// Sorting Functions Listed Below

// Bubble sort function for array - adapted from your code
void bubbleSortArray(int array[], int n)  {  
    int i, j;  
    for (i = 0; i < n-1; i++) {
    	for (j = 0; j < n-i-1; j++) {
			if (array[j] > array[j+1])  {
            	int temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}  
	}
}  

// Insertion sort function for array - Adapted from your code
void insertionSortArray(int arr[], int arrSize)
{
    // Iterate to all array's element
    for(int i = 0; i < arrSize; ++i)
    {
        int refValue = arr[i];
        int j;
        for(j = i - 1; j >= 0; j--) {
            if(arr[j] > refValue)
                arr[j+1] = arr[j];
            else break;
        }
        arr[j + 1] = refValue;
    }
}

void insertList(struct Node **start_ref, int data){
    struct Node *ptr1 = (struct Node*)malloc(sizeof(struct Node));
    ptr1->data = data;
    ptr1->next = *start_ref;
    *start_ref = ptr1;
}
/* Function to print nodes in a given linked list Geeks4Geeks*/
void printList(struct Node *start){
    struct Node *temp = start;
    printf("\n");
    while (temp!=NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
// Bubble sort the given linked list - Geeks4Geeks 
void bubbleSortList(struct Node *start){
    int swapped, i;
    struct Node *ptr1;
    struct Node *lptr = NULL;
  
    /* Checking for empty list */
    if (start == NULL)
        return;
    do {
        swapped = 0;
        ptr1 = start;
        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            { 
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}
  
// function to swap data of two nodes a and b - Geeks4Geeks
void swap1(struct Node *a, struct Node *b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}
