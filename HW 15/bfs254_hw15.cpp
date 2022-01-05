//Author: Briana Singleton
//NYU ID: bfs254 
//HW 15  
//Employee data system for payroll calculation  
//Last modified: 28 October 2021

//I have also included the text files I used for input testing for your use or reference on Gradescope. I don't know if you want them or not. 

#include <iostream> 
#include <fstream> 
#include <string>
#include <vector>
#include <algorithm>
using namespace std; 

template <class T>
class List;

template <class T> 
class Node {
private:
    T data;
    Node<T>* next;
    Node<T>* prev;
public: 
    Node(T newData = T(), Node<T>* newNext = nullptr, Node<T>* newPrev = nullptr) : data(newData), next(newNext), prev(newPrev) {}
    friend class List<T>;
    template <class U> friend ostream& operator<< (ostream& os, Node<U>& node);
};

template <class T>
class List {
private: 
    Node<T>* head;
    Node<T>* tail;
public: 
    List() : head(nullptr), tail(nullptr) {} 
    //copy constructor
    List(const List& rhs) : head(nullptr), tail(nullptr) { *this = rhs; }
    //assignment operator
    List<T>& operator=(const List<T>& rhs);
    //destructor
    ~List() { clear(); }
    void insertAtHead(T newData);
    void removeFromHead(); 
    bool isEmpty() { return (head == nullptr); }
    void clear() { while(!isEmpty()){ removeFromHead(); }}
    void insertAtPoint(T newData, T positionToInsertAfter);
    void removeFromPoint(int positionToRemove);
    void insertAtEnd(T newData);
    void removeFromEnd();
    int size();
    void print() const;
    void reversePrint() const;

    //Employee class specific functions
    void readHoursWorked(ifstream& inStream);
    void adjustEmployeesTotalPay();
    void printPayroll(vector<double>& employeePayVector, ostream& payrollFileOut);

    Node<T>* getHead() const{ return head;}
};   
    
class Employee {
private: 
    int id;
    double wage;
    string name;
    double hours;
    double totalPay;
public: 
    Employee(int newID = 3000, double newWage = 15.50, string newName = "Jack", double newHours = 0.00, double newTotalPay = 0.00) : 
    id(newID), wage(newWage), name(newName), hours(newHours), totalPay(newTotalPay) {}

    int getID() const { return id; }
    double getWage() const { return wage; }
    string getName() const { return name; }
    double getHours() const { return hours; } // consider making an hours class to account for minutes 
    double getTotalPay() const { return totalPay; }

    void setID(int newID) {id = newID;}
    void setWage(double newWage) { wage = newWage; }
    void setName(string newName) { name = newName;}
    void setHours(double newHours) { hours += newHours; }
    void setTotalPay(double newTotalPay) { totalPay = newTotalPay; }

    void adjustTotalPay(double hours, double wage) { totalPay = hours * wage; }

    friend ostream& operator<< (ostream& os, Employee& employee);
};

void getAndOpenInputFile (ifstream& inStream);
//gets the name of the input file from user and opens it 

void getAndOpenOutputFile (ofstream& outStream);

void readEmployeeInfo(List<Employee>& dataLst, ifstream& inStream);
//reads in employee info text file and stores that info in dataLst

ostream& operator<< (ostream& os, Employee& employee);
//prints Employee data: ID, salary, name, and hours worked

int main() {
    List <Employee> employeeDataLst;

    // read employee info text file into employeeDataList   
    ifstream employeeInfoInput;
    cout << "Please enter the input file for employee information: " << endl;
    getAndOpenInputFile(employeeInfoInput);
    readEmployeeInfo(employeeDataLst, employeeInfoInput); 
    employeeInfoInput.close();

    // read hours worked text file into employeeDataList
    ifstream hoursWorkedInput;
    cout << "Please enter the input file for the hours each employee worked: " << endl;
    getAndOpenInputFile(hoursWorkedInput);
    employeeDataLst.readHoursWorked(hoursWorkedInput); 
    hoursWorkedInput.close();

    // iterate through employeeDataList and calculate total pay for each employee
    employeeDataLst.adjustEmployeesTotalPay();

    ofstream payrollOutput;
    cout << "Please enter the output file for payroll information: " << endl;
    getAndOpenOutputFile(payrollOutput);
    
    vector<double> employeePayVec;
    employeeDataLst.printPayroll(employeePayVec, payrollOutput);

    payrollOutput.close();
    return 0;
}

