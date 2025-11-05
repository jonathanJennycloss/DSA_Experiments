#pragma once

#include <iostream>
#include "LL_node.hpp"

class LinkedList {
private:
    // Owning pointers. LinkedList is responsible for deleting the chain.
    Node* head;
    Node* tail;

public:
    // Construct a list with an initial value. This matches existing code and
    // tests in this repo. If a default-constructed empty list is required,
    // consider adding LinkedList() but update call sites accordingly.
    explicit LinkedList(int value);

    // Destroys all nodes owned by the list.
    ~LinkedList();

        void printList();

        Node* getHead();
        Node* getTail();
        
        void makeEmpty();
        void append(int value);

};


