/*

        LECTURE 14: SEARCH IN A ROTATED SORTED ARRAY


GOAL:
- Find the index of a target element in a sorted but rotated array.
- Do this in O(log N) time.
- Example: arr = [7, 9, 1, 2, 3], target = 2 -> Returns index 3.


APPROACH (3-Step Process):
1. Find the Pivot: Find the index of the minimum element (separates the two lines).
2. Identify the Search Space: 
- If target is between arr[pivot] and arr[n-1], search the SECOND line.
- Else, search the FIRST line (from index 0 to pivot-1).
3. Binary Search: Run a standard binary search on the chosen line.
 */

#include <iostream>
using namespace std;

// Step 1: Helper function to find the pivot (minimum element)
int getPivot(int arr[], int n) {
    int start = 0;
    int end = n - 1;

    while (start < end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] >= arr[0]) {
            start = mid + 1;
        } else {
            end = mid;
        }
    }
    return start;
}

// Step 2: Standard Binary Search helper function
int binarySearch(int arr[], int start, int end, int key) {
    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == key) {
            return mid;
        }
        if (key > arr[mid]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return -1;
}

// Step 3: Main function to put it all together
int findPosition(int arr[], int n, int k) {
    int pivot = getPivot(arr, n);

    // Check if target lies on the second line
    if (k >= arr[pivot] && k <= arr[n - 1]) {
        // Search the second line
        return binarySearch(arr, pivot, n - 1, k);
    } 
    else {
        // Search the first line
        return binarySearch(arr, 0, pivot - 1, k);
    }
}

int main() {
    int arr[5] = {7, 9, 1, 2, 3};
    int size = 5;
    int target = 2;


    cout << "Array Elements: 7 9 1 2 3" << endl;
    cout << "Target Element: " << target << endl << endl;


    int resultIndex = findPosition(arr, size, target);

    if (resultIndex != -1) {
        cout << "Target " << target << " found at index: " << resultIndex << endl;
    } else {
        cout << "Target " << target << " not found in the array." << endl;
    }

    return 0;
}

/*
OUTPUT:
Array Elements: 7 9 1 2 3
Target Element: 2

Target 2 found at index: 3
*/