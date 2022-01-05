//Author name: Briana Singleton
//NYU ID: bfs254
//Assignment: HW4, Q4
//Takes an integer sequence and calculates the geometric mean of those integers
//Last modified: 30 July 2021

#include <iostream>
#include <cmath>
using namespace std;

int main() {

    cout<< "Section A \n"
        << "Please enter the length of the sequence: ";
    double sequence_length;
    cin>> sequence_length;
    cout<< "Please enter your sequence: \n";

    double n;
    double product = 1;

    for (int sequence_counter = 1; sequence_counter <= sequence_length; sequence_counter++) {
        cin>> n;
        product *= n;
    }

    double geometric_mean; 
    double exponent = 1 / sequence_length;
    geometric_mean = pow(product, (1 / sequence_length));

    cout<< "The geometric mean is: " << geometric_mean << "\n\n";


    cout<< "Section B \n"
        << "Please enter a non-empty sequence of positive integers, "
        << "each one in a separate line. "
        << "End your sequence by typing -1: \n";
    
    bool seen_negative = false;
    product = 1;
    int digit_counter = 0; //counts # of digits entered 

    while (seen_negative == false) {
        cin>> n; 

        if (n < 0) {
            seen_negative = true;
        }
        else {
            product *= n;
            digit_counter++;
        }
        
    }

    exponent = 1 / (double) digit_counter;

    geometric_mean = pow(product, exponent);

    cout<< "The geometric mean is: " << geometric_mean;

    return 0;
}