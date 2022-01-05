//Author name: Briana Singleton
//NYU ID: bfs254
//Assignment: HW4, Q2
//Takes a user decimal number and converts it to its simplified Roman numeral form
//Last modified: 30 July 2021

#include <iostream>
#include <string>
using namespace std;

int main() {

    cout<< "Enter decimal number: \n";
    int user_num;
    cin>> user_num;

    int ones_digit, tens_digit, hundreds_digit, thousands_digit;
    int remaining_digits = user_num;
  
    ones_digit = remaining_digits % 10; 
    remaining_digits /= 10; 

    tens_digit = remaining_digits % 10; 
    remaining_digits /= 10;

    hundreds_digit = remaining_digits % 10;
    remaining_digits /= 10;

    thousands_digit = user_num / 1000; 
    //store all other digits starting from the thousands and going up 
    //to print that amount of Ms

    string roman_numeral; 

    if (thousands_digit > 0) {
        for (int i = 1; i <= thousands_digit; i++) {
            roman_numeral += "M";
        }
    }
    
    if ((hundreds_digit > 0) && (hundreds_digit < 5)) {
        for (int i = 1; i <= hundreds_digit; i++) {
            roman_numeral += "C";
        }
    }
    else if (hundreds_digit >= 5) {
        roman_numeral += "D";
        hundreds_digit -= 5;
        for (int i = 1; i <= hundreds_digit; i++) {
            roman_numeral += "C";
        }
    }

    if ((tens_digit > 0) && (tens_digit < 5)) {
        for (int i = 1; i <= tens_digit; i++) {
            roman_numeral += "X";
        }
    }
    else if (tens_digit >= 5) {
        roman_numeral += "L";
        tens_digit -= 5;
        for (int i = 1; i <= tens_digit; i++) {
            roman_numeral += "X";
        }
    }

    if ((ones_digit > 0) && (ones_digit < 5)) {
        for (int i = 1; i <= ones_digit; i++) {
            roman_numeral += "I";
        }
    }
    else if (ones_digit >= 5) {
        roman_numeral += "V";
        ones_digit -= 5;
        for (int i = 1; i <= ones_digit; i++) {
            roman_numeral += "I";
        }
    }
    
    cout<< "\n"
        << user_num << " is " << roman_numeral;

    return 0;
}