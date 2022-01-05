//Author name: Briana Singleton
//NYU ID: bfs254
//Assignment: HW4, Q6
//Takes a user positive integer, n, and prints all numbers 1 to n 
//that have more even digits than odd digits
//Last modified: 30 July 2021

#include <iostream>
using namespace std;

int main() {

    cout<< "Please enter a positive integer: ";
    int n;
    cin>> n;

    int count_2_n;
    int evens_count;
    int odds_count;
    int current_digit;
    int remaining_digits;

    //counts up to n 
    for (count_2_n = 1; count_2_n <= n; count_2_n++) {
        evens_count = 0;
        odds_count = 0;

        remaining_digits = count_2_n;
        //iterate through value of count_2_n 
        while (remaining_digits > 0) {
            current_digit = remaining_digits % 10;
            remaining_digits /= 10;

            if (current_digit % 2 == 0) {
                evens_count++;
            }
            else {
                odds_count++;
            }
        }

        if (evens_count > odds_count) {
                cout<< count_2_n << "\n";
        }

    }

    return 0;
}