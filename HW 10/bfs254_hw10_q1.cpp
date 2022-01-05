//Author: Briana Singleton
//NYU ID: bfs254
//WK 10 HW Q1
//takes a sentence and returns an array with each word of sentence as an element
//Last modified: 16 September 2021

#include <iostream>
#include <string>
#include <vector>
using namespace std; 

void getStr(string& sentence);
//gets a sentence from the user

void printStrArr (string* arrPtr, int arrSize);
//takes an array pointer of type string and that array's logical size

void stripSpChars(string& str);
//takes a string and strips away white space and special characters

vector <int> findWhiteSpace(string str);
//takes a string, str
//returns a vector of type int containing the indexes of the white spaces in str

void resizeArray(string*& arrPtr, int arrSize, int& arrPhysSize);
//takes an array pointer, arrPtr, of type string, the array's logical size, and the array's physical size
//arrPtr is call-by-reference, so the address of the newly resized array is assigned to arrPtr

string* createWordsArray(string sentence, int& outWordsArrSize);
//gets string, sentence, 
//returns a new array of strings containing all words in sentence
//also returns size of wordsArr

int main() {
    string* wordsArrPtr = NULL;
    string sentence;
    int wordsArrSize = 0;

    getStr(sentence);
    stripSpChars(sentence);
    wordsArrPtr = createWordsArray(sentence, wordsArrSize);
    printStrArr(wordsArrPtr, wordsArrSize);

    delete [] wordsArrPtr;
    wordsArrPtr = NULL;
    return 0;
}

void getStr(string& sentence) {
    cout << "Please type in a line of text: ";
    getline(cin, sentence);
    return;
}

void printStrArr (string* arrPtr, int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        cout << *(arrPtr + i) << " ";
    }
    return;
}

void stripSpChars(string& str){
    string spChars = "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
    int i, j;

    for(i = 0; i < str.length(); i++) {
        for (j = 0; j < spChars.length(); j++){
            if (str[i] == spChars[j]) {
                str.erase(i, 1);
            }
        }
    }
    return;
}

vector <int> findWhiteSpace(string str) {
    vector <int> whiteSpacePositions;

    for (int strInd = 0; strInd < str.length(); strInd++) {
        if(str[strInd] == ' ') {
            whiteSpacePositions.push_back(strInd);
        }
    }
    return whiteSpacePositions;
}

void resizeArray(string*& arrPtr, int arrSize, int& arrPhysSize){
    string* tempArr = NULL;
    tempArr = new string [arrPhysSize * 2];
    for (int l = 0; l < arrSize; l++) {
        tempArr[l] = arrPtr[l];
    }
    delete [] arrPtr;
    arrPtr = tempArr;
    arrPhysSize *= 2;
    return;
}

string* createWordsArray(string sentence, int& outWordsArrSize) {
    vector <int> whiteSpacePositions;
    whiteSpacePositions = findWhiteSpace(sentence);

    string* wordsArray = NULL;
    wordsArray = new string [1];
    outWordsArrSize = 0;
    int wordsArrPhysSize = 1;

    int j = 0;
    for (int i = 0; i <= whiteSpacePositions.size(); i++) {
        if (outWordsArrSize == wordsArrPhysSize) {
            resizeArray(wordsArray, outWordsArrSize, wordsArrPhysSize);
        }

        if (i == 0) {
            wordsArray[i] = sentence.substr(0, whiteSpacePositions[0]);
            outWordsArrSize++;
        }
        else if (j == (whiteSpacePositions.size() - 1)) {
            wordsArray[i] = sentence.substr(whiteSpacePositions[j] + 1, ((sentence.length() - 1) - whiteSpacePositions[j] + 1));
            outWordsArrSize++;
        }
        else if ((i > 0) && (j < whiteSpacePositions.size())) {
            wordsArray[i] = sentence.substr((whiteSpacePositions[j] + 1), (whiteSpacePositions[j + 1] - (whiteSpacePositions[j] + 1)));
            outWordsArrSize++;
            j++;
        }
    }
    return wordsArray;
}