#include <iostream>

int recursiveBinarySearch(int arr[], int low, int high, int key) {
    if (low > high) {
        std::cout << "Key not found" << std::endl;
        return -1;
    }

    int mid = low + (high - low) / 2;

    if (arr[mid] == key) {
        std::cout << "Key found at index " << mid << std::endl;
        return mid;
    } else if (arr[mid] < key) {
        return recursiveBinarySearch(arr, mid + 1, high, key);
    } else {
        return recursiveBinarySearch(arr, low, mid - 1, key);
    }
}

int main() {
    int arr[] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 8;

    recursiveBinarySearch(arr, 0, size - 1, key);

    return 0;
}