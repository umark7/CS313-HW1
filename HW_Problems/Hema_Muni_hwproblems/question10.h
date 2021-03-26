//
// Created by Hema Muni on 3/25/21.
//

#ifndef HOMEWORK_ONE_QUESTION10_H
#define HOMEWORK_ONE_QUESTION10_H

#include <list>
#include <iostream>
using namespace std;

//this function sorts it
ListNode* oddEvenList(ListNode* head) {
    if(head == nullptr) return nullptr;

    ListNode *oddNode = head;
    ListNode *evenNode = head->next;
    ListNode *temp = evenNode;

    //psuedo code on how i would sort it
//    if(head->value%2 != 0) {
//        oddNode = head;
//    }
//    if(head->value%2 == 0) {
//        evenNode = head->next;
//        temp = evenNode;
//    }

    //if even is not empty or next to even is not empty then this loop will run
    while(evenNode != nullptr && evenNode->next != nullptr){
        //
        oddNode->next = evenNode->next;
        oddNode = oddNode->next;
        evenNode->next = oddNode->next;
        evenNode = evenNode->next;
    }

    oddNode->next = temp;
    return head;
}

//this function prints out each node
void print(ListNode* node) {
    while(node != nullptr) {
        //prints the node value
        cout << node->value << "->";
        //moves onto the next one
        node = node->next;
    }
    cout << "Nullptr" << endl;
}

#endif //HOMEWORK_ONE_QUESTION10_H
