
/*
Question 4
4. Compare the times it takes to sort an array filled with random numbers vs a linked list via
bubble sort and insertion sort.
*/

// step 3 - sort the linked list with bubble sort and insertion sort 
// step 4 - record & print times at end, make whitepaper and video record you going through the code 
//timing things

#include <iostream>
#include <chrono>
#include <thread>
#include <array>
#include <vector>
#include <list>
#include <bits/stdc++.h>
#include <ctime>
#include <ratio>
#include <ostream>
#include <algorithm>

using namespace std;
using namespace std::chrono;


void bubbleSortArray(int array[], int n);
void insertionSortArray(int arr[], int arrSize);
void push(struct Node** head_ref, int new_data);
void sortedInsert(struct Node**, struct Node*);

struct Node
{
    int data;
    struct Node* next;
};


high_resolution_clock::time_point start = high_resolution_clock::now();
high_resolution_clock::time_point endTime = high_resolution_clock::now();
duration<double> time_span = duration_cast<std::chrono::nanoseconds>(endTime - start);
float ns = time_span.count();


int main()
{

	srand(time(nullptr));
	const int SIZE = 1000000;

	int array[SIZE]; //initialize array of size 10

	// Filling Array & Testing

	for (int i = 0; i < SIZE; i++) {
		array[i] = rand() % 10;
	}
	// Now Sort Array Using Bubble and Insertion, time the process
	start;
	bubbleSortArray(array, 1000000);
	endTime;
	time_span;
	cout << "Bubble Sort Array timing: " << ns << " Nanoseconds." << endl;

	// Sort Array using Insertion Sort
	start;
	insertionSortArray(array, 1000000);
	endTime;
	time_span;
	cout << "Insertion Sort Array timing: " << ns << " Nanoseconds." << endl;

	
	// Declare New Linked List

	// Timings for Linked List in Bubble vs Insertion
	// TODO MAKE LIST, ADD RANDOM NUMS, AND MAKE BUBBLELIST FUNCTION 
	start;
	bubbleSortList(array, 1000000);
	endTime;
	time_span;
	cout << "\nBubble Sort List timing: " << ns << " Nanoseconds." << endl;

	start;
	insertionSortList(array, 1000000);
	endTime;
	time_span;
	cout << "Insertion Sort List timing: " << ns << " Nanoseconds." << endl;
	
}




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

void insertionSortArray(int arr[], int arrSize)
{
    // Iterate to all array's element
    for(int i = 0; i < arrSize; ++i)
    {
    
        int refValue = arr[i];
        int j;

        for(j = i - 1; j >= 0; --j)
        {
            if(arr[j] > refValue)
                arr[j+1] = arr[j];
            else
                break;
        }
        arr[j + 1] = refValue;
    }
}




// function to sort a singly linked list using insertion sort
void insertionSortList(struct Node **head_ref)
{
    // Initialize sorted linked list
    struct Node *sorted = NULL;
  
    // Traverse the given linked list and insert every
    // node to sorted
    struct Node *current = *head_ref;
    while (current != NULL)
    {
        // Store next for next iteration
        struct Node *next = current->next;
  
        // insert current in sorted linked list
        sortedInsert(&sorted, current);
  
        // Update current
        current = next;
    }
  
    // Update head_ref to point to sorted linked list
    *head_ref = sorted;
}

/* function to insert a new_node in a list. Note that this
  function expects a pointer to head_ref as this can modify the
  head of the input linked list (similar to push())*/
void sortedInsert(struct Node** head_ref, struct Node* new_node)
{
    struct Node* current;
    /* Special case for the head end */
    if (*head_ref == NULL || (*head_ref)->data >= new_node->data)
    {
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    else
    {
        /* Locate the node before the point of insertion */
        current = *head_ref;
        while (current->next!=NULL &&
               current->next->data < new_node->data)
        {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}


void push(struct Node** head_ref, int new_data)
{
    /* allocate node */
    struct Node* new_node = new Node;
  
    /* put in the data  */
    new_node->data  = new_data;
  
    /* link the old list off the new node */
    new_node->next = (*head_ref);
  
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}


node* buildListBackwards() {
	node* first, * newNode;
	int num, listSize;

	cout << "How many values would you like in the list?\n";
	cin >> listSize;

	first = nullptr;

	for (int i = 0; i < listSize; i++) {
		cout << "What value would you like to insert?\n";
		cin >> num;

		newNode = new node;
		newNode->info = num;
		newNode->link = first;
		first = newNode;
	}
	return first;
}

void printList(node* val) {
	node* current = val;

	while (current != nullptr) {
		cout << current->info << " ";
		current = current->link;
	}
	cout << endl << endl;
}
