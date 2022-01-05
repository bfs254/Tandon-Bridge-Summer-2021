//Author: Briana Singleton
//NYU ID: bfs254
//WK 10 HW Q3
//takes a list of numbers and a number to search the list for
//Last modified: 16 September 2021

#include <iostream>
#include <vector>
using namespace std; 

//array function declarations
void resizeArray(int*& intArrPtr, int arrSize, int& arrPhysSize);
//takes an array pointer of type int, that array's size, and that array's physical size
//returns an array that is array's old physical size * 2

void printArray(int* arrPtr, int arrSize);
//takes an array pointer of type int and its size
//prints the array

void readIntsToArray(int*& intArrPtr, int& intArrSize);
//reads positive integers from user
//stores them in the array at intArrPtr

void searchArray(int* intArrPtr, int intArrSize);
//takes an array pointer of type int and its size
//reads a positive integer to search the array for
//prints the position(s) in the array the user integer is at

int main1(); //uses arrays

//vector function declarations---------------------------------------------------------------------------------------------------------------
void printVector(vector <int> intVec);
//takes a vector of type int
//prints the elements of vector

void readIntsToVector(vector <int>& intVec);
//reads positive integers from user
//stores them in the vector, intVec

void searchVector(vector <int> intVec);
//takes a vector of type int
//reads a positive integer to search the array for
//prints the position(s) in the array the user integer is at

int main2(); //uses vectors

int main() {
    main1();
    main2();
    return 0;
}

//array functions--------------------------------------------------------------------------------------------------------------------------
int main1() {
    int* intArrPtr = NULL;
    int intArrSize = 0;
    readIntsToArray(intArrPtr, intArrSize);
    searchArray(intArrPtr, intArrSize);

    delete [] intArrPtr;
    intArrPtr = NULL;
    return 0;
}

void printArray(int* arrPtr, int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        cout << *(arrPtr + i) << " ";
    }
}

void resizeArray(int*& intArrPtr, int arrSize, int& arrPhysSize){
    int* tempArr = NULL;
    tempArr = new int [arrPhysSize * 2];
    for (int l = 0; l < arrSize; l++) {
        tempArr[l] = intArrPtr[l];
    }
    delete [] intArrPtr;
    intArrPtr = tempArr;
    arrPhysSize *= 2;
    return;
}

void readIntsToArray(int*& intArrPtr, int& intArrSize) {
    bool seenNeg = false;
    int n;
    intArrPtr = new int [1];
    int intArrPhysSize = 1;
    int index = 0;

    cout << "Please enter a sequence of positive integers, each in a separate line. " << endl
        << "End your input by typing -1. " << endl;
    
    while (seenNeg == false) {
        cin >> n;
        if (n < 0) {
            seenNeg = true;
        }
        else {
            if (intArrSize == intArrPhysSize) {
                resizeArray(intArrPtr, intArrSize, intArrPhysSize);
            }
            intArrPtr[index] = n;
            index++;
            intArrSize++;
        }
    }
    return;
}   

void searchArray(int* intArrPtr, int intArrSize) {
    int n;
    int numCount = 0, numOfMatches = 0;
    cout << "Please enter a number you want to search." << endl;
    cin >> n;

    for (int i = 0; i < intArrSize; i++) {
        if (intArrPtr[i] == n) {
            numCount++;
        }
    }
    if (numCount == 0) {
        cout << n << " is not in this sequence.";
    }
    else {
        for (int i = 1; i <= intArrSize; i++) {
            if (intArrPtr[i - 1] == n) {
                if(numCount == 1) {
                    cout << n << " shows in line " << i << "."; 
                }
                else {
                    numOfMatches++;
                    if (numOfMatches == numCount){
                        cout << i << ". ";
                    }
                    else {
                        cout << n << " shows in lines " << i << ", ";
                    }
                }
            }
        }
    }
    return;
}

//vector functions------------------------------------------------------------------------------------------------------------------------
int main2() {
    vector <int> intVec;
    readIntsToVector(intVec);
    searchVector(intVec);
    return 0;
}

void printVector(vector <int> intVec) {
    for (int i = 0; i < intVec.size(); i++){
    cout<< intVec[i] << " ";
    }
    return;
}

void readIntsToVector(vector <int>& intVec) {
    bool seenNeg  = false;
    int n;

    cout << "Please enter a sequence of positive integers, each in a separate line. " << endl
         << "End your input by typing -1. " << endl;

    while (seenNeg == false) {
        cin >> n;
        if (n < 0) {
            seenNeg = true;
        }
        else {
            intVec.push_back(n);
        }
    }
    return;
}

void searchVector(vector <int> intVec){
    int n;
   int numCount = 0, numOfMatches = 0;
    cout << "Please enter a number you want to search." << endl;
    cin >> n;

    for (int i = 0; i < intVec.size(); i++) {
        if (intVec[i] == n) {
            numCount++;
        }
    }
    if (numCount == 0) {
        cout << n << " is not in this sequence.";
    }
    else {
        for (int i = 1; i <= intVec.size(); i++) {
            if (intVec[i - 1] == n) {
                if(numCount == 1) {
                    cout << n << " shows in line " << i << "."; 
                }
                else {
                    numOfMatches++;
                    if (numOfMatches == numCount){
                        cout << i << ". ";
                    }
                    else {
                        cout << n << " shows in lines " << i << ", ";
                    }
                }
            }
        }
    }
    return;
}

