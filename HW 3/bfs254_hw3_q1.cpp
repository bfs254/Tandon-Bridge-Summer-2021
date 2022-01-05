//Author name: Briana Singleton
//NYU ID: bfs254
//Assignment: HW3, q1
//Computes how much a customer has to pay after purchasing 2 items in a buy 1, get 1 half off sale 
//with membership discount added in if they have a membership card
//Last modified: 27 July 2021

#include <iostream>
using namespace std;

const double MEMBERSHIP_DISCOUNT = .1;

int main() {

    double first_item_price, second_item_price, base_price, half_off_price_total;
    double discounted_price, amount_of_membership_discount, total_price;
    double tax_rate_percentage, tax_rate_decimal, tax_amount_on_discount_price;
    char club_card;

    cout<< "Enter price of first item: ";
    cin>> first_item_price;
    cout<< "Enter price of second item: ";
    cin>> second_item_price;
    cout<< "Does customer have a club card? (Y/N): ";
    cin>> club_card; 
    cout<< "Enter tax rate, e.g. 5.5 for 5.5\% tax: ";
    cin>> tax_rate_percentage;

    base_price = first_item_price + second_item_price;
    cout<< "Base price: " << base_price << "\n";
 
    if (first_item_price < second_item_price) {
        first_item_price = first_item_price / 2;
    }
    else if (first_item_price == second_item_price) {
        first_item_price = first_item_price / 2;
    }
    else {
        second_item_price = second_item_price / 2; 
    }

    half_off_price_total = first_item_price + second_item_price;

    if (club_card == 'y' || club_card == 'Y') {
        amount_of_membership_discount = half_off_price_total * MEMBERSHIP_DISCOUNT; //10% of half_off_price_total to subtract from half_off_price_total  
        discounted_price = half_off_price_total - amount_of_membership_discount; 
    }
    
    cout<< "Price after discounts: " << discounted_price << "\n";

    tax_rate_decimal = tax_rate_percentage / 100; //converts tax rate of ex) 5.5% to .055 decimal 
    tax_amount_on_discount_price = tax_rate_decimal * discounted_price; //amount of tax to add to the discounted price 
    total_price = tax_amount_on_discount_price + discounted_price; 
    
    cout<< "Total price: " << total_price << "\n";

    return 0; 
}