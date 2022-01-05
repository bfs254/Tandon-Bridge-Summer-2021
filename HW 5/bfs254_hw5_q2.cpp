//Author: Briana Singleton
//NYU ID: bfs254
//HW5, Q2
//number guessing game, user guesses a number between 1 - 100 (inclusive), if they don't guess after 5 tries, the game ends
//Last Modified: 8 August 2021

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main () {

    int guessesLeft = 5, guessedIn = 0;
    int userGuess;
    int lowBound = 1, highBound = 100;
    int guessTarget;

    srand(time(0));
    guessTarget = (rand() % 100) + 1;

    cout<< "I thought of a number between 1 and 100! Try to guess it." << endl;

    do {
        cout<< "Range ["<< lowBound << ", " << highBound << "], number of guesses left: " << guessesLeft << endl
            << "Your guess: ";
        cin>> userGuess;
        
        guessesLeft--;
        guessedIn++;
        
        if ((userGuess > guessTarget) && (guessesLeft > 0)) {
            cout<< "Wrong! My number is smaller." << endl;
            highBound = userGuess - 1;
        }
        else if ((userGuess < guessTarget) && (guessesLeft > 0)) {
            cout<< "Wrong! My number is bigger." << endl;
            lowBound = userGuess + 1;
        }

        if (userGuess == guessTarget) {
            cout<< "Congrats! You guessed my number in " << guessedIn << " guesses." << endl;
        }
        else if (guessesLeft == 0) {
            cout<< "Out of guesses! My number is " << guessTarget << endl;
        }

    } while ((guessesLeft > 0) && (userGuess != guessTarget));
    
    return 0;
}