void readEmployeeInfo(List <Employee>& dataLst, ifstream& inStream){
    int nextID;
    while (inStream >> nextID) { // read text file into inStream
        double localNextWage;
        string localNextName;

        inStream >> localNextWage;
        inStream.ignore(1, '\t');
        inStream.ignore();
        getline(inStream, localNextName); 
        dataLst.insertAtEnd(Employee(nextID, localNextWage, localNextName));
    }
}

void getAndOpenInputFile (ifstream& inStream) {
    string fileName;
    cin>> fileName;
    inStream.open(fileName);
    while (!inStream){
        cout<< "File failed to open. " << endl 
            << "Please re-enter the input file's name: ";
        cin>> fileName;
        inStream.clear();
        inStream.open(fileName);
    }
    if(inStream) {
        cout << "File opened successfully. " << endl;
    }
}

void getAndOpenOutputFile (ofstream& outStream) {
    string fileName;
    cin>> fileName;
    outStream.open(fileName);
    while (!outStream){
        cout<< "File failed to open. " << endl 
            << "Please re-enter the output file's name: ";
        cin>> fileName;
        outStream.clear();
        outStream.open(fileName);
    }
    if(outStream) {
        cout << "File opened successfully. " << endl;
    }
}

// EMPLOYEE CLASS FUNCTIONS
ostream& operator<< (ostream& os, Employee& employee){
    os.setf(ios::fixed);
    os.setf(ios::showpoint);
    os.precision(2);
    os  << "*********************************************" << endl
        << "ID: " << employee.getID() << endl
        << "Wage: $" << employee.getWage() << endl
        << "Name: " << employee.getName() << endl
        << "Hours worked: " << employee.getHours() << endl
        << "Total pay: $" << employee.getTotalPay() << endl 
        << "**********************************************" << endl;
    return os;
}

// NODE CLASS FUNCTIONS

template <class U>
ostream& operator<< (ostream& os, Node<U>& node) {
        os << node.data;
        return os;
}

// LINKED LIST CLASS FUNCTIONS
template <class T>
void List<T>::printPayroll(vector<double>& employeePayVector, ostream& payrollFileOut) {
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    payrollFileOut.setf(ios::fixed);
    payrollFileOut.setf(ios::showpoint);
    payrollFileOut.precision(2);

    Node<T>* iterator = head;
    int i = 0;

    while (iterator != nullptr) {
        employeePayVector.push_back(iterator->data.getTotalPay());
        iterator = iterator->next;
    }

    sort(employeePayVector.begin(), employeePayVector.end(), greater<double>());

    cout << endl << "**********Payroll Information**********" << endl; 
    payrollFileOut << endl << "**********Payroll Information**********" << endl; 

    int positionCounter; 

    for (int i = 0; i < employeePayVector.size(); i++) {
        iterator = head;
        positionCounter = 0;
        while (iterator != nullptr) {
            if (employeePayVector[i] == iterator->data.getTotalPay()) {
                cout << iterator->data.getName() << ", $" << employeePayVector[i] << endl;
                payrollFileOut << iterator->data.getName() << ", $" << employeePayVector[i] << endl;
                if (positionCounter == 0) {
                    removeFromHead();   
                }
                else if (positionCounter == (this->size())){
                    removeFromEnd();                   
                }
                else {
                    removeFromPoint(positionCounter);     
                }
            }
            positionCounter++; 
            iterator = iterator->next;
        }
    }
    cout << "**************End Payroll**************" << endl << endl; 
    payrollFileOut << "**************End Payroll**************" << endl << endl; 
}

