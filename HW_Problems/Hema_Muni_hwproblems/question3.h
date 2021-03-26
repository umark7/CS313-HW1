//
// Created by Hema Muni on 3/25/21.
//

#ifndef HOMEWORK_ONE_QUESTION3_H
#define HOMEWORK_ONE_QUESTION3_H

#include <iostream>
using namespace std;

//insertion sort
void insertionSortMatrix(int matrix[][5], int rows, int cols){
    int i, j;
    //go through our list of rows
    for(i=0; i< rows; i++) {
        //go through our list of columns
        for (j = 1; j < cols; j++) {
            int tmp_value = matrix[i][j];
            int k = j -1;
            //we check to see if the value of k is larger than our original numbers
            //if so, we switch the values so they can increase numerically
            while(k >= 0 && matrix[i][k] > tmp_value) {
                matrix[i][k+1] = matrix[i][k];
                k = k-1;
            }
            matrix[i][k+1] = tmp_value;
        }
    }

    //go through our list of columns
    for(i=0; i< cols; i++) {
        //go through our list of rows
        for (j = 0; j < rows -1; j++) {
            for (int k = 0; k < rows-1; ++k) {
                //we check to see if the value of k is larger than our original numbers
                //if so, we switch the values so they can increase numerically
                if (matrix[k][i] > matrix[k+1][i])  {
                    int temp = matrix[k][i];
                    matrix[k][i] = matrix[k+1][i];
                    matrix[k+1][i] = temp;
                }
            }
        }
    }
}

//Selection Sort
void selectionSortMatrix(int matrix[][5], int rows, int cols){
    int i, j;

    //go through our list of rows
    for(i=0; i< rows; i++) {
        //go through our list of columns
        for (j = 1; j < cols; j++) {
            int tmp_value = matrix[i][j];
            int k = j -1;
            //we check to see if the value of k is larger than our original numbers
            //if so, we switch the values so they can increase numerically
            while(k >= 0 && matrix[i][k] > tmp_value) {
                matrix[i][k+1] = matrix[i][k];
                k = k-1;
            }
            matrix[i][k+1] = tmp_value;
        }
    }

    //go through our list of columns
    for(i=0; i< cols; i++) {
        //go through our list of rows
        for (j = 0; j < rows -1; j++) {
            for (int k = 0; k < rows-1; ++k) {
                //we check to see if the value of k is larger than our original numbers
                //if so, we switch the values so they can increase numerically
                if (matrix[k][i] > matrix[k+1][i])  {
                    int temp = matrix[k][i];
                    matrix[k][i] = matrix[k+1][i];
                    matrix[k+1][i] = temp;
                }
            }
        }
    }
}

//Bubble Sort

void bubbleSortMatrix(int matrix[][5], int rows, int cols){
    //go through our list of rows
    for(int k=0; k< rows; k++) {
        //go through our list of columns
        for (int i = 0; i < cols; i++) {
            for (int j = i +1; j < cols; ++j) {
                //we check to see if the value of k is larger than our original numbers
                //if so, we switch the values so they can increase numerically
                if (matrix[k][i] > matrix[k][j])  {
                    int swap = matrix[k][i];
                    matrix[k][i] = matrix[k][j];
                    matrix[k][j] = swap;
                }
            }
        }
    }
    //go through our list of columns
    for(int i = 0; i < cols; i++){
        //go through our list of rows
        for(int j = 0; j < rows - 1; j++){
            for(int k = 0; k < rows - 1; k++){
                //we check to see if the value of k is larger than our original numbers
                //if so, we switch the values so they can increase numerically
                if(matrix[k][i] > matrix[k + 1][i]){
                    int temp = matrix[k][i];
                    matrix[k][i] = matrix[k + 1][i];
                    matrix[k + 1][i] = temp;
                }
            }
        }
    }
}
#endif //HOMEWORK_ONE_QUESTION3_H
