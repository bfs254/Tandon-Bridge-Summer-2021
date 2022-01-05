//Author name: Briana Singleton
//NYU ID: bfs254
//Assignment: HW3, q3
//Determines whether user-entered values for a, b, and c in the quadratic equation have infinite, no, no real, one, or two solutions; 
//provides solutions if they exist
//Last modified: 27 July 2021

#include <iostream>
#include <cmath>
using namespace std;

int main() {

    double a, b, c, test_for_solutions, quad_solution1, quad_solution2;

    cout<< "Please enter value of a: ";
    cin>> a;
    cout<< "Please enter value of b: ";
    cin>> b;
    cout<< "Please enter value of c: ";
    cin>> c; 

    test_for_solutions = (b * b) - (4 * a * c); // store the number result of the descriminant (b^2 - 4ac) of the quadratic equation 
                                                //to determine number of solutions

    if ((a == 0) && (b == 0) && (c == 0)) {
        cout<< "This equation has an infinite number of solutions. \n";
    }
    else if ((a == 0) && (b == 0)) {
        cout<< "This equation has no solutions. \n";
    }
    else if (test_for_solutions > 0) {
        quad_solution1 = ((-b) + sqrt((b * b) - 4 * a * c)) / (2 * a);
        quad_solution2 = ((-b) - sqrt((b * b) - 4 * a * c)) / (2 * a);
        
        cout<< "This equation has two real solutions x1 = " << quad_solution1 << " and x2 = " << quad_solution2 << "\n";
    }
    else if ((test_for_solutions == 0) && (a > 0) && (b > 0)) {
        quad_solution1 = ((-b) + sqrt((b * b) - 4 * a * c)) / (2 * a);

        cout<< "This equation has one real solution x = " << quad_solution1 << "\n";
    } 
    else if (test_for_solutions < 0) {
        cout<< "This equation has no real solutions. \n";
    }

    return 0; 
}