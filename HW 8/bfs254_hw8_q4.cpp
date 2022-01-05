//Author: Briana Singleton
//NYU ID: bfs254
//HW 8 Q4
//takes an encoded pin number from user 
//Last modified: 30 August 2021 

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int USER_PIN = 98765;
const int PIN_MAPPING_RANGE = 10; //digits 0 - 9

void fillArrayRandNum1to3(int arr[], int arrSize); 
//fills an array of size 10 with random numbers from 1 to 3

void printPINMapping(int arr[], int arrSize); 
//prints the map of numbers 0 to 9 with corresponding randomly generated numbers from 1 to 3

int mapOfUserPin(int pin, int arr[], int arrSize); 
//gets the mapped version of the user's pin 

int readEnteredPin();
//gets pin from user 

void verifyPin(int userPin, int enteredPin);
//compares the const int USER_PIN to the entered pin from user

int main() {
    int pinMapping[PIN_MAPPING_RANGE];
    int enteredPIN;
    int mappedPIN;

    fillArrayRandNum1to3(pinMapping, PIN_MAPPING_RANGE);
    printPINMapping(pinMapping, PIN_MAPPING_RANGE);
    mappedPIN = mapOfUserPin(USER_PIN, pinMapping, PIN_MAPPING_RANGE);
    enteredPIN = readEnteredPin();
    verifyPin(mappedPIN, enteredPIN);
    return 0;
}

void fillArrayRandNum1to3(int arr[], int arrSize) {
    srand(time(0));
    for (int i = 0; i < 10; i++) {
        arr[i] = ((rand() % 3) + 1);
    }
    return;
}

void printPINMapping(int arr[], int arrSize){
    cout<< "Please enter your pin according to the following mapping: " << endl
        << "PIN:    0 1 2 3 4 5 6 7 8 9" << endl
        << "NUM:    ";
    for (int i = 0; i < 10; i++) {
        cout<< arr[i] << " ";
    }
    cout<< endl;
    return;
}

int mapOfUserPin(int pin, int arr[], int arrSize) {
    int mapOfUserPin = 0;
    int currDig, remainingDigs = pin;
    int digitPlace = 1;
    int i, j;

    for(i = 0; i < 5; i++){
        currDig = remainingDigs % 10;
        remainingDigs /= 10;

        for(j = 0; j < arrSize; j++) {
            if (currDig == j) {
                mapOfUserPin += (arr[j] * digitPlace);
                digitPlace *= 10;
            }
        }
    }
    return mapOfUserPin;
}

int readEnteredPin() {
    int enteredPin;
    cin>> enteredPin;
    return enteredPin;
}

void verifyPin(int userPin, int enteredPin) {
    if (enteredPin == userPin) {
        cout<< "Your PIN is correct" << endl;
    }
    else {
        cout<< "Your PIN is incorrect" << endl;
    }
    return;
}