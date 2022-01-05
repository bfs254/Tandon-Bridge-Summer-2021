//Author: Briana Singleton
//NYU ID: bfs254
//HW 5, Q1
//takes a positive integer, n, from user and prints an n by n multiplication table 
//Last Modified: 8 August 2021

#include <iostream>
using namespace std; 

int main () {

    cout<< "Please enter a positive integer: " << endl;
    int n; 
    cin>> n;

    int count2n, mult2n, product;

    for (count2n = 1; count2n <= n; count2n++) {

        for (mult2n = 1; mult2n <= n; mult2n++) {
            product = mult2n * count2n;
            cout<< product << "    ";
        }     
        cout<< endl;
    }

    return 0;
}