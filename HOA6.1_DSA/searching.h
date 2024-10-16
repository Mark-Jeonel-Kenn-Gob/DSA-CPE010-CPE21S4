#ifndef SEARCHING_H
#define SEARCHING_H

#include <iostream>

template <typename T>
void linearSearch(T item, T* data, int n) {
    int i = 0; // Step 1: Initialize index

    // Step 2: Repeat while I <= n
    while (i < n) {
        if (item == data[i]) { // Check if the item matches the current data
            std::cout << "Searching is successful" << std::endl;
            return; // Exit if found
        }
        i++; // Move to the next index
    }
    std::cout << "Searching is Unsuccessful" << std::endl; // Item not found
}

#endif // SEARCHING_H