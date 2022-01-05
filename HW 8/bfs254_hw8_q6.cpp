//Author: Briana Singleton
//NYU ID: bfs254
//HW 8 Q6
//takes a user ID and pin number and returns the user ID with the pin number censored using x's
//Last modified: 5 September 2021 

#include <iostream>
#include <string> 
#include <cctype>
using namespace std;

void findWhiteSpace(string str, int arr[], int& arrSize);
//takes a string, finds locations of white spaces, and stores locations in an array
void printIntArray(int arr[], int arrSize);
//takes an integer array and prints it
void splitStr(string str, string arr1[], int& arr1Size, int arr2[], int arr2Size);
//takes a string, the array from findWhiteSpace, splits each word of the string at the white spaces, 
//and stores them in a new array
void printStrArray(string arr[], int arrSize);
//takes an array of strings and prints it 
void censorStrings(string arr[], int arrSize);
//takes an array of strings and censors the string if there are only digits in the string

int main() {
    string str; 
    int strWhiteSpacesLogicalSize = 0;
    int strWhiteSpacesArr[100];

    int strArrLogicalSize = 0;
    string strArr[100];

    cout<< "Please enter a line of text: " << endl;
    getline(cin, str);

    findWhiteSpace(str, strWhiteSpacesArr, strWhiteSpacesLogicalSize);
    splitStr(str, strArr, strArrLogicalSize, strWhiteSpacesArr, strWhiteSpacesLogicalSize);
    censorStrings(strArr, strArrLogicalSize);
    printStrArray(strArr, strArrLogicalSize);

    return 0;
}

void printIntArray(int arr[], int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        cout<< arr[i] << " ";
    }
    return;
}

void printStrArray(string arr[], int arrSize) {
    for (int i = 0; i < arrSize; i++){
        cout << arr[i] << " ";
    }
    return;
}

void findWhiteSpace(string str, int arr[], int& arrSize) {
    int i;
    int j = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ') {
            arr[j] = i;
            j++;
            arrSize++;    
        }
    }
    return;
}

void splitStr(string str, string arr1[], int& arr1Size, int arr2[], int arr2Size) {
    int j = 0;
    for (int i = 0; i <= arr2Size; i++){
        if (i == 0) {
            arr1[i] = str.substr(0, (arr2[0] - 0));
            arr1Size++;
        }
        else if (j == (arr2Size - 1)) {
            arr1[i] = str.substr(arr2[j] + 1, ((str.length() - 1) - arr2[j]));
            arr1Size++;
        }
        else if ((i > 0) && (j < (arr2Size - 1))) {
            arr1[i] = str.substr(arr2[j] + 1, ((arr2[j + 1]) - (arr2[j] + 1)));
            arr1Size++;
            j++;
        }
    }
    return;
}

void censorStrings(string arr[], int arrSize) {
    string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int alphaCount = 0;
    int storeAlphaCount[50];
    int storeAlphaCountSize = 0;

    for (int i = 0; i < arrSize; i++){
        for (int j = 0; j < arr[i].length(); j++) {
            for (int k = 0; k <= alphabet.length(); k++) {
                if (arr[i][j] == alphabet[k]) {
                    alphaCount++;  
                }
            }
        }
        storeAlphaCount[i] = alphaCount;
        storeAlphaCountSize++;
        alphaCount = 0;
    }
    
    for (int l = 0; l < arrSize; l++) {
        if (storeAlphaCount[l] < 1) {
            for (int m = 0; m < arr[l].length(); m++) {
                arr[l][m] = 'x';
            }
        }
    }

    return;
}
