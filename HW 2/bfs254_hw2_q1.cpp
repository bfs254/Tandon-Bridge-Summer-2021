#include <iostream> 
using namespace std;

//all coin values are United States currency values (USD)
const int one_quarter = 25; //one quarter is 25 cents
const int one_dime = 10; //one dime is 10 cents
const int one_nickel = 5; //one nickel is 5 cents
const int one_penny = 1; //one penny is 1 cent
const int cents_in_one_dollar = 100;//there are 100 cents in one dollar

int main() {

    int num_of_quarters, num_of_dimes, num_of_nickels, num_of_pennies;
    int temp_total_cents;
    double total_dollars, total_cents; 

    cout<< "Please enter number of coins: \n";
    cout<< "# of quarters: ";
    cin>> num_of_quarters;
    cout<< "# of dimes: ";
    cin>> num_of_dimes;
    cout<< "# of nickels: ";
    cin>> num_of_nickels;
    cout<< "# of pennies: ";
    cin>> num_of_pennies;
    

    temp_total_cents = num_of_quarters * one_quarter + num_of_dimes * one_dime + num_of_nickels * one_nickel + num_of_pennies * one_penny; 
    total_cents = temp_total_cents % cents_in_one_dollar;
    total_dollars = temp_total_cents / cents_in_one_dollar;

    cout<< "The total is " << total_dollars << " dollars and " << total_cents << " cents \n";



    return 0;
}