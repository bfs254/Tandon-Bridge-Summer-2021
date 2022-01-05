//a	program	that reads from the user two positive integers, and prints the result of when we add, subtract, 
//multiply, divide, div, and mod them.

#include <iostream>
using namespace std;

int main() {

    int user_num1, user_num2;
    double double_user_num1, double_user_num2; //store user input numbers as doubles for decimal division

    cout<< "Please enter two positive integers, separated by a space: ";
    cin>> user_num1 >> user_num2; 
    
    double_user_num1 = user_num1;
    double_user_num2 = user_num2;

    int add = user_num1 + user_num2;
    int subtract = user_num1 - user_num2;
    int multiply = user_num1 * user_num2;
    double floating_point_divide = double_user_num1 / double_user_num2;
    int integer_divide = user_num1 / user_num2;
    int modulo = user_num1 % user_num2; 

    cout<< user_num1 << " + " << user_num2 << " = " << add << " \n"
        << user_num1 << " - " << user_num2 << " = " << subtract << " \n"
        << user_num1 << " * " << user_num2 << " = " << multiply << " \n"
        << user_num1 << " / " << user_num2 << " = " << floating_point_divide << " \n"
        << user_num1 << " div " << user_num2 << " = " << integer_divide << " \n"
        << user_num1 << " mod " << user_num2 << " = " << modulo << " \n";


    return 0;
}