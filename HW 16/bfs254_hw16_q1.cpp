/*
Author: Briana Singleton
NYU ID: bfs254
Assignment: Wk 16 HW Q1
Symbol balance checker using a stack
Created: 1 November 2021
Last modified: 5 November 2021
*/

//balance checker that returns T/F if symbols are balanced or not
//stack structure

#include <iostream> 
#include <fstream>
#include <string>
#include <stack>
using namespace std; 

void getAndOpenInputFile (ifstream& inputFile);

bool keywordsBalanced (ifstream& inputFile);
bool symbolsBalanced (ifstream& inputFile);
bool isBalanced (ifstream& inputFile);


int main() {

    ifstream pascalInput;
    getAndOpenInputFile(pascalInput);
    
    cout << isBalanced(pascalInput);

    pascalInput.close();
    return 0;
}

bool isBalanced(ifstream& inputFile) {
    bool keywords, symbols;

    keywords = keywordsBalanced(inputFile);
    symbols = symbolsBalanced(inputFile);

    if (keywords == true && symbols == true) {
        cout << "Keywords and symbols are balanced." << endl;
        return true;
    }
    else {
        cout << "Keywords and symbols are not balanced." << endl;
        return false;
    }
}

bool symbolsBalanced (ifstream& inputFile) {
    stack<char> symbolStack;
    char nextSymbol;
    bool areNotBalanced = false;

    while (areNotBalanced == false && inputFile >> nextSymbol){
       if (nextSymbol == '{' || nextSymbol == '(' || nextSymbol == '[') {
                symbolStack.push(nextSymbol);
        }
        else if (nextSymbol == '}' || nextSymbol == ')' || nextSymbol == ']') {
            if (nextSymbol == '}' &&  symbolStack.top() != '{') {
                areNotBalanced = true;
            }
            else if (nextSymbol == ')' && symbolStack.top() != '(') {
                areNotBalanced = true;
            }
            else if (nextSymbol == ']' && symbolStack.top() != '[') {
                areNotBalanced = true;
            }
            else {
                symbolStack.pop();
            }
        }
    }

    if (symbolStack.empty() == false) {
        areNotBalanced = true;
    }

    if (areNotBalanced == true) {
        cout << "Symbols are not balanced" << endl;
        return false;
    }
    else {
        cout << "Symbols are balanced" << endl;
        return true;
    }
}

bool keywordsBalanced (ifstream& inputFile) {
    stack<string> stringStack;
    string nextWord;
    bool areNotBalanced = false;

    while (areNotBalanced == false && inputFile >> nextWord) {
        if (nextWord == "BEGIN" || nextWord == "begin" || nextWord == "Begin") {
            stringStack.push(nextWord);
        }
        else if (nextWord == "END" || nextWord == "end" || nextWord == "End" 
            || nextWord == "END;" || nextWord == "end;" || nextWord == "End;"
            || nextWord == "END." || nextWord == "end." || nextWord == "End.") {
            
            if (stringStack.top() == "BEGIN" || stringStack.top() == "begin" || stringStack.top() == "Begin"){
                stringStack.pop();
            }
            else {
                areNotBalanced = true;
            }
        }
    }

    if (stringStack.empty() == false) {
        areNotBalanced = true;
    }
    

    if (areNotBalanced == true) {
        cout << "Keywords are not balanced" << endl;
        return false;
    }
    else {
        cout << "Keywords are balanced" << endl;
        return true;
    }
}

void getAndOpenInputFile (ifstream& inputFile) {
    string fileName;
    cout << "Please type the name of your input file and press enter: " << endl;
    cin >> fileName;
    inputFile.open(fileName);
    while(!inputFile) {
        cout << "File failed to open. Please type in your file again and press enter: " << endl;
        cin >> fileName;
        inputFile.clear();
        inputFile.open(fileName);
    }
    if(inputFile) {
        cout << "File opened successfully." << endl;
    }
}

