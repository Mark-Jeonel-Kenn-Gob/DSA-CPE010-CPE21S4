#include <iostream>
#include <vector>

using namespace std;

void shellSort(vector<int>& arr) {
	int n = arr.size();
	int gap = n / 2;

	while (gap > 0) {
		for (int i = gap; i < n; i++) {
			int temp = arr[i];
			int j = i;
			while (j >= gap && arr[j - gap] > temp) {
				arr[j] = arr[j - gap];
				j -= gap;
			}
			arr[j] = temp;
		}
		gap /= 2;
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

	shellSort(arr);

	cout << "Sorted array: ";
	for (int num : arr) {
		cout << num << " ";
	}
	cout << endl;

	return 0;
}