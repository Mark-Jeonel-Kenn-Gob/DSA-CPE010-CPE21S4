#include <iostream>

struct Node {
    int data;
    Node* next;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    if (newNode == NULL) {
        std::cout << "Memory error\n";
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the Linked List
void insertNode(Node*& head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* lastNode = head;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
}

// Function to count occurrences of 'key' in Linked List
int countOccurrencesLinkedList(Node* head, int key) {
    int count = 0;
    while (head != nullptr) {
        if (head->data == key) {
            count++;
        }
        head = head->next;
    }
    return count;
}

// Function to count occurrences of 'key' in array
int countOccurrencesArray(int arr[], int size, int key) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            count++;
        }
    }
    return count;
}

int main() {
    // Linked List approach
    Node* head = NULL;
    int linkedListData[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
    int linkedListSize = sizeof(linkedListData) / sizeof(linkedListData[0]);

    for (int i = 0; i < linkedListSize; i++) {
        insertNode(head, linkedListData[i]);
    }

    int countLinkedList = countOccurrencesLinkedList(head, 18);
    std::cout << "Occurrences of 18 in Linked List: " << countLinkedList << std::endl;

    // Array approach
    int arr[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
    int size = sizeof(arr) / sizeof(arr[0]);
    int countArray = countOccurrencesArray(arr, size, 18);
    std::cout << "Occurrences of 18 in Array: " << countArray << std::endl;

    return 0;
}