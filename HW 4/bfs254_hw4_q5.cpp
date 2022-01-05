//Author name: Briana Singleton
//NYU ID: bfs254
//Assignment: HW4, Q5
//Takes a positive int from a user and prints a textual image of an hourglass
//made of 2n lines with asterisks (*)
//Last modified: 30 July 2021

#include <iostream>
using namespace std;

int main() {

    cout<< "Please enter a positive integer: ";
    int n;
    cin>> n;

    int line_count;
    int num_of_stars, star_count;
    int num_of_spaces, space_count;

    for (line_count = 1, num_of_stars = (2 * n) - 1, num_of_spaces = 0; line_count <= n; line_count++, num_of_stars -= 2, num_of_spaces++) {

            for (space_count = 0; space_count < num_of_spaces; space_count++){
                cout<< " ";
            }

            for (star_count = 1; star_count <= num_of_stars; star_count++){
                cout<< "*";
            }
            cout<< endl;
    }

    for (line_count = 1, num_of_stars = 1, num_of_spaces = n - 1; line_count <= n; line_count++, num_of_stars += 2, num_of_spaces--) {
        
        for (space_count = 0; space_count < num_of_spaces; space_count++){
            cout<< " ";
        }
        for (star_count = 1; star_count <= num_of_stars; star_count++) {
            cout<< "*";
        }

        cout<< endl;
    }

    return 0;
}