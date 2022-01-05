//Author name: Briana Singleton
//NYU ID: bfs254
//Assignment: HW3, q4
//Allows a user to enter a decimal and perform floor rounding, ceiling rounding, or rounding to the nearest whole number
//Last modified: 27 July 2021

#include <iostream> 
using namespace std;

const int FLOOR_ROUND = 1;
const int CEILING_ROUND = 2;
const int ROUND = 3; 

int main() {

    double user_number;
    int user_rounding_choice, floor, ceiling, nearest_whole_round, temp_user_number_decimal, temp_ceiling;  

    cout<< "Please enter a Real number: \n";
    cin>> user_number;
    cout<< "Choose your rounding method: \n"
        << "1. Floor round\n"
        << "2. Ceiling round\n"
        << "3. Round to the nearest whole number\n";
    cin>> user_rounding_choice; 

    switch (user_rounding_choice) {
        case FLOOR_ROUND:                      // floor round: if num = -1.5, floor = -2
            if (user_number >= 0) {
                floor = user_number;
            }
            else {
                floor = user_number - 1;
            }
            cout<< floor;
            break;
        
        case CEILING_ROUND:                     // ceiling round: if num = -1.5, ceiling = -1
            temp_ceiling = user_number * 100;
            temp_ceiling %= 100; //isolate decimal;
            if ((user_number >= 0) && (temp_ceiling == 0)) {
                ceiling = user_number;
            }
            else if ((user_number >= 0) && (temp_ceiling > 0)) {
                ceiling = user_number + 1;
            }
            else {
                ceiling = user_number;
            }
            cout<< ceiling;
            break;

        case ROUND: 
            if (user_number >= 0) {
                temp_user_number_decimal = user_number * 100; 
                temp_user_number_decimal %= 100; //isolate the decimal 
            }
            else {
                temp_user_number_decimal = user_number * -100; 
                temp_user_number_decimal %= 100; //isolate the decimal 
            }

            if ((temp_user_number_decimal >= 50) && (user_number >= 0)) { //rounds up positive numbers
                nearest_whole_round = user_number + 1; 
            }
            else if ((temp_user_number_decimal >= 50) && (user_number < 0)) { //rounds up negative numbers
                nearest_whole_round = user_number - 1;
            }
            else if ((temp_user_number_decimal < 50) && (user_number >= 0)) { //rounds down positive numbers
                nearest_whole_round = user_number;
            }
            else if ((temp_user_number_decimal < 50) && (user_number < 0)) { //rounds down negative numbers
                nearest_whole_round = user_number;
            }

            cout<< nearest_whole_round;
            break;
    }

    return 0; 
}