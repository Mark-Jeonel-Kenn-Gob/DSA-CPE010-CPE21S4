#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[middle + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}

int main() {
    vector<int> arr = {94, 78, 25, 46, 83, 33, 48, 17, 29, 88, 56, 5, 96, 21, 65, 
                 57, 96, 87, 73, 50, 8, 15, 58, 9, 67, 84, 52, 44, 15, 
                 7, 9, 62, 85, 35, 8, 68, 20, 8, 86, 1, 97, 42, 7, 
                 45, 64, 72, 2, 12, 11, 27, 15, 20, 42, 73, 81, 61, 
                 9, 33, 57, 24, 40, 66, 86, 26, 53, 46, 94, 25, 55, 
                 32, 27, 52, 27, 34, 97, 43, 6, 51, 55, 17, 30, 22, 
                 89, 24, 95, 22, 37, 4, 55, 94, 81, 48, 60, 67, 26, 
                 66, 66, 20, 91, 21};

    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl << endl;

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}