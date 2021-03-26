/*5. Create a multi-level sort. For instance, for all selections of n > 10 you do sort X and
within sort X, when you have a situation with n < 10 you do sort Y. Be creative. Time
your sort against two “reasonably comparable” sorts (you may use libraries for the
“reasonably comparable sorts”).
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
#include <algorithm>
#include <string>
#include <utility>
#include <time.h>
#include <iterator>

using namespace std;
using namespace std::chrono;

int itemPrice(int items[], int amount)


template <typename Comparable>
void mergeSort(vector<Comparable>& a,
    vector<Comparable>& tmpArray, int left, int right);
template <typename Comparable>
void mergeSort(vector<Comparable>& a);
template <typename Comparable>
void merge(vector<Comparable>& a, vector<Comparable>& tmpArray,
    int leftPos, int rightPos, int rightEnd);



int main()
{
	srand(time(nullptr));

    // My Multisort runned
    auto start1 = high_resolution_clock::now();
    int amount = 1000;
    int items[amount];
    cout << itemPrice(items, amount) << endl;
    auto end1 = high_resolution_clock::now();
    auto duration1 = duration_cast<std::chrono::microseconds>(end1 - start1);
    cout << "The array print with my multisort took: " << duration1.count() << " microseconds" << endl;

    // Compared against reasonable sorts (Quicksort (sort) for lower numbers, mergesort for higher numbers)
    auto start2 = high_resolution_clock::now();
    std::sort(items.begin(), items.end());
    auto end2 = high_resolution_clock::now();
    auto duration2 = duration_cast<std::chrono::microseconds>(end2 - start2);
    cout << "The array print with my Quicksort took: " << duration2.count() << " microseconds" << endl;

    auto start3 = high_resolution_clock::now();
    std::mergeSort(items.begin(), items.end());
    auto end3 = high_resolution_clock::now();
    auto duration3 = duration_cast<std::chrono::microseconds>(end3 - start3);
    cout << "The array print with mergesort took: " << duration3.count() << " microseconds" << endl;
} 




int itemPrice(int items[], int amount) {
    srand(time(nullptr));
    int i, temp, sorted;
    int amount = 1000;
    int items[amount];

    cout << "Original Items Cost List\n";
    for(int i = 0; i < amount; i++) {
        items[i] = rand()% 100 + 1;
        cout << items[i] << " ";
    }

    while(1) {
        sorted = 0; //checks if array is sorted or not

        for (int i = 0; i < amount-1; i++) {
            if(items[i] > items[i+1]) { // if items[i] is greater than next index, swap using temp variables 
                if (items[i] > 50) {    // If items cost is greater than 50, do another sort here similar to top
                    while(1) {
                        sorted = 0;
                        for (int i = 0; i < amount-1; i++) {
                            if(items[i] > items[i+1]) {
                                int temp =  items[i];
                                items[i] = items[i+1];
                                items[i+1] = temp;
                                sorted = 1;  
                            }
                        }    
                        if(sorted == 0) break;    
                    }
                }
                int temp =  items[i];
                items[i] = items[i+1];
                items[i+1] = temp;
                sorted = 1;
            }
        }
        if(sorted==0) {
            break;
        }
    }

    cout << "Sorted Item Cost List\n";
    for (int i = 0; i < amount; i++) {
        cout << items[i] << " " << endl;
    }
}
















template <typename Comparable>
void mergeSort(vector<Comparable>& a,
    vector<Comparable>& tmpArray, int left, int right)
{
    if (left < right)
    {
        int center = (left + right) / 2;
        mergeSort(a, tmpArray, left, center);
        mergeSort(a, tmpArray, center + 1, right);
        merge(a, tmpArray, left, center + 1, right);
    }
}

/**
 * Mergesort algorithm (driver).
 */
template <typename Comparable>
void mergeSort(vector<Comparable>& a)
{
    vector<Comparable> tmpArray(a.size());

    mergeSort(a, tmpArray, 0, a.size() - 1);
}


/**
 * Internal method that merges two sorted halves of a subarray.
 * a is an array of Comparable items.
 * tmpArray is an array to place the merged result.
 * leftPos is the left-most index of the subarray.
 * rightPos is the index of the start of the second half.
 * rightEnd is the right-most index of the subarray.
 */
template <typename Comparable>
void merge(vector<Comparable>& a, vector<Comparable>& tmpArray,
    int leftPos, int rightPos, int rightEnd)
{
    int leftEnd = rightPos - 1;
    int tmpPos = leftPos;
    int numElements = rightEnd - leftPos + 1;

    // Main loop
    while (leftPos <= leftEnd && rightPos <= rightEnd)
        if (a[leftPos] <= a[rightPos])
            tmpArray[tmpPos++] = std::move(a[leftPos++]);
        else
            tmpArray[tmpPos++] = std::move(a[rightPos++]);

    while (leftPos <= leftEnd)    // Copy rest of first half
        tmpArray[tmpPos++] = std::move(a[leftPos++]);

    while (rightPos <= rightEnd)  // Copy rest of right half
        tmpArray[tmpPos++] = std::move(a[rightPos++]);

    // Copy tmpArray back
    for (int i = 0; i < numElements; ++i, --rightEnd)
        a[rightEnd] = std::move(tmpArray[rightEnd]);
}
