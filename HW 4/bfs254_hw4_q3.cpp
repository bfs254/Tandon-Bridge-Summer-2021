//Author name: Briana Singleton
//NYU ID: bfs254
//Assignment: HW4, Q3
//Takes a number represented in decimal and converts it to binary
//Last modified: 3 August 2021

#include <iostream>
#include <cmath>
using namespace std;

int main() {

    cout<< "Please enter a decimal number: \n";
    int n;
    cin>> n;

    int n_operations = n;

    if (n_operations < 0) {
        n_operations *= (-1);
    }
   
    int power_of_2 = 0;
    int save_exponent; // holds 2^k that was subtracted from n to find the positions of the 1s in n's binary equivalent
    int exponent;
    int binary = 0;

    while (n_operations > 0) {
        for (exponent = 0; power_of_2 < n_operations; exponent++) {
            power_of_2 = pow(2, exponent);

            if (power_of_2 > n_operations) {
                power_of_2 = pow(2, exponent - 1);
                break;
            }
        }

        save_exponent = exponent - 1;

        n_operations -= power_of_2;

        binary += pow(10, save_exponent);

        power_of_2 = 0;
    }

    if (n > 0) {
        cout<< "The binary representation of " << n << " is " << binary << "\n";
    }
    else {
        cout<< "The binary representation of " << n << " is -" << binary << "\n";
    }

    return 0;
}