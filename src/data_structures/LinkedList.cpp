#include <iostream>
#include "LinkedList.hpp"

using namespace std;

LinkedList::LinkedList(int value) {
    Node* newNode = new Node(value);
    head = newNode;
    tail = newNode;
}

LinkedList::~LinkedList(){
    Node* temp = head;
    while (head) {
        head = head->next;
        delete temp;
        temp = head;
    }
}

void LinkedList::printList() {
    Node* temp = head;
    if (temp == nullptr) {
        cout << "empty";
    } else {
        while (temp != nullptr) {
            cout << temp->value;
            temp = temp->next;
            if (temp != nullptr) {
                cout << " -> ";
            }
        }
    }
    cout << endl;
}

Node* LinkedList::getHead() {
    return head;
}

Node* LinkedList::getTail() {
    return tail; 
}

void LinkedList::makeEmpty() {
    Node* temp = head;
    while (head) {
        head = head->next;
        delete temp;
        temp = head;
    }
    tail = nullptr;
}

void LinkedList::append(int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}
