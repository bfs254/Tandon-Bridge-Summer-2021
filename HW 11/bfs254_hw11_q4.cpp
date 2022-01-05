//Author: Briana Singleton
//NYU ID: bfs254
//HW 11 Q4
//outputs the most efficient score for a game of "Jump It"
//Last modified: 24 September 2021

#include <iostream>
using namespace std;

int minJumpItSum(int board[], int boardSize);
//takes an integer array called board and its logical size
//returns the sum of the lowest costs of the game board

int min(int num1, int num2);
//takes two integer numbers 
//returns the smallest of the two

int main() {
    int n = 6;
    int jumpItBoard[n] = {0, 3, 80, 6, 20, 10};
    int result; 
    result = minJumpItSum(jumpItBoard, n);
    cout << result;
    return 0;
}

int min(int num1, int num2) {
    int minimum = num1;
    if (num2 < num1){
        minimum = num2;
    }
    return minimum;
}

int minJumpItSum(int board[], int boardSize) {
    int sum = 0;
    int smaller;

    if (boardSize == 1) {
        return board[0];
    }
    else {
        sum += minJumpItSum(board + 1, boardSize - 1);
        cout << "sum: " << sum << endl;
        smaller = min(board[0], board[1]);

        if (smaller == sum) {
            return sum += 0;
        }

        sum += smaller;

        if (smaller == board[0] && smaller == board[1]){
            board[0] = 0;
            board[1] = 0;
        }
        else if (smaller == board[0]) {
            board[0] = 0;
        }
        else {
            board[1] = 0;
        }
        return sum;
    }
}