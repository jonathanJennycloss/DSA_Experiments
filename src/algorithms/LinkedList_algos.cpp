#include "../data_structures/LinkedList.hpp"
#include <iostream>

/**
 * @brief Finds the middle node of a linked list using the two-pointer technique
 * 
 * Uses the "tortoise and hare" algorithm where:
 * - slow pointer moves one step at a time
 * - fast pointer moves two steps at a time
 * When fast reaches the end, slow will be at the middle
 * 
 * @param list Reference to the LinkedList to search
 * @return Node* Pointer to the middle node, or nullptr if list is empty
 * 
 * Time Complexity: O(n) where n is the length of the list
 * Space Complexity: O(1) as only two pointers are used
 */
Node* findMiddleNode(LinkedList& list) {
    // Handle empty list case
    if(list.getHead() == nullptr) {
        return nullptr;
    }
    
    Node* slow = list.getHead();
    Node* fast = list.getHead();
            
    while(fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main() {
    LinkedList myList(1);
    myList.append(2);
    myList.append(3);
    myList.append(4);
    myList.append(5);

    Node* middle = findMiddleNode(myList);
    if (middle) {
        std::cout << "Middle node value: " << middle->value << std::endl;
    } else {
        std::cout << "The list is empty." << std::endl;
    }

    return 0;
}