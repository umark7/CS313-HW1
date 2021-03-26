//
// Created by Hema Muni on 3/25/21.
//

#ifndef HOMEWORK_ONE_QUESTION2_H
#define HOMEWORK_ONE_QUESTION2_H

#include <iostream>
#include <string>
using namespace std;

class ListNode {
public:
    int value;
    ListNode* next;
};

ListNode* newNode(int data) {
    ListNode* temp = new ListNode;
    temp->value = data;
    temp->next = nullptr;
    return temp;
}

ListNode* middleElement(ListNode* head, ListNode* tail) {
    //we have two pointers that will keep track of where the middle element is
    ListNode* slowptr = head;
    ListNode* fastptr = head;

    //while the faster pointer and the value next to the faster point is not equal to the tail it will run
    while(fastptr != tail && fastptr->next != tail) {
        //skips by 2
        fastptr = fastptr->next->next;

        //if not equal to tail it will have slower pointer move by 1 and faster pointer move by 2
        //this will help find the middle element
        if(fastptr != tail) {
            slowptr  = slowptr->next;
            fastptr = fastptr->next->next;
        }
    }
    return slowptr;
}

ListNode* LinkedListBinarySearch(ListNode* head, int val) {
    ListNode* start = head;
    ListNode* tail= nullptr;
    //while tail is empty or tail is not the head it will run
    while (tail == nullptr || tail!= start){
        //we call the middleElement to find out middle element
        ListNode* mid = middleElement(start, tail);
        //if its the value we want we return the middle
        if (mid->value == val)
            return mid;
            //if our value we want is greater than the mid value founded, we will continue to go next
        else if (val > mid->value)
            start = mid->next;
            //our tail has the middle value
        else
            tail = mid;
    }

    return nullptr;
}

bool recursiveBinarySearch(int* arr, int left, int right, int target) {
    static int counter = 0;
    counter++;

    int mid = (right + left)/2;

    //check mid for positive loop
    if(arr[mid] == target)
        return true;
    //check mid for negtiave loop
    if(mid == right || mid == left) {
        return false;
    }

    if(target < arr[mid]) {
        return recursiveBinarySearch(arr, left, mid, target);
    }
    return recursiveBinarySearch(arr, mid, right, target);
}

bool interativeBinarySearch(int* arr, int left, int right, int target){
    while(right != left){
        int mid = (right + left)/2;

        if(arr[mid] == target)
            return true;
        else if(target > arr[mid])
            left = mid+1;
        else
            right = mid-1;
    }
    return false;
}

int generateRand(int n) {
    //randomizes the numbers
    int randNums = rand() % n;
    return randNums;
}
#endif //HOMEWORK_ONE_QUESTION2_H
