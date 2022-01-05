//Author: Briana Singleton
//NYU ID: bfs254
//HW 11 Q2
//takes arrays and analyzes their elements
//Last modified: 20 September 2021

#include <iostream>
using namespace std;

int sumOfSquares(int arr[], int arrSize);
//takes an array of integers, arr, and its logical size, arrSize
//returns the sum of the squares in each of the values of arr

bool isSorted(int arr[], int arrSize);
//takes an array of integers, arr, and its logical size, arrSize
//returns true if elements in arr are sorted in ascending order, returns false if they are not

int main(){
    int arrSize = 10;
    int arr[arrSize] = {-5, -4, -3, -2, -1, 0, 1, 2, 3, 4};    
    
    cout << "The sum of the array's squares is: " << sumOfSquares(arr, arrSize) << endl;
    
    if(isSorted(arr, arrSize) == true) {
        cout<< "Array is sorted in ascending order." << endl;
    }
    else {
        cout << "Array is not sorted in ascending order." << endl;
    }

    return 0;
}

int sumOfSquares(int arr[], int arrSize) {
    int sum = 0;
    if (arrSize == 1) {
        sum = arr[0] * arr[0];
        return sum;
    }
    else {
        sum += sumOfSquares(arr, arrSize - 1);
        sum += arr[arrSize - 1] * arr[arrSize - 1];
        return sum;
    }
}

bool isSorted(int arr[], int arrSize) {
    bool isAscending = true;

    if (arrSize == 1) {
        return true;
    }
    else {
        isAscending = isSorted(arr, arrSize - 1);
        
        if (arr[arrSize - 2] > arr[arrSize - 1]){
            isAscending = false;
        }
        return isAscending;
    }
        
}