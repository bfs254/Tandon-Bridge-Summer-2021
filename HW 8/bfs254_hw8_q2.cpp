//Author: Briana Singleton
//NYU ID: bfs254
//HW 8 Q2
//takes a word from user and returns if it is a palindrome
//Last modified: 30 August 2021 

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isPalindrome(string str);
//takes a word stored in str from user 
//returns true if and only if str is a palindrome 

int main() {

    cout<< "Please enter a word: ";
    string word;
    cin>> word;

    isPalindrome(word);

    return 0;
}

bool isPalindrome(string str) {
    string strTemp;
    string strLower;
    int strLen = str.length() - 1;
    int i , j;

    for (i = 0; i <= strLen; i++) {
        strLower += tolower(str[i]);
    }

    for (j = strLen; j >= 0; j--) {
        strTemp += strLower[j];
    }

    if (strLower == strTemp) {
        cout<< str << " is a palindrome." << endl;
        return true;
    }
    else {
        cout<< str << " is not a palindrome." << endl;
        return false;
    }
}