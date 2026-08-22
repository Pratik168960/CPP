/*

        LECTURE 16: SELECTION SORT


GOAL:
- Sort an array in ascending order using Selection Sort

APPROACH:
- algorithm works in multiple rounds (or passes)
- For an array of size N, it takes N - 1 rounds to completely sort it
- In each round 'i', we find SMALLEST element in unsorted part 
  of array (from index i to N-1)
- Once we find minimum element, we swap it with element at index 'i'

COMPLEXITY:
- Time Complexity: O(N^2) in all cases (Best, Worst, and Average) because 
  it always scans remaining array to find minimum value
- Space Complexity: O(1) as it sorts array in-place without extra memory
 */

#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& arr, int n) {
    // Loop for rounds: 0 to n-2 (which means n-1 rounds total)
    for (int i = 0; i < n - 1; i++) {
        
        // Assume current position 'i' holds the minimum value
        int minIndex = i;

        // Scan the rest of the array to find if there is a smaller element
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j; // Update minIndex if a smaller element is found
            }
        }

        // Swap the minimum element found with the element at position 'i'
        swap(arr[minIndex], arr[i]);
    }
}

// Reusable function to print the array
void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {

    vector<int> arr = {64, 25, 12, 22, 11};
    int n = arr.size();

    cout << "Original Array: ";
    printArray(arr);

    selectionSort(arr, n);

    cout << "Sorted Array: ";
    printArray(arr);

    return 0;
}

/*
OUTPUT:
Original Array: 64 25 12 22 11 
Sorted Array: 11 12 22 25 64 
*/