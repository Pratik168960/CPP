/*

        LECTURE 18: INSERTION SORT


GOAL:
- Sort an array in ascending order using Insertion Sort

APPROACH (Card Example):
- Imagine sorting playing cards in your hands 
- You pick one card at a time and place it in its correct 
  position relative to cards you are already holding
- We start from i = 1 (assuming first element at index 0 is sorted).
- We store arr[i] in a 'temp' variable
- We compare 'temp' with elements to its left (j = i - 1 down to 0).
- If left element is greater than 'temp', we shift it one position 
  to right (arr[j+1] = arr[j]) to make room
- If it is smaller, or we reach beginning of array, we place 
  'temp' in vacant spot (arr[j+1] = temp)

COMPLEXITY:
- Time Complexity:
  - Best Case: O(N) (Array is already sorted)
  - Worst Case: O(N^2) (Array is reverse sorted)
- Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& arr, int n) {
    // Start from 1 because 0th element is assumed to be sorted
    for (int i = 1; i < n; i++) {
        int temp = arr[i]; // Pick up current card
        int j = i - 1;
        
        // Compare with elements to left
        for (; j >= 0; j--) {
            if (arr[j] > temp) {
                // Shift larger element one position to right
                arr[j + 1] = arr[j]; 
            } else {
                // Stop shifting when we find a smaller element
                break;
            }
        }
        
        // Place picked up card in its correct position
        arr[j + 1] = temp;
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

    vector<int> arr = {10, 1, 7, 4, 8, 2, 11};
    int n = arr.size();

    cout << "Original Array: ";
    printArray(arr);

    insertionSort(arr, n);

    cout << "Sorted Array: ";
    printArray(arr);

    return 0;
}

/*
OUTPUT:
Original Array: 10 1 7 4 8 2 11 
Sorted Array: 1 2 4 7 8 10 11 
*/