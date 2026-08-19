/*

        LECTURE 14: FIND PIVOT IN AN ARRAY


GOAL:
- Find the pivot element's index in a sorted and rotated array
- In this context, the "pivot" is the minimum element in the array
- Example: [7, 9, 1, 2, 3] -> The array was originally [1, 2, 3, 7, 9] 
but was rotated. The pivot is 1 (at index 2).


APPROACH (Binary Search):
- A rotated sorted array consists of two monotonically increasing lines
- We can use Binary Search (O(log N)) to find the break point (minimum element)
- Condition 1: If arr[mid] >= arr[0]
This means 'mid' is lying on the first line (the upper, larger numbers).
Therefore, the pivot must be to the right. Move start = mid + 1
- Condition 2: If arr[mid] < arr[0]
This means 'mid' is lying on the second line (the lower, smaller numbers)
Therefore, the pivot is either at 'mid' or to its left. Move end = mid
- We loop while (start < end). When they converge, we found our pivot
*/

#include <iostream>
using namespace std;

int getPivot(int arr[], int n) {
    int start = 0;
    int end = n - 1;

    // We use start < end to avoid infinite loops when they converge
    while (start < end) {
        int mid = start + (end - start) / 2;

        // Check if mid is on the first line
        if (arr[mid] >= arr[0]) {
            start = mid + 1; // Pivot must be to the right
        } 
        // Otherwise, mid is on the second line
        else {
            end = mid; // Pivot is here or to the left
        }
    }

    // start and end will point to the same pivot index
    return start;
}

int main() {
    int arr[5] = {7, 9, 1, 2, 3};
    int size = 5;

    cout << "Array Elements: 7 9 1 2 3" << endl;

    int pivotIndex = getPivot(arr, size);
    cout << "The pivot element is at index: " << pivotIndex << endl;
    cout << "The pivot element value is: " << arr[pivotIndex] << endl;

    return 0;
}

/*
OUTPUT:
Array Elements: 7 9 1 2 3
The pivot element is at index: 2
The pivot element value is: 1
*/