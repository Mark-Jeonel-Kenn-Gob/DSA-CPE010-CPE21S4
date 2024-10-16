#include <iostream>

using namespace std;

// Node structure for the linked list
template <typename T>
struct Node {
    T data;
    Node<T>* next;
};

// Function to create a new node
template <typename T>
Node<T>* new_node(T data) {
    Node<T>* newNode = new Node<T>;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to find the middle node
template <typename T>
Node<T>* findMiddle(Node<T>* start, Node<T>* last) {
    if (start == NULL) return NULL;

    Node<T>* slow = start;
    Node<T>* fast = start;

    while (fast != last && fast->next != last) {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

// Function to perform binary search
template <typename T>
bool binarySearch(Node<T>* head, T value) {
    Node<T>* start = head;
    Node<T>* last = NULL;
    int position = 1;

    while (true) {
        Node<T>* mid = findMiddle(start, last);

        if (mid == NULL) {
            cout << "Value " << value << " not found in the linked list." << endl;
            return false;
        }

        if (mid->data == value) {
            cout << "Value " << value << " found at position " << position << endl;
            return true;
        }

        else if (start == last) {
            break;
        }

        else if (mid->data < value) {
            start = mid->next;
            position++;
        }

        else {
            last = mid;
        }
    }

    cout << "Value " << value << " not found in the linked list." << endl;
    return false;
}

int main() {
    char choice = 'y';
    int count = 1;
    int newData;
    Node<int>* temp, *head, *node;

    while (choice == 'y') {
        cout << "Enter data: ";
        cin >> newData;

        if (count == 1) {
            head = new_node(newData);
            cout << "Successfully added " << head->data << " to the list.\n";
            count++;
        } else if (count == 2) {
            node = new_node(newData);
            head->next = node;
            node->next = NULL;
            cout << "Successfully added " << node->data << " to the list.\n";
            count++;
        } else {
            temp = head;
            while (true) {
                if (temp->next == NULL) break;
                temp = temp->next;
            }
            node = new_node(newData);
            temp->next = node;
            cout << "Successfully added " << node->data << " to the list.\n";
            count++;
        }

        cout << "Continue? (y/n)";
        cin >> choice;
        if (choice == 'n') break;
    }

    // Display the linked list
    Node<int>* currNode;
    currNode = head;
    cout << "Linked list: ";
    while (currNode != NULL) {
        cout << currNode->data << " ";
        currNode = currNode->next;
    }
    cout << endl;

    // Test the binary search function
    int searchValue;
    cout << "Enter a value to search: ";
    cin >> searchValue;
    binarySearch(head, searchValue);

    return 0;
}