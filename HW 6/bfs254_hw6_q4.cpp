//Author: Briana Singleton
//NYU ID: bfs254
//HW 6, Q4
//takes an integer, n, and prints all divisors of n
//Last modified: 13 August 2021

//EFFICIENT IMPLEMENTATION IS THETA(SQRT(N))

#include <iostream>
#include <cmath>
using namespace std;

void printDivisors(int num);
//Takes a positive integer greater than or equal to 2, n
//Returns all divisors of n 

int main() {

    cout<< "Please enter a positive integer >=2: ";
    int n;
    cin>> n;

    printDivisors(n);

    return 0; 
}

void printDivisors(int num) {
    for (int i = 1; i < (sqrt(num)); i++) {
        if (num % i == 0) {
            cout << i << " ";
        }
    }

    for (int i = (sqrt(num)); i > 0; i--) {
        if (num % i == 0) {
            cout << num / i << " ";
        }
    }
   
    return;
}
