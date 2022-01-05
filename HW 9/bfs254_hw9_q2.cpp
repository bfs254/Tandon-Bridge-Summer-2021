//Author: Briana Singleton
//NYU ID: bfs254
//WK 9 Q2
//checks if two strings are anagrams
//Last modified: 12 September 2021

#include <iostream>
#include <string>
using namespace std;

const int ENGLISH_ALPHABET_SIZE = 26;
const string ALPHABET = "abcdefghijklmnopqrstuvwxyz";

void readInput(string& str1, string& str2);
//reads 2 words, 1 word and 1 phrase, or 2 phrases from a user

void strToLower(string& str);
//takes a string and changes it to lowercase 
void stripSpChars(string& str);
//takes a string and strips away white space and special characters
void alphabetizeStrLetters(string& str);
//takes a string and alphabetizes it

bool compareStrLengths(string str1, string str2);
//takes two strings and returns true if they have the same number of letters and false if they do not

string getIndivLetters(string str);
//takes a string and returns a new string of the original string with no duplicates
void eraseChar (char ch, string& str);
//takes a character and a string and erases that character from the string

bool compareStrLetters(string str1, string str2);
//takes two strings and returns true if they have the same letters and false if they do not

void letterCount(string str, int letterCount[], int& letterCountSize);
//takes a string and counts the number of each letter in it, letter amounts are stored in an array
bool compareLetterAmounts(int letterCountStr1[], int letterCountStr1Size, int letterCountStr2[], int letterCountStr2Size);
//takes two int arrays and compares the amount of each letter present in each string

int main() {
    string str1 = "", str2 = "";
    string str1Copy, str2Copy;
    string lettersInStr1, lettersInStr2;
    bool sameLength, sameLetters, sameAmountOfEachLetter;
    int letterCountStr1[26];
    int letterCountStr1Size = 0;
    int letterCountStr2[26];
    int letterCountStr2Size = 0;

    readInput(str1, str2);
    
    str1Copy = str1;
    str2Copy = str2;
    
    strToLower(str1);
    strToLower(str2);
    stripSpChars(str1);
    stripSpChars(str2);
    alphabetizeStrLetters(str1);
    alphabetizeStrLetters(str2);
    sameLength = compareStrLengths(str1, str2);

    if (sameLength) {
        lettersInStr1 = getIndivLetters(str1);
        lettersInStr2 = getIndivLetters(str2);
        sameLetters = compareStrLetters(lettersInStr1, lettersInStr2);
    }
    if (sameLetters) {
        letterCount(str1, letterCountStr1, letterCountStr1Size);
        letterCount(str2, letterCountStr2, letterCountStr2Size);
        sameAmountOfEachLetter = compareLetterAmounts(letterCountStr1, letterCountStr1Size, letterCountStr2, letterCountStr2Size);
    }

    if (sameAmountOfEachLetter) {
        cout << "\"" << str1Copy << "\" and \"" << str2Copy << "\" are anagrams" << endl;
    }
    else {
        cout << "\"" << str1Copy << "\" and \"" << str2Copy << "\" are not anagrams" << endl;
    }

    return 0;
}

void readInput(string& str1, string& str2) { 
    cout << "Please type two lines of text. Press enter after each line: " << endl;
    getline(cin, str1);
    getline(cin, str2);
}

void alphabetizeStrLetters(string& str) {
    string alphabetizedStr = "";
    for (int i = 0; i < ENGLISH_ALPHABET_SIZE; i++){
        for (int j = 0; j < str.length(); j++){
            if (ALPHABET[i] == str[j]){
                alphabetizedStr += ALPHABET[i];
            } 
        }
    }
    str = alphabetizedStr;
    return;
}

void strToLower(string& str){
    int i; 

    for (i = 0; i < str.length(); i++) {
        if (str[i] >= 65 && str[i] <= 90) {
            str[i] += 32;
        }
    }
    return;
}

void stripSpChars(string& str){
    string spChars = "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
    int i, j;

    for(i = 0; i < str.length(); i++) {
        for (j = 0; j < spChars.length(); j++){
            if ((str[i] == spChars[j]) || (str[i] == ' ')) {
                str.erase(i, 1);
            }
        }
    }
    return;
}

bool compareStrLengths(string str1, string str2) {
    int str1Len = str1.length();
    int str2Len = str2.length();

    if (str1Len == str2Len) {
        return true;
    } 
    else {
        return false;
    }
}

string getIndivLetters(string str){
    int i, j;
    string lettersInStr = "";
    int strLen = str.length();
    string localAlpha = "abcdefghijklmnopqrstuvwxyz";

    for (i = 0; i < ENGLISH_ALPHABET_SIZE; i++) {
        for (j = 0; j < strLen; j++) {
            if (localAlpha[i] == str[j]) {
                lettersInStr += localAlpha[i];
                localAlpha.erase(i, 1);
            }
        }
    }
    return lettersInStr;
}

bool compareStrLetters(string str1, string str2) {
    int numOfMatches = 0;
    for (int i = 0; i < str1.length(); i++) {
            if (str1[i] == str2[i]) {
                numOfMatches++;
            }
    }
    if (numOfMatches == str1.length()) {
        return true;
    }
    else {
        return false;
    }
}

void letterCount(string str, int letterCount[], int& letterCountSize){
    int letterCounter;
    int k = 0;

    for (int i = 0; i < ENGLISH_ALPHABET_SIZE; i++) {
        letterCounter = 0;
        for (int j = 0; j < str.length(); j++) {
            if (ALPHABET[i] == str[j]){
                letterCounter++;
            }
        }
        if (letterCounter > 0) {
            letterCount[k] = letterCounter;
            k++;
            letterCountSize++;
        }
    }
    return;
}

bool compareLetterAmounts(int letterCountStr1[], int letterCountStr1Size, int letterCountStr2[], int letterCountStr2Size) {
    int numOfMatches = 0; 
    for (int i = 0; i < letterCountStr1Size; i++) {
        if (letterCountStr1[i] == letterCountStr2[i]) {
            numOfMatches++;
        }
    }
    if (numOfMatches == letterCountStr1Size) {
        return true;
    }
    else {
        return false;
    }
}