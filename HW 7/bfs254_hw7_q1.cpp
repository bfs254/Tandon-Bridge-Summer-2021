//Author: Briana Singleton
//NYU ID: bfs254 
//HW7 Q1
//prints yearly calendars
//Last modified: 23 August 2021

#include <iostream> 
using namespace std;

int printMonthCalendar (int numOfdays, int startingDay);
//Returns a number 1-7 that represents the day in the week of the last day in that month
//Ex) if the last day of the month is Saturday, it prints "6" and the calendar

bool isLeapYear (int year);
//Returns true if the year is a leap year and false if not

void printYearCalendar (int year, int startingDay);
//uses printMonthCalendar() and isLeapYear()
//prints formatted yearly calendar of that year
//ex) if printYearCalendar(2016, 5), Jan - Dec of 2016 prints and Jan 1st is on a Friday (5)

int main() {

    //interact with user here
    cout<< "Please enter the year and day the new year begins (1 for Monday, 6 for Saturday, 7 for Sunday, etc.) separated by a space: ";
    int currYear, startDay;
    cin>> currYear >> startDay;
    printYearCalendar(currYear, startDay);

    return 0;
}

int printMonthCalendar (int numOfDays, int startingDay){
    int daysInAWeek = 0;
    int endDay;

    cout<< "Mon    Tue    Wed    Thu    Fri    Sat    Sun" << endl;

    for (int spaceCount = 1; spaceCount < startingDay; spaceCount++){
        cout<< "       ";
    }
    for (int dateCounter = 1; dateCounter <= numOfDays; dateCounter++){
        if (dateCounter < 10) {
            cout<< dateCounter << "      "; //puts in 6 spaces if the date is a single digit #
        }
        else {
            cout<< dateCounter << "     "; //puts in 5 spaces if the date is a double digit #
        }

        if (dateCounter == 1) {
            daysInAWeek = startingDay - 1;
        }

        daysInAWeek++;
        
        if (daysInAWeek == 7) {
            cout<< endl;
            daysInAWeek = 0;
        }

        if (dateCounter == numOfDays) {
            endDay = daysInAWeek;
        }
    }
    cout<< endl << endl;

    return endDay;
}

bool isLeapYear (int year){
    if ((year % 4 == 0) && (year % 100 != 0)) {
        return true;
    }
    else if ((year % 4 == 0) && (year % 400 == 0)) {
        return true;
    }
    else {
        return false;
    }
}

void printYearCalendar (int year, int startingDay) {
    int monthsInAYear = 12;
    int currMonth = 2; //set to February
    bool isLeap = isLeapYear(year);

    cout<< "January " << year << endl;
    int tempStartDay = printMonthCalendar(31, startingDay) + 1; //prints January and stores February's start day in tempStartDay

    for (int monthCounter = 2; monthCounter <= monthsInAYear; monthCounter++) {
        switch (currMonth) {
            case 2: 
                cout<< "February " << year << endl;
                break;
            case 3: 
                cout<< "March " << year << endl;
                break;
            case 4: 
                cout<< "April " << year << endl;
                break;
            case 5: 
                    cout<< "May " << year << endl;
                    break;
            case 6: 
                cout<< "June " << year << endl;
                break;
            case 7: 
                cout<< "July " << year << endl;
                break;
            case 8: 
                cout<< "August " << year << endl;
                break;
            case 9: 
                cout<< "September " << year << endl;
                break;
            case 10: 
                cout<< "October " << year << endl;
                break;
            case 11: 
                cout<< "November " << year << endl;
                break;
            case 12: 
                cout<< "December " << year << endl;
                break;
        }

        if (currMonth == 2) {                               //February and leap year effects
            if (isLeap == true) {
                if (tempStartDay > 7) {
                    tempStartDay = 1;
                }
                tempStartDay = printMonthCalendar(29, tempStartDay) + 1;
            }
            else {
                if (tempStartDay > 7) {
                    tempStartDay = 1;
                }
                tempStartDay = printMonthCalendar(28, tempStartDay) + 1;
            }
        }
        else if ((currMonth >= 1) && (currMonth <= 7)) {
            if (currMonth % 2 == 1) {                      //alternates between 31 and 30 days for 1st half of year, odd months w/ 31 days, even months w/ 30
                if (tempStartDay > 7) {
                    tempStartDay = 1;
                }
                tempStartDay = printMonthCalendar(31, tempStartDay) + 1;
            }
            else {
                if (tempStartDay > 7) {
                    tempStartDay = 1;
                }
                tempStartDay = printMonthCalendar(30, tempStartDay) + 1;
            }
        }
        else {                                              //alternates between 31 and 30 days for 2nd half of year, odd months w/ 30 days, even months w/ 31
            if (currMonth % 2 == 1) {
                if (tempStartDay > 7) {
                    tempStartDay = 1;
                }
                tempStartDay = printMonthCalendar(30, tempStartDay) + 1;
            }
            else {
                if (tempStartDay > 7) {
                    tempStartDay = 1;
                }
                tempStartDay = printMonthCalendar(31, tempStartDay) + 1;
            }
        }
        currMonth++;
    }

    return;
}