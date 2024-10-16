#include <iostream>

// Define the structure for a linked list node
struct Node {
    int data;
    Node* next;
};

// Function to find the middle element of a linked list
Node* findMiddle(Node* start, Node* last) {
    if (start == NULL) {
        return NULL;
    }

    if (start == last) {
        return start;
    }

    Node* slow = start;
    Node* fast = start->next;

    while (fast != last) {
        fast = fast->next;
        slow = slow->next;
        if (fast != last) {
            fast = fast->next;
        }
    }

    return slow;
}

// Function to perform binary search on a linked list
bool binarySearch(Node* head, int value) {
    Node* start = head;
    Node* last = NULL;
    int position = 1;

    while (true) {
        // Find the middle element
        Node* mid = findMiddle(start, last);

        // If the middle element is empty
        if (mid == NULL) {
            std::cout << "Value " << value << " not found in the linked list." << std::endl;
            return false;
        }

        // If the value is present at the middle element
        if (mid->data == value) {
            std::cout << "Value " << value << " found at position " << position << std::endl;
            return true;
        }

        // If the start and last node are overlapping
        else if (start == last) {
            break;
        }

        // If the value is less than the middle element
        else if (mid->data < value) {
            start = mid->next;
            position++;
        }

        // If the value is greater than the middle element
        else {
            last = mid;
        }
    }

    // Value not present
    std::cout << "Value " << value << " not found in the linked list." << std::endl;
    return false;
}

int main() {
    // Create a sample linked list
    Node* head = new Node();
    head->data = 1;
    head->next = new Node();
    head->next->data = 2;
    head->next->next = new Node();
    head->next->next->data = 3;
    head->next->next->next = new Node();
    head->next->next->next->data = 4;
    head->next->next->next->next = new Node();
    head->next->next->next->next->data = 5;

    // Perform binary search
    int value = 3;
    if (binarySearch(head, value)) {
        std::cout << "Value found!" << std::endl;
    } else {
        std::cout << "Value not found!" << std::endl;
    }

    return 0;
}