/*

        LECTURE 12: BINARY SEARCH


GOAL:
- Find the index of a specific element (the 'key') in a SORTED array. 
The Golden Rule: Binary Search ONLY works on arrays that are sorted 
(monotonic—either strictly increasing or strictly decreasing)


TIME COMPLEXITY:
- O(log N): Because we divide the search space in half during every step
- This is significantly faster than Linear Search O(N)


THE APPROACH:
- We use two pointers: 'start' (index 0) and 'end' (index size - 1)
- Loop while start <= end:
1. Calculate 'mid'
* OPTIMIZATION: Use `start + (end - start) / 2` instead of 
`(start + end) / 2` to prevent integer overflow for huge arrays
2. If arr[mid] == key: Return mid (We found it)
3. If arr[mid] < key: The key is larger, so it must be in the right half
Move start = mid + 1
4. If arr[mid] > key: The key is smaller, so it must be in the left half
Move end = mid - 1
- If the loop finishes and we haven't returned, the key is not in the array. Return -1
*/



#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key) {
    int start = 0;
    int end = size - 1;

    // Run until the search space is exhausted
    while (start <= end) {
        
        // Optimized mid calculation to avoid integer overflow
        int mid = start + (end - start) / 2;

        if (arr[mid] == key) {
            return mid; // Key found
        }

        // Go to right part
        if (key > arr[mid]) {
            start = mid + 1;
        } 
        // Go to left part
        else {
            end = mid - 1;
        }
    }

    return -1; // Key not found
}

int main() {
    // Binary Search REQUIRES the arrays to be sorted
    int evenArray[6] = {2, 4, 6, 8, 12, 18};
    int oddArray[5] = {3, 8, 11, 14, 16};

    int evenIndex = binarySearch(evenArray, 6, 12);
    cout << "Index of 12 in Even Array is: " << evenIndex << endl;

    int oddIndex = binarySearch(oddArray, 5, 14);
    cout << "Index of 14 in Odd Array is: " << oddIndex << endl;
    
    int notFoundIndex = binarySearch(evenArray, 6, 100);
    cout << "Index of 100 in Even Array is: " << notFoundIndex << endl;

    return 0;
}

/*
OUTPUT:
Index of 12 in Even Array is: 4
Index of 14 in Odd Array is: 3
Index of 100 in Even Array is: -1
*/