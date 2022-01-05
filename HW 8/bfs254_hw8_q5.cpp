//Author: Briana Singleton
//NYU ID: bfs254
//HW 8 Q5
//takes a name and returns the name in Last, First Middle Initial order
//Last modified: 30 August 2021 

#include <iostream>
#include <string>
#include <cctype>
using namespace std; 

const int MAX_NUMBER_OF_NAMES_IN_FULL_NAME = 3;

void readFullName (string fullName[], int arrSize);
//reads in user's full name and stores it in an array

void capitalizeFirstLetter(string fullName[], int arrSize);
//reads users full name from array fullName[] and capitalizes the first letter of each name in the array

void formatNameInitial(string& name);
//reads name, isolates the first letter of name, and adds a period after the letter

int main() {

    string fullName[MAX_NUMBER_OF_NAMES_IN_FULL_NAME];
    readFullName(fullName, MAX_NUMBER_OF_NAMES_IN_FULL_NAME);
    capitalizeFirstLetter(fullName, MAX_NUMBER_OF_NAMES_IN_FULL_NAME);
    formatNameInitial(fullName[1]);

    cout<< fullName[2] << ", " << fullName[0] << " " << fullName[1] << endl;

    return 0;
}

void readFullName (string fullName[], int arrSize) {
    cout<< "Please enter your full name (ex. John A. Smith or John Allen Smith): ";
    for (int i = 0; i < arrSize; i++) {
        cin>> fullName[i];
    }
    return;
}

void capitalizeFirstLetter(string fullName[], int arrSize) {
    char firstLetterUpper;
    int nameLen;
    string tempName;

    for (int i = 0; i < arrSize; i++){
        nameLen = fullName[i].length() - 1;
        firstLetterUpper = toupper(fullName[i][0]);
        tempName = fullName[i].substr(1, nameLen);
        fullName[i] = firstLetterUpper + tempName;
    }
    return;
}

void formatNameInitial(string& name) {
    name = name.substr(0, 1);
    name = name + ".";
    return;
}