//Author: Briana Singleton
//NYU ID: bfs254
//WK 9 Q4
//takes an array of integers and its logical size, reorders elements
//Last modified: 12 September 2021

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int TEST_ARRAY_SIZE = 6;

void printArray(int arr[], int arrSize);

void fillArrays(int arr[], int arrSize);

void swap(int& int1, int& int2);

void oddsKeepEvensFlip(int arr[], int arrSize);
//takes an array of integers and its logical size
//reorders elements of array so that 
//1) all odds come before all evens 
//2) odd #s keep original relative order
//3) even #s are placed in reverse order

int main() {
    srand(time(0));
    
    int testArr1[TEST_ARRAY_SIZE];
    int testArr2[TEST_ARRAY_SIZE];
    int testArr3[TEST_ARRAY_SIZE];
    int testArr4[TEST_ARRAY_SIZE];
    
    fillArrays(testArr1, TEST_ARRAY_SIZE);
    printArray(testArr1, TEST_ARRAY_SIZE);
    oddsKeepEvensFlip(testArr1, TEST_ARRAY_SIZE);
    printArray(testArr1, TEST_ARRAY_SIZE);
    cout<< endl;

    fillArrays(testArr2, TEST_ARRAY_SIZE);
    printArray(testArr2, TEST_ARRAY_SIZE);
    oddsKeepEvensFlip(testArr2, TEST_ARRAY_SIZE);
    printArray(testArr2, TEST_ARRAY_SIZE);
    cout<< endl;

    fillArrays(testArr3, TEST_ARRAY_SIZE);
    printArray(testArr3, TEST_ARRAY_SIZE);
    oddsKeepEvensFlip(testArr3, TEST_ARRAY_SIZE);
    printArray(testArr3, TEST_ARRAY_SIZE);
    cout<< endl;

    fillArrays(testArr4, TEST_ARRAY_SIZE);
    printArray(testArr4, TEST_ARRAY_SIZE);
    oddsKeepEvensFlip(testArr4, TEST_ARRAY_SIZE);
    printArray(testArr4, TEST_ARRAY_SIZE);
    cout<< endl;

    for (int i = 0; i < 10; i++) {
        int arr[TEST_ARRAY_SIZE];
        fillArrays(arr, TEST_ARRAY_SIZE);
        printArray(arr, TEST_ARRAY_SIZE);
        oddsKeepEvensFlip(arr, TEST_ARRAY_SIZE);
        printArray(arr, TEST_ARRAY_SIZE);
        cout<< endl;
    }
   
    return 0;
}

void printArray(int arr[], int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
    }
    cout<< endl;
}

void fillArrays(int arr[], int arrSize) {
    int randNum;

    for (int i = 0; i < arrSize; i++) {
        randNum = rand() % 100 + 1;
        arr[i] = randNum;
    }
    return;
}

void swap(int& int1, int& int2) {
    int temp;
    temp = int1;
    int1 = int2;
    int2 = temp;

    return;
}

void oddsKeepEvensFlip(int arr[], int arrSize) {
    int j = 0, l = 0, m = 0, p;
    int evensArrSize = 0;
    int* evensArr = NULL;
    int* tempEvensArr = NULL;

    //count evens to determine evensArrSize
    for (int i = 0; i < arrSize; i++) {
       if (arr[i] % 2 == 0) {
        evensArrSize++;
       }
    }

    evensArr = new int [evensArrSize];
    tempEvensArr = new int [evensArrSize];

    //copy evens from arr to evensArr
    for (int k = 0; k < arrSize; k++) {
        if (arr[k] % 2 == 0) {
            evensArr[l] = arr[k];
            l++;
        }
    }

    //reverse evens in tempEvensArr
    for (int k = (evensArrSize - 1); k >= 0; k--) {
        tempEvensArr[m] = evensArr[k];
        m++;
    }

    //move reversed evens from tempEvensArr to evensArr
    delete [] evensArr;
    evensArr = tempEvensArr;
    tempEvensArr = NULL;

    //move odd #s to the front of arr
    for (int i = 0; i < arrSize; i++) {
        if ((arr[i] % 2 == 1) || (arr[i] % 2 == (-1))) {
            swap(arr[i], arr[j]);
            j++;
        }
    }

    p = arrSize - evensArrSize;

    //replace even #s at back of arr with reversed evens from evensArr 
    for (int i = 0; i < evensArrSize; i++) {
        arr[p] = evensArr[i];
        p++;
    }

    delete [] evensArr;
    evensArr = NULL;

    return;
}
