#include <iostream>
#include "LinkedList.hpp"

LinkedList::LinkedList(int value) {
    // Create the initial node. head and tail point to the same node for a
    // one-element list.
    Node* newNode = new Node(value);
    head = newNode;
    tail = newNode;
}

LinkedList::~LinkedList(){
    // Delete the whole chain safely. This walks the list and deletes each
    // node. After this method runs all owned nodes are freed.
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
        std::cout << "empty";
    } else {
        while (temp != nullptr) {
            std::cout << temp->value;
            temp = temp->next;
            if (temp != nullptr) {
                std::cout << " -> ";
            }
        }
    }
    std::cout << std::endl;
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
    // Append to tail in O(1) time by keeping a `tail` pointer.
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}