template <class T>
void List<T>::adjustEmployeesTotalPay() {
    Node<T>* iterator = head;
    if (head == nullptr) {
        cout << "list is empty" << endl;
    }
    else {
        while (iterator != nullptr) {
            iterator->data.adjustTotalPay(iterator->data.getHours(), iterator->data.getWage());
            iterator = iterator->next;
        }
    }
}

template <class T>
void List<T>::readHoursWorked(ifstream& inStream) { 
    int nextID;
    double hoursWorked;
    Node<T>* nextEmployee = head; // nextEmployee points to head node in list

    while (inStream >> nextID) {
        if (nextID == nextEmployee->data.getID()) { //if ID matches ID in list, add hours
            inStream >> hoursWorked;
            nextEmployee->data.setHours(hoursWorked);
        }
        else { // if the IDs don't match, check the next ID
            nextEmployee = nextEmployee->next;
            if (nextID == nextEmployee->data.getID()) {
                inStream >> hoursWorked;
                nextEmployee->data.setHours(hoursWorked);
            }
        }
    }
}

template <class T> 
void List<T>::insertAtHead(T newData) {
    if (size() == 0) {
        Node<T>* firstNode = new Node<T> (newData, nullptr, nullptr);
        head = firstNode;
        tail = firstNode;
    }
    else {
        Node<T>* oldHead = head;
        Node<T>* newHead = new Node<T> (newData, oldHead, nullptr);
        head = newHead;
        oldHead->prev = newHead; 
    }
}

template <class T> 
void List<T>::removeFromHead() {
    Node<T>* oldHead = head;
    
    if (size() > 1 && head != tail) {
        head = oldHead->next;
        head->prev = nullptr;
        delete oldHead;
    }
    else if (size() == 1 && head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
    }
}

template <class T> 
void List<T>::insertAtPoint(T newData, T positionToInsertAfter) {
    Node<T>* iterator = head;
    int positionCounter = 0;

    while(positionCounter != positionToInsertAfter) {
        iterator = iterator->next;
        positionCounter++;
    }

    if(positionCounter == positionToInsertAfter){
        Node<T>* newNode = new Node<T> (newData, iterator->next, iterator);
        Node<T>* temp = iterator->next;
        iterator->next = newNode;
        temp->prev = newNode;
    }
}

template <class T> 
void List<T>::removeFromPoint(int positionToRemove){
    Node<T>* iterator = head;
    int positionCounter = 0;

    if (size() == 1 && tail == head) {
        delete tail;
        tail = nullptr;
        head = nullptr;
    }
    else {
        while (positionCounter != positionToRemove) {
            iterator = iterator->next;
            positionCounter++;
        }
        iterator->prev->next = iterator->next;
        iterator->next->prev = iterator->prev;
        delete iterator;
    }
}

template <class T>
void List<T>::insertAtEnd(T newData) {
    if (size() == 0) {
        insertAtHead(newData);
    }
    else {
        Node<T>* oldTail = tail;
        Node<T>* newTail = new Node<T> (newData, nullptr, oldTail);
        tail = newTail;
        oldTail->next = newTail;
    }
}

template <class T> 
void List<T>::removeFromEnd() {
    Node<T>* oldTail = tail;

    if (size() > 1 && tail != head) {
         tail = oldTail->prev;
        tail->next = nullptr;
        delete oldTail;
    }
    else if (size() == 1 && tail == head) {
        delete tail;
        tail = nullptr;
        head = nullptr;
    }
}

template <class T> 
int List<T>::size() {
    int size = 0;
    Node<T>* iterator = head;
    while (iterator != nullptr) {
        size++;
        iterator = iterator->next;
    }
    return size;
}

template <class T> 
void List<T>::print() const {
    Node<T>* iterator = head;
    if (head == nullptr) {
        cout << "list is empty" << endl;
    }
    else {
        while(iterator != nullptr) {
            cout << iterator->data << " ";
            iterator = iterator->next;
        }
    }
}

template <class T> 
void List<T>::reversePrint() const {
    Node<T>* iterator = tail;
    while (iterator != nullptr) {
        cout << iterator->data << " ";
        iterator = iterator->prev;
    }
}

