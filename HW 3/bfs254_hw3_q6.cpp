//Author name: Briana Singleton
//NYU ID: bfs254
//Assignment: HW3, q6
//Calculates the cost of a long-distance call based on the time the call started, the day of the week the call was made, and the length of the call
//Last modified: 27 July 2021

#include <iostream>
#include <string>
using namespace std;

const int WEEKDAY_40_CENT_RATE_START_HOUR = 8; //8:00AM
const int WEEKDAY_40_CENT_RATE_END_HOUR = 18; //18:00 (6:00PM)
const double WEEKDAY_8_TO_18_RATE = .4; //$0.40 for calls Monday to Friday started between 8:00AM and 18:00 (6:00PM)
const double WEEKDAY_19_TO_7_RATE = .25; // $0.25 for calls Monday to Friday started between 19:00 (7:00PM) and 7:00AM (the next morning)
const double WEEKEND_RATE = .15; //$0.15 for calls on Saturdays and Sundays

int main() {

    int call_time_hrs, call_time_mins, call_length;
    string call_day;
    char colon_holder;
    double call_cost;

    cout<< "Please input the time of your call in 24-hr format (ex. 1:30 PM = 13:30): ";
    cin>> call_time_hrs >> colon_holder >> call_time_mins;
    cout<< "Please input the day of your call using the first two letters \n"
        << "(ex. Mo = Monday, Th = Thursday, Sa = Saturday): ";
    cin>> call_day;
    cout<< "Please input the length of your call in minutes (ex. 15, 30, 75): ";
    cin>> call_length;

    if (call_day == "mo" || call_day == "MO" || call_day == "Mo") {
        if ((call_time_hrs >= WEEKDAY_40_CENT_RATE_START_HOUR) && (call_time_hrs <= WEEKDAY_40_CENT_RATE_END_HOUR)) {
            call_cost = call_length * WEEKDAY_8_TO_18_RATE;
            cout<< "A " << call_length<< " minute call on Monday at " << call_time_hrs << colon_holder << call_time_mins << " is $" << call_cost << " \n";
        }
        else {
            call_cost = call_length * WEEKDAY_19_TO_7_RATE; 
            cout << "A " << call_length<< " minute call on Monday at " << call_time_hrs << colon_holder << call_time_mins << " is $" << call_cost << " \n";
        }
    }

    else if (call_day == "tu" || call_day == "TU" || call_day == "Tu") {
        if ((call_time_hrs >= WEEKDAY_40_CENT_RATE_START_HOUR) && (call_time_hrs <= WEEKDAY_40_CENT_RATE_END_HOUR)) {
            call_cost = call_length * WEEKDAY_8_TO_18_RATE;
            cout << "A " << call_length<< " minute call on Tuesday at " << call_time_hrs << colon_holder << call_time_mins << " is $" << call_cost << " \n";
        }
        else {
            call_cost = call_length * WEEKDAY_19_TO_7_RATE; 
            cout << "A " << call_length<< " minute call on Tuesday at " << call_time_hrs << colon_holder << call_time_mins << " is $" << call_cost << " \n";
        }
    }

    else if (call_day == "we" || call_day == "WE" || call_day == "We") {
        if ((call_time_hrs >= WEEKDAY_40_CENT_RATE_START_HOUR) && (call_time_hrs <= WEEKDAY_40_CENT_RATE_END_HOUR)) {
            call_cost = call_length * WEEKDAY_8_TO_18_RATE;
            cout << "A " << call_length<< " minute call on Wednesday at " << call_time_hrs << colon_holder << call_time_mins << " is $" << call_cost << " \n";
        }
        else {
            call_cost = call_length * WEEKDAY_19_TO_7_RATE; 
            cout << "A " << call_length<< " minute call on Wednesday at " << call_time_hrs << colon_holder << call_time_mins << " is $" << call_cost << " \n";
        }
    }

    else if (call_day == "th" || call_day == "TH" || call_day == "Th") {
        if ((call_time_hrs >= WEEKDAY_40_CENT_RATE_START_HOUR) && (call_time_hrs <= WEEKDAY_40_CENT_RATE_END_HOUR)) {
            call_cost = call_length * WEEKDAY_8_TO_18_RATE;
            cout << "A " << call_length<< " minute call on Thursday at " << call_time_hrs << colon_holder << call_time_mins << " is $" << call_cost << " \n";
        }
        else {
            call_cost = call_length * WEEKDAY_19_TO_7_RATE; 
            cout << "A " << call_length<< " minute call on Thursday at " << call_time_hrs << colon_holder << call_time_mins << " is $" << call_cost << " \n";
        }
    }

    else if (call_day == "fr" || call_day == "FR" || call_day == "Fr") {
        if ((call_time_hrs >= WEEKDAY_40_CENT_RATE_START_HOUR) && (call_time_hrs <= WEEKDAY_40_CENT_RATE_END_HOUR)) {
            call_cost = call_length * WEEKDAY_8_TO_18_RATE;
            cout << "A " << call_length<< " minute call on Friday at " << call_time_hrs << colon_holder << call_time_mins << " is $" << call_cost << " \n";
        }
        else {
            call_cost = call_length * WEEKDAY_19_TO_7_RATE; 
            cout << "A " << call_length<< " minute call on Friday at " << call_time_hrs << colon_holder << call_time_mins << " is $" << call_cost << " \n";
        }
    }

    else if (call_day == "sa" || call_day == "SA" || call_day == "Sa") {
        call_cost = call_length * WEEKEND_RATE;
        cout << "A " << call_length<< " minute call on Saturday at " << call_time_hrs << colon_holder << call_time_mins << " is $" << call_cost << " \n";
    }

    else if (call_day == "su" || call_day == "SU" || call_day == "Su") {
        call_cost = call_length * WEEKEND_RATE;
        cout << "A " << call_length<< " minute call on Sunday at " << call_time_hrs << colon_holder << call_time_mins << " is $" << call_cost << " \n";
    }

    return 0;
}