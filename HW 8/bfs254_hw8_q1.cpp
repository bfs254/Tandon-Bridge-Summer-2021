//Author: Briana Singleton
//NYU ID: bfs254
//HW 8 Q1
//takes an array of integers from user and returns minimum value in array
//Last modified: 30 August 2021

#include <iostream>
using namespace std;

const int MAX_SIZE_OF_NUM_ARRAY = 20;

void readArray(int arr[], int arrSize);
//reads a list of integers into an array 

int minInArray(int arr[], int arrSize);
//takes a user-provided array of numbers and array's logical size
//returns minimum value in array

void indexesOfMinInArray(int arr[], int arrSize);
//takes a user-provided array of numbers and array's logical size
//returns the index locations of minimum value in array

int main() {
    int numArray[MAX_SIZE_OF_NUM_ARRAY];

    readArray(numArray, MAX_SIZE_OF_NUM_ARRAY);
    indexesOfMinInArray(numArray, MAX_SIZE_OF_NUM_ARRAY);

    return 0;
}

void readArray(int arr[], int arrSize){
    cout<< "Please enter " << arrSize << " integers separated by a space: " << endl;
    for (int i = 0; i < arrSize; i++) {
        cin>> arr[i];
    }
    return;
}

int minInArray(int arr[], int arrSize) {
    int min;
    min = arr[0];

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min; 
}

void indexesOfMinInArray(int arr[], int arrSize) {
    int min = minInArray(arr, arrSize);

    cout<< "The minimum value is " << min <<  ", and it is located in the following indices: ";
    for (int i = 0; i < arrSize; i++){
        if (arr[i] == min) {
            cout << i << " ";
        }
    }
    return;
}