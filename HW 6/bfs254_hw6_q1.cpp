//Author: Briana Singleton
//NYU ID: bfs254
//HW 6, Q1
// takes an integer, n, and prints out the nth element of the Fibonacci sequence
//Last modified: 14 August 2021

#include <iostream>
using namespace std;

int fib(int n);
//Takes an integer n assigned by cin>> num
//Returns the n-th element of the Fibonacci sequence

int main() {

    cout<< "Please enter a positive integer: ";
    int num; 
    cin>> num;

    cout<< fib(num);

    return 0; 
}

int fib(int n) {
    int term1 = 1;
    int term2 = 1;
    int sum = 0;

    if ((n == 1) || (n == 2)) {
        return 1;
    }
    else {
        for (int i = 3; i <= n ; i++) {
            if (i % 2 == 1) {
                term1 += term2;
                sum = term1;
            }
            else {
                term2 += term1;
                sum = term2;
            }
        }

        return sum;
    }
}