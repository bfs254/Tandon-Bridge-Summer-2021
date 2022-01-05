//Author: Briana Singleton
//NYU ID: bfs254
//WK 9 Q1
//takes a line of text and outputs the number of words in the line and the number of occurences of each letter
//Last modified: 12 September 2021

#include <iostream>
#include <string> 
#include <algorithm>
using namespace std; 

const int ENGLISH_ALPHABET_SIZE = 26;
const string ALPHABET = "abcdefghijklmnopqrstuvwxyz";

void readLine(string& str);
void strToLower(string& str);
void removeSpChars(string& str);
void wordCounter(string str);
string getIndivLetters(string str);
void printCountedLetters(string str);

int main() {
    string str;

    readLine(str);
    strToLower(str);
    removeSpChars(str);
    wordCounter(str);
    printCountedLetters(str);

    return 0;
}

void readLine(string& str) {
    cout<< "Please enter a line of text: " << endl;
    getline(cin, str);
    return;
}

void strToLower(string& str) {
    int i; 
    for(i = 0; i < str.length(); i++) {
        str[i] = tolower(str[i]);
    }
    return;
}

void removeSpChars(string& str) {
    int i;
    for (i = 0; i < str.length(); i++) {
        if ((str[i] == ',') || (str[i] == '.')) {
            str.erase(i, 1);
        }
    }
    return;
}

void wordCounter(string str) {
    int i, whiteSpaceCount = 0, wordCount;
    for (i = 0; i < str.length(); i++) {
        if (str[i] == ' ') {
            whiteSpaceCount++;
        }
    }
    wordCount = whiteSpaceCount + 1;
    cout<< wordCount << "    words" << endl;
    return;
}

void printCountedLetters (string str){
    int letterCount;

    for (int l = 0; l < ENGLISH_ALPHABET_SIZE; l++){
        letterCount = 0;
        for (int m = 0; m < str.length(); m++) {
            if (ALPHABET[l] == str[m]) {
                letterCount++;
            }
        }
        if (letterCount > 0) {
            cout << letterCount << "    " << ALPHABET[l] << endl;
        }
    }
    return;
}
