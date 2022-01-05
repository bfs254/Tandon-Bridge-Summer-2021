//Author name: Briana Singleton
//NYU ID: bfs254
//Assignment: HW4, Q1
//Reads a positive integer, userInt, from user and prints the first userInt even numbers
//Last modified: 30 July 2021

#include <iostream>
using namespace std;

int main() {

    cout<< "Section A \n"
        << "Please enter a positive integer: ";
    int userInt;
    cin>> userInt;

    int loopCounter = 1;
    int countBy2 = 0;

    while (loopCounter <= userInt) {
        countBy2 += 2;
        cout<< countBy2 << "\n";
        loopCounter++;
    }

    cout<< "\n"
        << "Section B \n"
        << "Please enter a positive integer: ";
    cin>> userInt;

    for (loopCounter = 1, countBy2 = 0; loopCounter <= userInt; loopCounter++) {
        countBy2 += 2;
        cout<< countBy2 << "\n";
    }

    return 0;
}