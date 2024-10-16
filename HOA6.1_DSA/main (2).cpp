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

// Function to perform sequential search on Linked List
int sequentialSearchLinkedList(Node* head, int key) {
    int comparisons = 0;
    while (head != nullptr) {
        comparisons++;
        if (head->data == key) {
            std::cout << "Key found! Comparisons: " << comparisons << std::endl;
            return comparisons;
        }
        head = head->next;
    }
    std::cout << "Key not found. Comparisons: " << comparisons << std::endl;
    return comparisons;
}

// Function to perform sequential search on array
int sequentialSearchArray(int arr[], int size, int key) {
    int comparisons = 0;
    for (int i = 0; i < size; i++) {
        comparisons++;
        if (arr[i] == key) {
            std::cout << "Key found! Comparisons: " << comparisons << std::endl;
            return comparisons;
        }
    }
    std::cout << "Key not found. Comparisons: " << comparisons << std::endl;
    return comparisons;
}

int main() {
    // Linked List approach
    Node* head = NULL;
    int linkedListData[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
    int linkedListSize = sizeof(linkedListData) / sizeof(linkedListData[0]);

    for (int i = 0; i < linkedListSize; i++) {
        insertNode(head, linkedListData[i]);
    }

    int comparisonsLinkedList = sequentialSearchLinkedList(head, 18);

    // Array approach
    int arr[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
    int size = sizeof(arr) / sizeof(arr[0]);
    int comparisonsArray = sequentialSearchArray(arr, size, 18);

    return 0;
}