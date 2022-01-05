#include <iostream> 
using namespace std;

//all coin values are United States currency values (USD)
const int one_quarter = 25; //one quarter is 25 cents
const int one_dime = 10; //one dime is 10 cents
const int one_nickel = 5; //one nickel is 5 cents
const int one_penny = 1; //one penny is 1 cent
const int cents_in_one_dollar = 100; //there are 100 cents in one dollar

int main() {

    int user_dollars, user_cents;
    int sum_of_user_money, leftover_cents;
    int total_quarters, total_dimes, total_nickels, total_pennies; 

    cout<< "Please enter your amount in the format of dollars and cents separated by a space: \n";
    cin>> user_dollars >> user_cents; 
    sum_of_user_money = user_dollars * cents_in_one_dollar + user_cents; //sum of user's money in cents

    total_quarters = sum_of_user_money / one_quarter;
    leftover_cents = sum_of_user_money % one_quarter; 

    total_dimes = leftover_cents / one_dime;
    leftover_cents %= one_dime;

    total_nickels = leftover_cents / one_nickel;
    leftover_cents %= one_nickel;

    total_pennies = leftover_cents / one_penny;

    cout<< user_dollars << " dollars and " << user_cents << " cents are: \n"
        << total_quarters << " quarters, " << total_dimes << " dimes, " << total_nickels << " nickels, and " << total_pennies << " pennies \n";

    return 0; 
}