#ifndef SORTINGALGORITHMS_H
#define SORTINGALGORITHMS_H

#include <vector>

//Function prototypes for sorting algorithms
void bubbleSort(std::vector<int>& arr);
void selectionSort(std::vector<int>& arr);
void quickSort(std::vector<int>& arr, int low, int high);

//Helper function for quickSort
int partition(std::vector<int>& arr, int low, int high);

#endif