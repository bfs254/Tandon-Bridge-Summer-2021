/*Author: Briana Singleton
NYU ID: bfs254
HW 6, Q2
takes an integer, n, and returns an approximation of e with n digits of accuracy
Last modified: 13 August 2021*/

//EFFICIENT IMPLEMENTATION IS THETA(N)
//use DOUBLE data type to hold factorials

#include <iostream>
using namespace std;

int factorial(int n);
//Takes an integer provided in the eApprox() function or a programmer-given integer
//Returns the factorial of that integer

double eApprox(int n);
//Takes user-given integer, n
//Returns an approximation of e with n digits of accuracy 

int main() {

    cout<< "Please enter a positive integer: ";
    int n;
    cin>> n;

    cout<< eApprox(n);

    return 0; 
}

int factorial(int n) {
    int prod = 1;

    for (int i = 1; i <= n; i++) {
        prod *= i;
    }

    return prod;
}

double eApprox(int n) { 
    double e = 1;
    double fact1 = factorial(1);

    for (int j = 1; j <= n; j++) {
        e += (1 / fact1);
        fact1 *= (j + 1);
    } 
    return e;
}