//Author: Briana Singleton
//NYU ID: bfs254
//HW 11 Q3
//finds minimum in an array recursively 
//Last modified: 24 September 2021

#include <iostream> 
using namespace std;

int minInArray1(int arr[], int arrSize);
//takes array of integers and its logical size
//returns the minimum value of all elements in positions 0 to arrSize - 1

int minInArray2(int arr[], int low, int high);
//takes an array of integers and indices low and high (low <= high), which give the range of indices to evaluate
//returns the minimum value of all elements in positions low to high

int min(int num1, int num2);

int main() {
    int arr[10] = {9, -2, 14, 12, 3, 6, 2, 1, -9, 15};
    int res1, res2, res3, res4;

    res1 = minInArray1(arr, 10);
    res2 = minInArray2(arr, 0, 9);
    cout<< res1 << endl;
    cout << res2 << endl;

    res3 = minInArray2(arr, 2, 5);
    res4 = minInArray1(arr + 2, 4);
    cout << res3 << endl;
    cout << res4 << endl;

    return 0;
}

int min(int num1, int num2) {
    int min = num1; 
    if (num2 < num1) {
        min = num2;
    }
    return min;
}

int minInArray1(int arr[], int arrSize) {
    if (arrSize == 1) {
        return arr[0];
    }
    else {
        return min(arr[arrSize - 1], minInArray1(arr, arrSize - 1));
    }
}

int minInArray2(int arr[], int low, int high) {
    if (low == high) {
        return arr[low];
    }
    else {
        return min(arr[high - 1], minInArray2(arr, low, high - 1));
    }
}