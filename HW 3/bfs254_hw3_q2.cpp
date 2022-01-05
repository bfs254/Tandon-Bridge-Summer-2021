//Author name: Briana Singleton
//NYU ID: bfs254
//Assignment: HW3, q2
//Determines an undergraduate's progress/classification (freshman, sophomore, junior, or senior) in a 4-year university program
//based off the current year and the year they will graduate
//Last modified: 27 July 2021

#include <iostream> 
#include <string>
using namespace std;

const int FRESHMAN = 4;
const int SOPHOMORE = 3;
const int JUNIOR = 2;
const int SENIOR = 1;
const int GRADUATE = 0;

int main() {

    string name; 
    int graduation_year, current_year, difference_btwn_years;  

    cout<< "Please enter your name: ";
    cin>> name;
    cout<< "Please enter your graduation year: ";
    cin>> graduation_year;
    cout<< "Please enter current year: ";
    cin>> current_year;

    difference_btwn_years = graduation_year - current_year; 

    if (graduation_year == current_year || difference_btwn_years < GRADUATE) {
        cout<< name << ", you have graduated \n";
    }
    else if (difference_btwn_years == FRESHMAN) {
        cout<< name << ", you are a freshman \n";
    }
    else if (difference_btwn_years == SOPHOMORE) {
        cout<< name << ", you are a sophomore \n";
    } 
    else if (difference_btwn_years == JUNIOR) {
        cout<< name << ", you are a junior \n";
    } 
    else if (difference_btwn_years == SENIOR) {
        cout<< name << ", you are a senior \n";
    } 
    else {
        cout<< name << ", you are not in college yet \n";
    }

    return 0; 
}