//Author: Briana Singleton
//NYU ID: bfs254
//HW 12 
//Checkbook balancing program
//Last modified: 8 October 2021

#include <iostream>
#include <vector>
using namespace std;

class Money {
private: 
    long totalCents;
    long dollars; 
    int cents;
    bool correctMoneyFormat(int newCents);
    //reads new input if cents were entered with a value > 99
public:
// CONSTRUCTOR
    Money(long newDollars = 0, int newCents = 0) : dollars(newDollars), cents(newCents), totalCents((newDollars * 100) + newCents) {};    
    // w/ arguments: initializes according to arguments 

// ACCESSORS
    double getValue() const {return (totalCents * .01);}
    //returns the amount of totalCents in 0.00 format

// MUTATORS
    void readValue();
    //gets dollars and cents from user 

    void setValue(double amount);
    //sets dollars and cents according to argument

// FRIENDS
    friend istream& operator>> (istream& is, Money& amount);
    friend ostream& operator<< (ostream& os, Money& amount);
    friend Money operator+ (const Money& amount1, const Money& amount2);
    friend Money operator- (const Money& amount1, const Money& amount2);
};

class Check {
private: 
    int checkNumber;
    Money checkAmount;
    bool wasCashed; // 1 = true, was cashed before; 0 = false, was NOT cashed
public: 
// CONSTRUCTOR
    Check (int newCheckNumber = 1000, Money newCheckAmount = 0, bool newWasCashed = 0) : checkNumber(newCheckNumber), checkAmount(newCheckAmount.getValue()), wasCashed(newWasCashed) {};
    //default: initializes checkNumber to 1000, checkAmount to 0.00, and wasCashed to 0 (= false, not cashed)
    //with arguments: initializes check according to arguments 

// ACCESSORS
    int getCheckNumber() const {return checkNumber;}
    //prints the check's identifying number
    Money getCheckAmount() const {
        Money decimalVal;
        double temp;
        temp = checkAmount.getValue();
        decimalVal.setValue(temp);
        return decimalVal;
    }

    //prints the check's monetary value in USD
    bool getWasCashed() const;
    //returns whether or not the check was cashed 
    void printWasCashed() const;

    void outputCheck() {cout << "Check number: " << checkNumber << " Check amount: " << checkAmount << " Cashed?: "; printWasCashed(); cout << endl;};
    //prints out check number and check amount

// MUTATORS
    void setCheckNumber() {cin>> checkNumber;}
    //reads a new checkNumber from user
    void setCheckAmount() {checkAmount.readValue();}
    //reads a new checkAmount from user
    void setWasCashed() {cin>> wasCashed;}
    //reads if the entered check has been cashed from user
    bool correctCheckNumber(int checkNumber);
    //reads new input if check number was input with less or more than 4 digits

// FRIENDS
};

// CLASS FUNCTION/FRIEND DECLARATIONS
istream& operator>> (istream& is, Money& amount);
//overloaded operator>> for Money class

// GENERAL FUNCTION DECLARATIONS
void atmMenu(vector <Check>& checkVector, Money& depositsTotal);
//prints a menu to user with options to deposit cash or checks
//reads the type of deposit the user wishes to make

void getAndStoreChecks(vector<Check>& checkVector, Money& depositsTotal);
//reads and collects checks entered by the user into a vector   

Money totalOfCashedChecks(vector<Check> checkVector);
//returns the sum of all checks that have been cashed

void sortCashedUncashedChecks(vector<Check> checkVector, vector<int>& cashedVector, vector<int>& uncashedVector);
//separates checks from checkVector into cashed checks and uncashed checks
//the cashed and uncashed checks are stored in new vectors, cashed and uncashed 

void orderVectors(vector<int>& v);
//puts a vector in order from smallest to largest number

void getCashDeposits(vector <Check>& checkVector, Money& depositsTotal);
//reads a cash value entered by the user

void getOldAndNewAcctBalance(Money& oldBalance, Money& newBalance);
//reads the old and new account balance from the console

void printReceipt(vector <Check>& checkVector, vector <int> cashedVector, vector <int> uncashedVector, Money& depositsTotal, Money cashedChecksTotal, Money oldBalance, Money newBalance);
//prints final summary of transaction to user

int main() {
    vector <Check> checkDepositVec;
    vector <int> cashedChecksVec, uncashedChecksVec;
    Money depositsTotal; 
    Money cashedChecksTotal, oldBalance, newBalance;

    getOldAndNewAcctBalance(oldBalance, newBalance);
    atmMenu(checkDepositVec, depositsTotal);
    cashedChecksTotal = totalOfCashedChecks(checkDepositVec);
    sortCashedUncashedChecks(checkDepositVec, cashedChecksVec, uncashedChecksVec);
    printReceipt(checkDepositVec, cashedChecksVec, uncashedChecksVec, depositsTotal, cashedChecksTotal, oldBalance, newBalance);
    return 0;
}

