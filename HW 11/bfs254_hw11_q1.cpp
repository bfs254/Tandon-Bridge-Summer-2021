//Author: Briana Singleton
//NYU ID: bfs254
//HW 11 Q1
//Prints shapes recursively 
//Last modified: 24 September 2021

#include <iostream> 
#include <cmath> 
using namespace std;

void printTriangle(int n);
//takes positive integer, n
//print a textural image of a right triangle (aligned to the left) made with n lines of asterisks

void printOppositeTriangles(int n);
//takes a positive integer, n
//prints a textual image of two opposite right triangles (aligned to the left), each containing n lines, with asterisks

void printRuler(int n);
//takes a positive integer, n
//prints a vertical ruler with ((2^n) - 1) lines using '-' marks

int main() {
    printTriangle(2);
    printOppositeTriangles(10);
    printRuler(4);

    return 0;
}

void printTriangle(int n){
    if(n == 1) {
        cout << "*" << endl;
    }
    else {
        printTriangle(n - 1);
        for(int i = 0; i < n; i++) {
            cout << "*";
        }
        cout<< endl;
    }
    return;
}

void printOppositeTriangles(int n) {
    if(n == 1) {
        cout<< "*" << endl;
        cout << "*" << endl;
    }
    else {
        for (int j = 0; j < n; j++) {
            cout << "*";
        }
        cout<< endl;

        printOppositeTriangles(n - 1);

        for(int i = 0; i < n; i++) {
            cout << "*";
        }
        cout<< endl;
    }
    return;
}

void printRuler(int n) {
    int leftover;
    if (n == 1) {
        cout << "-" << endl;
        return;
    }
    else {
        if (n <= 4) {
            printRuler(n - 1);
            if (n == 2) {
                for (int i = 0; i < n; i++){
                    cout << "-";
                }
                cout << endl;
                printRuler(n - 1);
            }
            else if (n == 3) {
                for (int i = 0; i < n; i++){
                    cout << "-";
                }
                cout << endl;
                printRuler(n - 1);
            }
            else if (n == 4) {
                for (int i = 0; i < n; i++){
                    cout << "-";
                }
                cout << endl;
                printRuler(n - 1);
            }
        }
        else {
            leftover = n - 4;
            n = 4;
            printRuler(n);
            printRuler(leftover);
        }
    }
    return;
}
