//
// Created by Hema Muni on 3/18/21.
//

#ifndef HEMA_MUNI_HOMEWORK1_QUESTION8_H
#define HEMA_MUNI_HOMEWORK1_QUESTION8_H
#include <vector>
#include <iostream>
using namespace std;

template <class T>
class PossibleAnswers{
public:
//    PossibleAnswers() {};
    void possibleUniqueComb(vector<int>& randomNums, int targetSum, vector<int>& storeCombs, int start_val, int temp_sum);
    void sortArray(vector<int> randomNums, int targetSum);
    void uniqueCombination(int temp_sum, int targetSum, vector<int>& storeCombs);
    void ask();
};


template <class T>
void PossibleAnswers<T> :: ask() {
    int n, s;

    cout << "Enter in the length of the vector: ";
    cin >> n;

    cout << "Enter in the target sum: ";
    cin >> s;

    vector<int> randomNumbers;

    for (int i= 0; i < n; i++) {
        randomNumbers.push_back(rand() % 20);
    }

    // Function call
    sortArray(randomNumbers, s);

}

template <class T>
void PossibleAnswers<T> :: uniqueCombination(int temp_sum, int targetSum, vector<int>& storeCombs) {
    // If a unique combination is found we want to display it.
    for (int i = 0; i < storeCombs.size(); i++)
    {
        cout << storeCombs[i] << " ";
    }
    cout << endl;
    return;
}

template <class T>
void PossibleAnswers<T> :: possibleUniqueComb(vector<int>& randomNums, int targetSum, vector<int>& storeCombs, int start_val, int temp_sum){

    if (temp_sum == targetSum) {
        uniqueCombination(temp_sum, targetSum, storeCombs);
    }

    // For all other combinations
    for (int i = start_val; i < randomNums.size(); i++)
    {
        // Check if the temp sum exceeds our targetSum or if combination is repeated.
        if ((targetSum < temp_sum + randomNums[i]) || (randomNums[i] == randomNums[i - 1] && i > start_val)) {
            continue;
        }

        // Take the element into the combination
        storeCombs.push_back(randomNums[i]);

        // Recursive call
        possibleUniqueComb(randomNums, targetSum, storeCombs, i + 1, temp_sum + randomNums[i]);

        // Remove element from the combination once we don't need it anymore.
        storeCombs.pop_back();

    }
}

// Function to find all combination
// of the given elements
template <class T>
void PossibleAnswers<T>:: sortArray(vector<int> randomNumbers, int targetSum){
    // Sort the given elements, this is needed to get unique combinations. We'll iterate the vector one element at a time.
    sort(randomNumbers.begin(), randomNumbers.end());

    // Create a new vector to store the new elements.
    vector<int> storeCombinations;

    possibleUniqueComb(randomNumbers, targetSum, storeCombinations, 0, 0);
}
#endif //HEMA_MUNI_HOMEWORK1_QUESTION8_H