// CLASS FUNCTION/FRIEND DEFINITIONS
istream& operator>> (istream& is, Money& amount) {
    char decimalPoint;
    long dollars;
    int cents;

    is >> dollars >> decimalPoint >> cents;
    
    amount.totalCents = dollars * 100 + cents;
    return is; 
}

ostream& operator<< (ostream& os, Money& amount) {
    os << "$" << amount.getValue();
    return os;
}

Money operator+ (const Money& amount1, const Money& amount2) {
    Money sum;
    sum.totalCents = amount1.totalCents + amount2.totalCents;
    return sum;
}

Money operator- (const Money& amount1, const Money& amount2) {
    Money difference;
    difference.totalCents = amount1.totalCents - amount2.totalCents;
    return difference;
}

void Money::readValue() {
    char decimalPoint;
    long newDollars;
    int newCents;

    cin >> newDollars >> decimalPoint >> newCents;
    while (correctMoneyFormat(newCents) == false) {
        cin >> newDollars >> decimalPoint >> newCents;
    }

    dollars = newDollars;
    cents = newCents;
    totalCents = (newDollars * 100) + newCents;
}

void Money::setValue(double amount) {
        int temp = amount * 100;
        cents = temp % 100; 
        dollars = temp / 100;
        totalCents = (dollars * 100) + cents;
};

bool Money::correctMoneyFormat(int newCents) {
    if (newCents > 99) {
        cout<< "Invalid input for cents. Please re-enter the amount." << endl;
        return false;
    }
    else {
        return true;
    }
}

bool Check::getWasCashed() const {
    if (wasCashed){ 
        return true;
    }
    else {
        return false;
    }
}

void Check::printWasCashed() const {
    if (wasCashed) {
        cout << "Check was cashed.";
    }
    else {
        cout << "Check was not cashed.";
    }
}

bool Check::correctCheckNumber(int checkNumber) {
    string checkNumStr;
    checkNumStr = to_string(checkNumber);  
    if (checkNumStr.length() < 4) {
        cout << "Too few digits in check ID number. Please re-enter your check ID number." << endl;
        return false;
    } 
    else if (checkNumStr.length() > 4) {
        cout << "Too many digits in check ID number. Please re-enter your check ID number." << endl;
        return false;
    }
    else {
        return true;
    }
}

// GENERAL FUNCTION DECLARATIONS

void atmMenu(vector<Check>& checkVector, Money& depositsTotal) {
    int menuAns;

    cout<< "Would you like to: " << endl
        << "1.) Deposit checks" << endl
        << "2.) Deposit cash" << endl;
    do {
        cin>> menuAns;
        if ((menuAns <= 0) || (menuAns >= 3)) {
            cout << "Invalid input, please press 1 to deposit checks or 2 to deposit cash." << endl;
        }
        else {
            switch(menuAns){
            case 1:
                getAndStoreChecks(checkVector, depositsTotal);
                break;
            case 2: 
                getCashDeposits(checkVector, depositsTotal);
                break;
            }
        }
    } while ((menuAns != 1) && (menuAns != 2));
}

void getAndStoreChecks(vector <Check>& checkVector, Money& depositsTotal) {
    bool seenNeg = false;
    int backToMenu = 0;

    cout<< "Please enter your check's 4-digit ID number, cash value, and whether or not you have cashed your check "
        << "in accordance with the prompts on your screen. " << endl
        << "When you have finished, please enter -1 in the field for the 4-digit ID number. " << endl << endl;

    while(seenNeg == false) {
        Check newCheck;

        cout << "Please enter the check's 4-digit identification number (from the top right corner of the check): #";
        newCheck.setCheckNumber();
        if (newCheck.getCheckNumber() < 0) {
            seenNeg = true;
        }
        else {
            while(newCheck.correctCheckNumber(newCheck.getCheckNumber()) == false) {
                newCheck.setCheckNumber();
            } 
            cout << "Please enter the cash value of your check with a decimal (ex.) 100.00, 1234.56, etc.): $";
            newCheck.setCheckAmount();

            cout << "Has your check been cashed? Type 1 for yes and 0 for no: ";
            newCheck.setWasCashed();

            checkVector.push_back(newCheck);
        }
    }

    cout<< "Would you like to return to the main menu?" << endl   
        << "Type 1 for 'yes' and 0 to get a session summary." << endl;
    cin>> backToMenu;
    if(backToMenu >= 1) {
        atmMenu(checkVector, depositsTotal);
    }
    else {
        return;
    }
}

