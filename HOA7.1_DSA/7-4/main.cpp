#include <iostream>

//Insertion Sort function
template <typename T>
void insertionSort(T arr[], const int N) {
    int K = 1; //Start from the second element
    T temp; //Temporary variable for the current element

    //Step 1: Repeat Steps 2 to 5 for K = 1 to N-1
    while (K < N) {
        //Step 2: Set temp = A[K]
        temp = arr[K];
        
        //Step 3: Set J = K - 1
        int J = K - 1;

        //Step 4: Repeat while J >= 0 and temp < A[J]
        while (J >= 0 && temp < arr[J]) {
            //Set A[J + 1] = A[J]
            arr[J + 1] = arr[J];
            //Set J = J - 1
            J--;
        }
        //Step 5: Set A[J + 1] = temp
        arr[J + 1] = temp;

        //Increment K for the next iteration
        K++;
    }
    //Step 6: Exit
}

//Function to print the array
template <typename T>
void printArray(T arr[], const int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    //Example usage
    int arr[] = {94, 78, 25, 46, 83, 33, 48, 17, 29, 88, 56, 5, 96, 21, 65, 
                 57, 96, 87, 73, 50, 8, 15, 58, 9, 67, 84, 52, 44, 15, 
                 7, 9, 62, 85, 35, 8, 68, 20, 8, 86, 1, 97, 42, 7, 
                 45, 64, 72, 2, 12, 11, 27, 15, 20, 42, 73, 81, 61, 
                 9, 33, 57, 24, 40, 66, 86, 26, 53, 46, 94, 25, 55, 
                 32, 27, 52, 27, 34, 97, 43, 6, 51, 55, 17, 30, 22, 
                 89, 24, 95, 22, 37, 4, 55, 94, 81, 48, 60, 67, 26, 
                 66, 66, 20, 91, 21};

    const int arrSize = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    printArray(arr, arrSize);

    insertionSort(arr, arrSize);

    std::cout << "Sorted array: ";
    printArray(arr, arrSize);

    return 0;
}