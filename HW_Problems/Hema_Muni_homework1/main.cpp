#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <time.h>
#include <chrono>

using std::chrono::system_clock;
using std::chrono::steady_clock;
using std::chrono::duration_cast;
using std::chrono::seconds;
using std::chrono::milliseconds;

#include "question1.h"
#include "question2.h"
#include "question3.h"
#include "question8.h"
#include "question10.h"
#include "question11.h"

using namespace std;

template <typename Func>
long long TimeFunc(Func f)
{
    auto begin = steady_clock::now();
    f();
    auto end = steady_clock::now();

    return duration_cast<milliseconds>(end - begin).count();
}

int main() {
    cout << "Question 1: " << endl;
    srand(time(0));
    int const size = 1000;
    //filling them with random numbers
    Vec<int> v1;
    v1.push_back(0);

    LinkedList<int> l1;
    l1.InsertHead(0);

    auto v1milliseconds = TimeFunc([&]() {BuildVector(size,v1); });
    cout << "vector time: " << v1milliseconds << endl;
    auto l1milliseconds = TimeFunc([&]() {BuildList(size,l1); });
    cout << "linked list time: " << l1milliseconds << endl;

    //filling them with random chars
    Vec<char> v2;
    auto v2milliseconds = TimeFunc([&]() {buildStringVector(size,v2); });
    cout << "ascii vector time: " << v2milliseconds << endl;

    LinkedList<char> l2;
    auto l2milliseconds = TimeFunc([&]() {buildStringList(size,l2); });
    cout << "ascii linked list time: " << l2milliseconds << endl;

    //filling them with random strings with move semantics
    Vec<char> v3;
    auto v3milliseconds = TimeFunc([&]() { buildStringVector(size, v3); });
    auto v4 = move(v3milliseconds);
    cout << "move semantic vector time: " << v4<< endl;

    LinkedList<char> l3;
    auto l3milliseconds = TimeFunc([&]() { BuildList(size, l3); });
    auto l4 = move(l3milliseconds);
    cout << "move semantic linked list time: " << l4 << endl;
    cout << endl;

    cout << "Question 2: " << endl;
    int n = 10000000;
    int* arr1 = new int[n];
    for(int i = 0; i < n; i++){
        arr1[i] = (rand()% n) + 1;
    }

    sort(arr1, arr1 + n);

    ListNode *first = newNode(1);
    first->next = newNode(4);
    first->next->next = newNode(7);
    first->next->next->next = newNode(8);
    first->next->next->next->next = newNode(9);
    first->next->next->next->next->next = newNode(10);
    int value = 7;

    auto rBSseconds = TimeFunc([&] () {recursiveBinarySearch(arr1, 0, 999, 15); });
    auto iBSseconds = TimeFunc([&] () {interativeBinarySearch(arr1, 0, 999, 15); });
    auto llBSseconds = TimeFunc([&] () {LinkedListBinarySearch(first, value); });

    cout << rBSseconds << endl;
    cout << iBSseconds << endl;
    cout << llBSseconds << endl;
    cout << endl;

    cout << "Question 3: " << endl;
    //insertion sort
    int insert_matrix[3][5] = {{15, 14, 13, 12, 11}, {10, 9, 8, 7, 6}, {500, 400, 300, 200, 100}};
    int insert_rows = sizeof(insert_matrix)/sizeof(insert_matrix[0]);
    int insert_cols = sizeof(insert_matrix[0])/sizeof(insert_matrix[0][0]);
    insertionSortMatrix(insert_matrix, insert_rows, insert_cols);
    cout << "Insertion sort:" << endl;
    for (int i = 0; i < insert_rows; i++) {
        for (int j = 0; j < insert_cols; j++) {
            cout << insert_matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    //selection sort
    int selection_matrix[3][5] = {{15, 14, 13, 12, 11}, {10, 9, 8, 7, 6}, {500, 400, 300, 200, 100}};
    int selection_rows = sizeof(selection_matrix)/sizeof(selection_matrix[0]);
    int selection_cols = sizeof(selection_matrix[0])/sizeof(selection_matrix[0][0]);
    selectionSortMatrix(selection_matrix, selection_rows, selection_cols);
    cout << "Selection sort:" << endl;
    for (int i = 0; i < selection_rows; i++) {
        for (int j = 0; j < selection_cols; j++) {
            cout << selection_matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    //bubble sort
    int bubble_matrix[3][5] = {{15, 14, 13, 12, 11}, {10, 9, 8, 7, 6}, {500, 400, 300, 200, 100}};
    int bubble_rows = sizeof(bubble_matrix)/sizeof(bubble_matrix[0]);
    int bubble_cols = sizeof(bubble_matrix[0])/sizeof(bubble_matrix[0][0]);
    bubbleSortMatrix(bubble_matrix, bubble_rows, bubble_cols);
    cout << "Bubble sort:" << endl;
    for (int i = 0; i < bubble_rows; i++) {
        for (int j = 0; j < bubble_cols; j++) {
            cout << insert_matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Question 8: " << endl;
    PossibleAnswers<int> pa;
    pa.ask();
    cout << endl;

    cout << "Question 10: " << endl;
    ListNode* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    cout << "before sorted" << endl;
    print(head);
    cout << endl;

    head = oddEvenList(head);
    cout << "after sorted" << endl;
    print(head);
    cout << endl;

    cout << "Question 11: " << endl;
    Italian_Restaurant i = Italian_Restaurant("Pizzaro", "21 Midtown New York");
    Reader_Robot<Italian_Restaurant> italianTemplate(i);
    italianTemplate.read();

    Greek_Restaurant g = Greek_Restaurant("Oba", "96-11 Forest Hills");
    Reader_Robot<Greek_Restaurant> greekTemplate(g);
    greekTemplate.read();

    Chinese_Restaurant c = Chinese_Restaurant("Feng Shua", "1 Flushing New York");
    Reader_Robot<Chinese_Restaurant> chineseTemplate(c);
    chineseTemplate.read();

    return 0;
}
