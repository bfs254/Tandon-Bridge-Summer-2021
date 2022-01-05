/*
Author: Briana Singleton
NYU ID: bfs254
Assignment: Wk 16 HW Q2
Queue using a vector as a storage container
Created: 1 November 2021
Last modified: 5 November 2021
*/

#include <iostream> 
#include <vector> 
using namespace std;

template <class T>
class Queue{
private: 
    vector<T> data;
    int topIndex; //index of top of queue (if queue is empty, data[topIndex] would be data[0])
    int size;
    int physSize;
public: 
    Queue() : topIndex(0), size(0), physSize(0) {}

    T top() const { return data[topIndex]; }
    //returns value stored at topIndex

    void push(T newData) { data.push_back(newData); size++; physSize++; };
    //takes a new value and adds it to the end of the queue

    void pop();
    //removes the first value on the queue

    int getSize() const { return size; }
    //returns the logical size of the vector (not the physical size)

    int getPhysSize() const { return physSize; }

    bool isEmptyLogical() const { return size == 0; }
    //returns true if the vector's logical size is 0 and false if it's not

    bool isEmptyPhys() const { return data.size() == 0; }
    //returns true if vector's physical size is 0 and false if it's not

    void clear();
    //removes all elements from vector physically using vector's pop_back(), sets the value of topIndex, size, and physSize to 0

    template <class U> friend ostream& operator<< (ostream& os, Queue<U> q);
};

int main() {
    Queue<int> intQ;

    intQ.push(10);
    intQ.push(896);
    intQ.push(34);
    intQ.push(22);
    intQ.push(90);
    intQ.push(1);

    cout << intQ
        << "top: " << intQ.top() << endl
        << "size: " << intQ.getSize() << endl;

    intQ.pop();
    intQ.pop();
    
    cout << intQ
        << "top: " << intQ.top() << endl
        << "size: " << intQ.getSize() << endl;

    intQ.pop();
    intQ.pop();
    intQ.pop();
    intQ.pop();
    cout << "use of clear in pop function when logical size reaches 0: " << endl
        << "isEmptyLogical: " << intQ.isEmptyLogical() << endl
        << "isEmptyPhys: " << intQ.isEmptyPhys() << endl;

    intQ.push(1);
    intQ.push(100);
    intQ.push(1000);
    intQ.push(10000);

    intQ.pop();

    cout << intQ 
        << "top: " << intQ.top() << endl
        << "size: " << intQ.getSize() << endl
        << "call of clear function by user: " << endl;
        
    intQ.clear();

    cout << intQ
        << "isEmptyLogical: " << intQ.isEmptyLogical() << endl
        << "isEmptyPhys: " << intQ.isEmptyPhys() << endl;

    return 0;
}

template <class T>
void Queue<T>::pop() {  
    topIndex++;
    size--;
    if (size == 0) { // if logical size is 0, call clear to clean up all old queue values
        clear();
    }
}

template <class T> 
void Queue<T>::clear() {
    while(physSize > 0) {
        data.pop_back();
        physSize--;
    }
    topIndex = 0;

    if (size > 0) { // if clear is called by user instead of by pop()
        size = 0;
    }
}

template <class T>
ostream& operator<< (ostream& os, Queue<T> q) {
    if (q.size == 0 || q.physSize == 0) {
        os << "empty queue" << endl;
    }
    else {
        for (int i = q.topIndex; i < q.physSize; i++) {
            os << q.data[i] << " ";
        }
        cout << endl;
    }
    return os;
}   