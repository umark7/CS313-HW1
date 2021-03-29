/*5. Create a multi-level sort. For instance, for all selections of n > 10 you do sort X and
within sort X, when you have a situation with n < 10 you do sort Y. Be creative. Time
your sort against two “reasonably comparable” sorts (you may use libraries for the
“reasonably comparable sorts”).
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
#include <ostream>
#include <algorithm>
#include <string>
#include <utility>
#include <time.h>
#include <iterator>

using namespace std;
using namespace std::chrono;

int itemPrice(int items[], int amount)

int main()
{
	srand(time(nullptr));

    // My Multisort runned
    auto start1 = high_resolution_clock::now();
    int amount = 1000;
    int items[amount];
    itemPrice(items, amount);
    auto end1 = high_resolution_clock::now();
    auto duration1 = duration_cast<std::chrono::microseconds>(end1 - start1);
    cout << "The array sort with my multisort took: " << duration1.count() << " microseconds" << endl;


    // Compared against reasonable sorts (Quicksort (sort) for lower numbers, mergesort for higher numbers)
    //Instantiate same sized array to check speed against my own sort.
    array<int, 10000> arrayQuick; // instantiate array
    for (int i = 0; i < amount; i++) { // Fill with random numbers, exactly the same as my own sort
        int arrNum1 = rand() % 100 + 1 ;
        arrayQuick[i] = arrNum1;
    }
    auto start2 = high_resolution_clock::now();
    sort(arrayQuick.begin(), arrayQuick.end()); // N*log2(N)
    auto end2 = high_resolution_clock::now();
    auto duration2 = duration_cast<std::chrono::microseconds>(end2 - start2);
    cout << "The array sort with Quicksort took: " << duration2.count() << " microseconds" << endl;

    // Stable Sort Array to test against my own sort
    array<int, 10000> arrayStable; // instantiate array
    for (int i = 0; i < amount; i++) { // Fill with random numbers, exactly the same as my own sort
        int arrNum1 = rand() % 100 + 1 ;
        arrayStable[i] = arrNum1;
    }
    auto start3 = high_resolution_clock::now();
    stable_sort(arrayStable.begin(), arrayStable.end());
    auto end3 = high_resolution_clock::now();
    auto duration3 = duration_cast<std::chrono::microseconds>(end3 - start3);
    cout << "The array sort with stable sort took: " << duration3.count() << " microseconds" << endl;
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
	return 0;
}
