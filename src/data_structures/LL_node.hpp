#include <iostream>

/**
 * @brief Node class for singly linked list implementation
 * Represents a single node in the linked list containing an integer value
 * and a pointer to the next node
 */
class Node {
    public:
        int value;      // Data stored in the node
        Node* next;     // Pointer to the next node

        // Constructors
        Node() : value(0), next(nullptr) {}              // Default constructor
        Node(int val) : value(val), next(nullptr) {}     // Value constructor
        Node(const Node& other);                         // Copy constructor
        
        // Destructor
        ~Node() = default;  // Default destructor is sufficient as we don't own next
};