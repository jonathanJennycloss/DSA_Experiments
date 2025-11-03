#include "LL_node.hpp"

/**
 * @brief Copy constructor for Node class
 * Creates a deep copy of the node, but only copies the current node's value
 * Does not recursively copy the entire linked list to prevent infinite recursion
 * @param other The node to copy from
 */
Node::Node(const Node& other) : value(other.value), next(nullptr) {
    // Note: We don't copy other.next to avoid recursive copying of the entire list
    // The LinkedList class should handle the complete deep copying of the list structure
}