/*

        LECTURE 20: MERGE TWO SORTED ARRAYS


GOAL:
- Take two arrays that are already sorted (arr1 and arr2).
- Merge them into a brand-new third array (arr3) so that 
  final array remains perfectly sorted.

APPROACH (Two-Pointer):
- We initialize three pointers: 'i' for arr1, 'j' for arr2, 
  and 'k' for arr3 (all starting at index 0).
- We run a main while loop (i < n && j < m) to compare elements.
- If arr1[i] < arr2[j], we copy arr1[i] into arr3[k] and increment i and k.
- Otherwise, we copy arr2[j] into arr3[k] and increment j and k.
- Once main loop finishes, one array might still have leftover elements.
- We use two extra while loops to copy any remaining elements from 
  either arr1 or arr2 directly into arr3.

COMPLEXITY:
- Time Complexity: O(N + M) because we traverse both arrays exactly once.
- Space Complexity: O(N + M) because we are storing result in a third array.
*/


#include <iostream>
#include <vector>

using namespace std;

// Function to merge two sorted arrays into a third array
void mergeArrays(int arr1[], int n, int arr2[], int m, int arr3[]) {
    int i = 0; // Pointer for arr1
    int j = 0; // Pointer for arr2
    int k = 0; // Pointer for arr3

    // Step 1: Compare elements and merge until one array is empty
    while (i < n && j < m) {
        if (arr1[i] < arr2[j]) {
            arr3[k++] = arr1[i++];
        } else {
            arr3[k++] = arr2[j++];
        }
    }

    // Step 2: Copy any remaining elements from arr1 (if any)
    while (i < n) {
        arr3[k++] = arr1[i++];
    }

    // Step 3: Copy any remaining elements from arr2 (if any)
    while (j < m) {
        arr3[k++] = arr2[j++];
    }
}

// Helper function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Two pre-sorted arrays
    int arr1[5] = {1, 3, 5, 7, 9};
    int arr2[3] = {2, 4, 6};
    
    // third array to hold merged results, initialized to zeros
    int arr3[8] = {0}; 

    cout << "Array 1: ";
    printArray(arr1, 5);
    
    cout << "Array 2: ";
    printArray(arr2, 3);

    // Call merge function
    mergeArrays(arr1, 5, arr2, 3, arr3);
    cout << "Merged Array: ";
    printArray(arr3, 8);

    return 0;
}


/*
OUTPUT:
Array 1: 1 3 5 7 9 
Array 2: 2 4 6 
Merged Array: 1 2 3 4 5 6 7 9 
*/