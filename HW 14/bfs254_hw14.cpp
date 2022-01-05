//Author: Briana Singleton
//NYU ID: bfs254
//HW 14 
//function to take a vector of integers and return a new vector containing the min and max values of the original vector
//Last modified: 22 October 2021

#include <iostream>
#include <vector> 
using namespace std;

int min (int num1, int num2);

int max (int num1, int num2);

vector <int> copyVec (vector <int> v, int start, int end);

vector <int> findMinAndMax (vector <int> intVector);

int main() {
    vector <int> testVec;
    testVec.push_back(3);
    testVec.push_back(5);
    testVec.push_back(2);
    testVec.push_back(11);
    testVec.push_back(1);
    testVec.push_back(100);
    testVec.push_back(-1);

    vector <int> resultVec;
    resultVec = findMinAndMax(testVec);

    cout<< "The minimum number in the vector is " << resultVec[0] << ". " << endl 
        << "The maximum number in the vector is " << resultVec[1] << ". " << endl;

    return 0;
}

int min (int num1, int num2) {
    int min;
    if (num1 < num2) {
        min = num1;
    }
    else {
        min = num2;
    }
    return min;
}

int max (int num1, int num2) {
    int max; 
    if (num1 > num2) {
        max = num1; 
    }
    else {
        max = num2;
    }
    return max;
}

vector <int> copyVec (vector <int> v, int start, int end) { //start inclusive, end exclusive 
    vector <int> tempVec;

    for (int i = start; i < end; i++){
        tempVec.push_back(v[start]);
        start++;
    }

    return tempVec;
}

vector <int> findMinAndMax (vector <int> intVector) {
    vector <int> resultVec;
    int minNum, maxNum;

    if (intVector.size() == 1) {
        minNum = intVector[0];
        maxNum = intVector[0];
        resultVec.push_back(minNum);
        resultVec.push_back(maxNum);
        return resultVec;
    }
    else {
        int start, mid, end;
        start = 0;
        end = intVector.size(); 
        mid = (start + end) / 2;

        vector <int> firstHalf;
        vector <int> lastHalf;

        firstHalf = copyVec(intVector, start, mid); // mid exclusive, goes from indices 0 to 2 if 4 element array 

        lastHalf = copyVec(intVector, mid, end); // mid inclusive, from indices 2 to 4 if 4 element array 

        vector <int> firstHalfRes; // results of first half of vector
        vector <int> lastHalfRes; // results of last half of vector

        firstHalfRes = findMinAndMax(firstHalf);  

        lastHalfRes = findMinAndMax(lastHalf); 

        resultVec.push_back(min(firstHalfRes[0], lastHalfRes[0]));
        resultVec.push_back(max(firstHalfRes[1], lastHalfRes[1]));

        return resultVec;
    }
}

