#include <iostream>
#include <utility> 

template <typename T>
void bubbleSort(T arr[], size_t arrSize) {
    //Step 1: For i = 0 to N-1 repeat Step 2
    for (size_t i = 0; i < arrSize; i++) {
        //Step 2: For j = i + 1 to N – 1 repeat
        for (size_t j = i + 1; j < arrSize; j++) {
            //Step 3: if arr[j] > arr[i]
            if (arr[j] > arr[i]) {
                //Swap arr[j] and arr[i]
                std::swap(arr[j], arr[i]);
            }
        }
    }
    //Step 4: Exit
}

//Function to print array
template <typename T>
void printArray(T arr[], size_t arrSize) {
    for (size_t i = 0; i < arrSize; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    //Array of values for sorting
    int arr[] = {94, 78, 25, 46, 83, 33, 48, 17, 29, 88, 56, 5, 96, 21, 65, 
                 57, 96, 87, 73, 50, 8, 15, 58, 9, 67, 84, 52, 44, 15, 
                 7, 9, 62, 85, 35, 8, 68, 20, 8, 86, 1, 97, 42, 7, 
                 45, 64, 72, 2, 12, 11, 27, 15, 20, 42, 73, 81, 61, 
                 9, 33, 57, 24, 40, 66, 86, 26, 53, 46, 94, 25, 55, 
                 32, 27, 52, 27, 34, 97, 43, 6, 51, 55, 17, 30, 22, 
                 89, 24, 95, 22, 37, 4, 55, 94, 81, 48, 60, 67, 26, 
                 66, 66, 20, 91, 21};

    size_t arrSize = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    printArray(arr, arrSize);

    bubbleSort(arr, arrSize);

    std::cout << "Sorted array: ";
    printArray(arr, arrSize);

    return 0;
}