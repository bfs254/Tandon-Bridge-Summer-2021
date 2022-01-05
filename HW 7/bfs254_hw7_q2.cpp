//Author: Briana Singleton  
//NYU ID: bfs254
//HW7 Q2
//analyses digits and their divisors
//Last modified: 26 August 2021

#include <iostream> 
#include <cmath>
using namespace std; 

void analyzeDivisors(int num, int& outCountDivs, int& outSumDivs);
//Takes a number and returns how many divisors it has and the sum of the divisors

bool isPerfect(int num);
//Takes a number and returns true if that number is a perfect number and false if that number is not a perfect number

int main () {
    int m;
    int outCountDivs = 0, outSumDivs = 0, tempOutCountDivs = 0, tempOutSumDivs = 0;
    bool isPerfectNum;
    int i;

    cout<< "Please enter a positive integer greater than or equal to 2: ";
    cin>> m;

    cout<< "The perfect numbers between 2 and " << m << " are " << endl;
    for (i = 2; i <= m; i++){
        isPerfectNum = isPerfect(i);

        if (isPerfectNum) {
            cout<< i << endl;
        }
    }

    cout<< "The amicable numbers between 2 and " << m << " are " << endl;
    for (i = 2; i <= m; i++) {
        analyzeDivisors(i, outCountDivs, outSumDivs); //get i's divs' sum
        analyzeDivisors(outSumDivs, tempOutCountDivs, tempOutSumDivs); //get sum of i's divs' sum

        if ((tempOutSumDivs == i) && (i != outSumDivs)) { //if the sum of i's divs' sum equals i, the #s are amicable
            cout<< i << endl;
        }

        outSumDivs = 0;
        outCountDivs = 0;
        tempOutSumDivs = 0;
        tempOutCountDivs = 0;
    }

    return 0;
}

void analyzeDivisors(int num, int& outCountDivs, int& outSumDivs) {
    for (int i = 1; i < (sqrt(num)); i++) {
        if (num % i == 0) {
            outSumDivs += i;
            outCountDivs++;
        }
    }
    for (int i = (sqrt(num)); i > 1; i--) {
        if (num % i == 0) {
            outSumDivs += (num / i);
            outCountDivs++;
        }
    }
    return;
}

bool isPerfect(int num) {
    int outCountDivs = 0;
    int outSumDivs = 0;
    analyzeDivisors(num, outCountDivs, outSumDivs);

    if (num == outSumDivs) {
        return true;
    }
    else {
        return false;
    }
}