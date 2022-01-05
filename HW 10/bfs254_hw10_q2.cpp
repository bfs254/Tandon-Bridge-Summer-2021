//Author: Briana Singleton
//NYU ID: bfs254
//WK 10 HW Q2
//finds the missing numbers between 1 and n
//Last modified: 17 September 2021

#include <iostream>
#include <array>
using namespace std; 

void printArrayAtPtr(int* arrPtr, int arrSize);

void resizeArray(int*& arrPtr, int arrSize, int& arrPhysSize);

void sortArray(int arr[], int arrSize);

int* findMissing(int arr[], int n, int& resArrSize);
//gets array of integers, arr, w/ values ranging from 1 to n and arr's logical size, n, 
//returns a new array's pointer w/ all numbers that are missing between 1 and n and the new array's size

int main() {
    int n = 6; // arr's size and range of numbers, 1 - n
    int arr[n] = {3, 1, 3, 0, 6, 4};

    int resArrSize = 0;
    int* resArr = NULL;

    sortArray(arr, n);
    resArr = findMissing(arr, n, resArrSize);

    cout << "The missing numbers are ";
    printArrayAtPtr(resArr, resArrSize);
    cout << endl
        << "There are " << resArrSize << " numbers in the new array.";

    delete [] resArr;
    resArr = NULL;
    return 0;
}

void printArrayAtPtr(int* arrPtr, int arrSize){
    for (int i = 0; i < arrSize; i++) {
        cout << *(arrPtr + i) << " ";
    }
    return;
}

void resizeArray(int*& arrPtr, int arrSize, int& arrPhysSize){
    int* tempArr = NULL;
    tempArr = new int [arrPhysSize * 2];
    for (int l = 0; l < arrSize; l++) {
        tempArr[l] = arrPtr[l];
    }
    delete [] arrPtr;
    arrPtr = tempArr;
    arrPhysSize *= 2;
    return;
}

void swap(int& num1, int& num2) {
    int temp; 
    temp = num1;
    num1 = num2;
    num2 = temp;
    return;
}

void sortArray(int arr[], int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        for (int j = i + 1; j < arrSize; j++) {
            if(arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
    return;
}

int* findMissing (int arr[], int n, int& resArrSize) {
    int* resArr = NULL;
    resArr = new int [1];
    int resArrPhysSize = 1;
    int j = 0;

    if (resArrSize == resArrPhysSize) {
        resizeArray(resArr, resArrSize, resArrPhysSize);
    }

    for (int i = 0; i < n; i++) {
        if (i != arr[i]) {
            resArr[j] = i;
            j++;
            resArrSize++;
        }
    }
    return resArr;
}