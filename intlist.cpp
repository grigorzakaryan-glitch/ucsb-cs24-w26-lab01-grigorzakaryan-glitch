// intlist.cpp
// Implements class IntList
// YOUR NAME(S), AND DATE
// Grigor Zakaryan, January 12th 2025

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    //IMPLEMENT THIS
}

// destructor deletes all nodes
IntList::~IntList() {
    //IMPLEMENT THIS
}


// return sum of values in list
int IntList::sum() const {
    int sum = 0;

    Node* traverse = head;

    while(traverse){
        sum += traverse->info;
        traverse = traverse->next;
    }
    
    return sum; // REPLACE THIS NON-SOLUTION
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node* traverse = head;

    while(traverse){
        if(traverse->info == value){
            return true;
        }

        traverse = traverse->next;
    }

    return false; // REPLACE THIS NON-SOLUTION
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    if(!head){
        return 0;
    }

    int max = head->info;

    Node* traverse = head;

    while(traverse){
        if(traverse->info > max){
            max = traverse->info;
        }

        traverse = traverse->next;
    }

    return max;
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    if(!head){
        return 0;
    }

    return sum() / count();
}

// inserts value as new node at beginning of list
void IntList::push_front(int value) {
    // IMPLEMENT
    
    Node* newNode = new Node;
    newNode->info = value;
    newNode->next = head;
    head = newNode;

    if(!tail){
        tail = head;
    }
}

// append value at end of list
void IntList::push_back(int value) {
    // IMPLEMENT

    Node* newNode = new Node;
    newNode->info = value;    
    newNode->next = nullptr;

    if(!head){
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
 
}

// return count of values
int IntList::count() const {
   //IMPLEMENT THIS

    int numValues = 0;

    Node* traverse = head;

    while(traverse){
        numValues++;
        traverse = traverse->next;
    }

   return numValues;
}


//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    //IMPLEMENT
    return *this;
}

// constructor sets up empty list
IntList::IntList(){ 
    //IMPLEMENT THIS 

    head = nullptr;
    tail = nullptr;
}


// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = head;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

