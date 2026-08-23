/*

        LECTURE 17: BUBBLE SORT


GOAL:
- Sort an array in ascending order using Bubble Sort

APPROACH:
- algorithm works in N - 1 rounds (or passes)
- In every round, we compare adjacent elements If arr[j] > arr[j+1], 
  we swap them
- By end of round 'i', 'i'-th largest element is placed 
  in its correct rightmost position

OPTIMIZATION:
- If no two elements were swapped in a specific round, it means 
  array is already sorted We can break out early to save time

COMPLEXITY:
- Time Complexity:
  - Worst/Average Case: O(N^2) (Array is reverse sorted)
  - Best Case: O(N) (Array is already sorted, handled via optimization)
- Space Complexity: O(1) (In-place sorting)
*/


#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& arr, int n) {
    // For N elements, we need N-1 rounds
    for (int i = 1; i < n; i++) {
        
        bool swapped = false;

        // Process elements till n-i because last 'i' elements 
        // are already in their correct sorted positions
        for (int j = 0; j < n - i; j++) {
            
            // Compare adjacent elements
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true; // Mark that a swap occurred
            }
        }

        // OPTIMIZATION: If nothing was swapped, array is already sorted
        if (swapped == false) {
            break; // Break out of loop early
        }
    }
}

// Reusable function to print array
void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {

    vector<int> arr = {10, 1, 7, 6, 14, 9};
    int n = arr.size();

    cout << "Original Array: ";
    printArray(arr);

    bubbleSort(arr, n);

    cout << "Sorted Array: ";
    printArray(arr);

    return 0;
}

/*
OUTPUT:
Original Array: 10 1 7 6 14 9 
Sorted Array: 1 6 7 9 10 14 
*/