Money totalOfCashedChecks (vector<Check> checkVector) {
    Money cashedCheckTotal; 

    for (int i = 0; i < checkVector.size(); i++) {
        if (checkVector[i].getWasCashed() == true) {
            cashedCheckTotal = cashedCheckTotal + checkVector[i].getCheckAmount();
        }
    }
    
    return cashedCheckTotal;
}

void sortCashedUncashedChecks(vector<Check> checkVector, vector<int>& cashedVector, vector<int>& uncashedVector) {
    for (int i = 0; i < checkVector.size(); i++) {
        if (checkVector[i].getWasCashed() == true) {
            cashedVector.push_back(checkVector[i].getCheckNumber());
        }
        else {
            uncashedVector.push_back(checkVector[i].getCheckNumber());
        }
    }
}

void orderVectors(vector<int>& v) {
    int min;
    int temp;
    for (int i = 0; i < v.size(); i++) {
        min = v[i];
        for (int j = 0; j < v.size(); j++) {
            if (v[i] < v[j]) {
                temp = v[j];
                v[j] = v[i];
                v[i] = temp;
            }
        }
    }
    return;
}

void getCashDeposits(vector <Check>& checkVector, Money& depositsTotal) {
    int backToMenu = 0;
    int anotherDeposit = 1;
    Money cash;

    do {
        cout << "Please enter the amount you wish to deposit with a decimal (ex.) 100.00, 1234.56, etc.): $";
        cash.readValue();
        
        depositsTotal = depositsTotal + cash;

        cout << "Would you like to make another deposit?" << endl
            << "Type 1 for 'yes' and 0 for 'no.'" << endl;
        cin >> anotherDeposit;

    } while (anotherDeposit > 0);

    cout<< "Would you like to return to the main menu?" << endl   
        << "Type 1 for 'yes' and 0 to get a session summary." << endl;
    cin>> backToMenu;
    if(backToMenu >= 1) {
        atmMenu(checkVector, depositsTotal);
    }
    else {
        return;
    }
}

void getOldAndNewAcctBalance(Money& oldBalance, Money& newBalance) {
    cout << "Welcome!" << endl
        << "Please enter your old account balance with a decimal (ex.) 100.00, 1234.56, etc.): $";
    oldBalance.readValue();
    cout << "Your old balance was " << oldBalance << endl;
   
    cout << "Please enter your new account balance with a decimal (ex.) 100.00, 1234.56, etc.): $";
    newBalance.readValue();
 
    return;
}

void printReceipt(vector <Check>& checkVector, vector <int> cashedVector, vector <int> uncashedVector, Money& depositsTotal, Money cashedChecksTotal, Money oldBalance, Money newBalance) {
    Money banksNewBalance, balanceDifference;
    banksNewBalance = oldBalance + cashedChecksTotal + depositsTotal;
    balanceDifference = newBalance - banksNewBalance;

    cout<< "**********************************************************************" << endl
        <<"Your former account balance was " << oldBalance << ". " << endl
        << "You have deposited " << depositsTotal << " in cash into your account." << endl
        << "**********************************************************************" << endl
        << "The following checks were entered: " << endl;
    
    if (checkVector.size() == 0) {
        cout << "none" << endl;
    }
    else {
        for (int i = 0; i < checkVector.size(); i++){
            checkVector[i].outputCheck();
        }
        cout<< "The following check numbers have been cashed: " << endl;
        orderVectors(cashedVector);
        if (cashedVector.size() == 0) {
            cout << "none" << endl;
        }
        else {
            for (int i = 0; i < cashedVector.size(); i++) {
                cout << cashedVector[i] << " ";
            }
        }
        cout << endl << "The following check numbers have not been cashed: " << endl;
        orderVectors(uncashedVector);
        if (uncashedVector.size() == 0) {
            cout << "none" << endl;
        }
        else {
            for (int i = 0; i < uncashedVector.size(); i++) {
                cout << uncashedVector[i] << " ";
            }
        }
        cout<< endl;
    }

    cout<< "The sum of the checks that were cashed is " << cashedChecksTotal << "." << endl
        << "**********************************************************************" << endl
        << "According to our records, your new account balance should be " << banksNewBalance << ". " << endl
        << "The difference between the new account balance you entered and the bank's records is " << balanceDifference << ". " << endl
        << "**********************************************************************" << endl;

    return;
}



