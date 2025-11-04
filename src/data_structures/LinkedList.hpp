#include <iostream>
#include "LL_node.hpp"

class LinkedList {
    private:
        Node* head;
        Node* tail;
        
    public:
        LinkedList(int value);
        ~LinkedList();

        void printList();

        Node* getHead();
        Node* getTail();
        
        void makeEmpty();
        void append(int value);

};


