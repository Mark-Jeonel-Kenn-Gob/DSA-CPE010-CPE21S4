#include <iostream>

// Define the Node structure
template <typename T>
struct Node {
    T data;           // Data stored in the node
    Node* next;      // Pointer to the next node
};

// Function to create a new node
template <typename T>
Node<T>* new_node(T value) {
    Node<T>* newNode = new Node<T>(); // Allocate memory for a new node
    newNode->data = value;            // Set the data
    newNode->next = nullptr;          // Initialize next pointer to null
    return newNode;                   // Return the newly created node
}

// Linear search function for linked list
template <typename T>
void linearLS(Node<T>* head, T dataFind) {
    Node<T>* current = head; // Initialize current node to head

    while (current != nullptr) { // Traverse the linked list
        if (current->data == dataFind) { // Check if the current node's data matches the search value
            std::cout << "Searching is successful" << std::endl;
            return; // Exit if found
        }
        current = current->next; // Move to the next node
    }
    std::cout << "Searching is Unsuccessful" << std::endl; // Item not found
}

int main() {
    // Create linked list for the name "Kenn"
    Node<char>* name1 = new_node('K'); 
    Node<char>* name2 = new_node('e'); 
    Node<char>* name3 = new_node('n'); 
    Node<char>* name4 = new_node('n'); 

    // Link each node to each other
    name1->next = name2; 
    name2->next = name3; 
    name3->next = name4; 
    name4->next = nullptr; 

    // Perform linear search
    linearLS(name1, 'e'); // Searching for 'n'

    // Clean up memory (optional)
    Node<char>* current = name1;
    while (current != nullptr) {
        Node<char>* nextNode = current->next;
        delete current; // Deallocate memory for the current node
        current = nextNode; // Move to the next node
    }

    return 0;
}