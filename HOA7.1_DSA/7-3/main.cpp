#include <iostream>
#include <utility> // For std::swap

//Routine to find the position of the smallest element
template <typename T>
int Routine_Smallest(T A[], int K, const int arrSize) {
    int position = K; //Initialize position to K
    T smallestElem = A[K]; //Initialize smallestElem to A[K]

    //Step 3: For J = K + 1 to N - 1, repeat
    for (int J = K + 1; J < arrSize; J++) {
        if (A[J] < smallestElem) { //If a smaller element is found
            smallestElem = A[J]; //Update smallestElem
            position = J; //Update position
        }
    }
    //Step 4: Return position of the smallest element
    return position;
}

//Selection Sort function
template <typename T>
void selectionSort(T arr[], const int N) {
    int POS, temp;

    //Step 1: Repeat Steps 2 and 3 for K = 0 to N - 1
    for (int i = 0; i < N; i++) {
        //Step 2: Call routine smallest(A, K, N)
        POS = Routine_Smallest(arr, i, N);
        
        //Step 3: Swap A[K] with A[POS]
        std::swap(arr[i], arr[POS]);
    }
    //Step 4: Exit
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
    //New array of values for sorting
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

    selectionSort(arr, arrSize);

    std::cout << "Sorted array: ";
    printArray(arr, arrSize);

    return 0;
}