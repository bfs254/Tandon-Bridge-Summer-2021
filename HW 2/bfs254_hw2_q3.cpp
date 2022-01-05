#include <iostream> 
using namespace std;

int main() {

    int num_of_days_John_worked, num_of_hours_John_worked, num_of_minutes_John_worked;
    int num_of_days_Bill_worked, num_of_hours_Bill_worked, num_of_minutes_Bill_worked;
    int temp_sum_of_minutes, carry_over_minutes, temp_sum_of_hours, carry_over_hours;
    int total_days, total_hours, total_minutes; 

    cout<< "Please enter the number of days John has worked: "; 
    cin>> num_of_days_John_worked;
    cout<< "Please enter the number of hours John has worked: ";
    cin>> num_of_hours_John_worked;
    cout<< "Please enter the number of minutes John has worked: ";
    cin>> num_of_minutes_John_worked; 

    cout<< "\n";
    cout<< "Please enter the number of days Bill has worked: "; 
    cin>> num_of_days_Bill_worked;
    cout<< "Please enter the number of hours Bill has worked: ";
    cin>> num_of_hours_Bill_worked;
    cout<< "Please enter the number of minutes Bill has worked: ";
    cin>> num_of_minutes_Bill_worked; 

    temp_sum_of_minutes = num_of_minutes_John_worked + num_of_minutes_Bill_worked;
    carry_over_minutes = temp_sum_of_minutes / 60;
    total_minutes = temp_sum_of_minutes % 60;

    temp_sum_of_hours = carry_over_minutes + num_of_hours_John_worked + num_of_hours_Bill_worked;
    carry_over_hours = temp_sum_of_hours / 24; 
    total_hours = temp_sum_of_hours % 24; 

    total_days = carry_over_hours + num_of_days_John_worked + num_of_days_Bill_worked;


    cout<< "The total time both of them worked together is: "
        << total_days << " days, " << total_hours << " hours, and " << total_minutes << " minutes.";


    

    return 0; 
}