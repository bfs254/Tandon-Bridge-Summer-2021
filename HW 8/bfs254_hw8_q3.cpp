//Author: Briana Singleton
//NYU ID: bfs254
//HW 8 Q3
//takes an array of integers and 
//returns that array in reverse order
//returns that array without odd numbers
//and returns that array with odd numbers first and even numbers last
//Last modified: 3 September 2021 

const int MAX_ARRAY_SIZE = 10;

#include <iostream> 
using namespace std;

void reverseArray(int arr[], int arrSize);
//takes an array of integers and its size
//returns array elements in reverse order

void removeOdd(int arr[], int& arrSize);
//takes an array of integers and its size 
//returns that array with only even values and updates array's size w/out odd #s

void swap(int& v1, int& v2);
void printArray(int arr[], int arrSize);

void splitParity(int arr[], int arrSize);
//takes an array of integers and its size
//returns that array with the odd #s first and even #s last



int main() {
    
    int arr1[10] = {9, 2, 14, 12, -3};
    int arrSize = 5;
    
    int arr2[10] = {21, 12, 6, 7, 14};
    int arr2Size = 5;

    int arr3[10] = {3, 6, 4, 1, 12};
    int arr3Size = 5;

    reverseArray(arr1, arrSize);

    removeOdd(arr2, arr2Size);
    printArray(arr2, arr2Size);
 
    splitParity(arr3, arr3Size);
    printArray(arr3, arr3Size);

    return 0;
}

void reverseArray(int arr[], int arrSize){
    for (int i = arrSize - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout<< endl;
    return;
}

void swap(int& v1, int& v2){
    int temp;
    temp = v1;
    v1 = v2;
    v2 = temp;
    return;
}
void printArray (int arr[], int arrSize) {
    int i; 
    for (i = 0; i < arrSize; i++){
        cout<< arr[i] << " ";
    }
    cout<< endl;
    return;
}
void removeOdd(int arr[], int& arrSize) {
    int i;
    int j = 0;
    int evenCount = 0;
    
    for (i = 0; i < arrSize; i++) {
        if (arr[i] % 2 == 0) {
            swap(arr[i], arr[j]);
            j++;
            evenCount++;
        }
    }
    arrSize = evenCount;
    return;
}

void splitParity(int arr[], int arrSize){
    int i; 
    int j = 0;

    for (i = 0; i < (arrSize); i++) {
        if ((arr[i] % 2 == 1) || (arr[i] % 2 == (-1))){ //odd
            swap(arr[i], arr[j]);
            j++;
        }
    }
}