//Author name: Briana Singleton
//NYU ID: bfs254
//Assignment: HW3, q5
//Determines user's Body Mass Index (BMI) based on their weight in pounds and their height in inches
//Last modified: 27 July 2021

#include <iostream>
using namespace std;

const double POUNDS_TO_KILOS = .453592;
const double INCHES_TO_METERS = .0254;
const double UNDERWEIGHT_MAX = 18.5; //highest BMI value to be classified as Underweight
const double NORMAL_MAX = 25; //highest BMI value to be classified as Normal
const double OVERWEIGHT_MAX = 30; //highest BMI value to be classified as Overweight 

int main() {

    double weight_pounds, height_inches, weight_kilos, height_cm, user_BMI;

    cout<< "Please enter weight (in pounds): ";
    cin>> weight_pounds;
    cout<< "Please enter height (in inches): ";
    cin>> height_inches;

    weight_kilos = weight_pounds * POUNDS_TO_KILOS;
    height_cm = height_inches * INCHES_TO_METERS;

    user_BMI = weight_kilos / (height_cm * height_cm);

    if (user_BMI < UNDERWEIGHT_MAX) {
        cout<< "The weight status is: Underweight";
    }
    else if ((user_BMI >= UNDERWEIGHT_MAX) && (user_BMI < NORMAL_MAX)) {
        cout<< "The weight status is: Normal";
    }
    else if ((user_BMI >= NORMAL_MAX) && (user_BMI < OVERWEIGHT_MAX)) {
        cout<< "The weight status is: Overweight";
    }
    else {
        cout<< "The weight status is: Obese";
    }

    return 0; 
}