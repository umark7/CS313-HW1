/*
Question 7 - Umar Kagzi
C++ has several containers (https://www.cplusplus.com/reference/stl/). Pick three of
them and compare similar operations by timing them on a large scale. Explain a
hypothesis, your results, and your explanation.
*/

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

using namespace std;
using namespace std::chrono;

//  respective Containers

template <size_t Length>
void print(std::array <int, Length> &arr) {
   std::cout << "\nThe array elements are : ";
   for(int i=0; i < arr.size(); i++)
    std::cout << arr.at(i) << ' ';
}

void print(std::vector <int> &vec) {
   std::cout << "\nThe vector elements are : ";
   for(int i=0; i < vec.size(); i++)
    std::cout << vec.at(i) << ' ';
}

void printList(std::list <int> &lister) {
   std::cout << "\nThe list elements are : ";
   for (auto const &i: lister)
    std::cout << i << ' ';
}


int main() {

    srand(time(nullptr));
    int size = 10000; //default size of all containers

    // Check Array Speed
    auto start1 = high_resolution_clock::now();
    array<int, 10000> array; // instantiate array
    for (int i = 0; i < size; i++) {
        int arrNum1 = rand() % 100;
        array[i] = arrNum1;
    }
    sort(array.begin(), array.end()); // N*log2(N)
    print(array);
    //End of array now compile timings
    auto end1 = high_resolution_clock::now();
    auto duration1 = duration_cast<std::chrono::microseconds>(end1 - start1);
    cout << "The array print took: " << duration1.count() << " microseconds" << endl;


    // Check Vector Speed
    auto start2 = high_resolution_clock::now();

    vector<int> vec;
    for (int i = 0; i < size; i++) {
        int vecNum1 = rand() % 100;
        vec.push_back(vecNum1);
    }
    sort(vec.begin(), vec.end());
    print(vec);
    //End of Vector now compile timings
    auto end2 = high_resolution_clock::now();
    auto duration2 = duration_cast<std::chrono::microseconds>(end2 - start2);
    cout << "The vector print took: " << duration2.count() << " microseconds" << endl;


    // Check List Speed
    auto start3 = high_resolution_clock::now();
    list<int> lister;
    for (int i = 0; i < size; i++) { 
        int listNum1 = rand() % 100;
        lister.push_front(listNum1);
    }
    lister.sort();
    printList(lister);
    //End of List, now compile timings
    auto end3 = high_resolution_clock::now();
    auto duration3 = duration_cast<std::chrono::microseconds>(end3 - start3);
    cout << "The list print took: " << duration3.count() << " microseconds" << endl;

}







