/*

    LECTURE 10: SORT 0 AND 1


GOAL:
- You are given an array consisting of only 0s and 1s
- Sort the array in-place so all 0s are on the left and all 1s are on the right

OPTIMAL APPROACH (Two-Pointer Method):
- Use two pointers: 'left' starting at index 0, and 'right' starting at the last index
- We want to guarantee that everything behind 'left' is a 0, and everything 
past 'right' is a 1
- Loop while left < right:
1. If arr[left] == 0: correct half Move left forward
2. If arr[right] == 1: correct half Move right backward
3. If arr[left] == 1 AND arr[right] == 0: Both are in the wrong halves 
Swap them, then move both pointers inward.
 */

#include <iostream>
using namespace std;

// Reusable function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to sort 0s and 1s using the two-pointer approach
void sortOne(int arr[], int n) {
    int left = 0;
    int right = n - 1;

    // Run until the two pointers meet
    while (left < right) {
        
        // If left element is 0, just move forward
        while (arr[left] == 0 && left < right) {
            left++;
        }
        
        // If right element is 1, just move backward
        while (arr[right] == 1 && left < right) {
            right--;
        }

        // If we reach here, it means arr[left] == 1 and arr[right] == 0
        // Check left < right again before swapping just to be safe
        if (left < right) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
}

int main() {
    int arr[8] = {1, 1, 0, 0, 0, 1, 0, 1};
    int size = 8;

    cout << "Array: ";
    printArray(arr, size);

    sortOne(arr, size);

    cout << "Array: ";
    printArray(arr, size);

    return 0;
}

/*
OUTPUT:
Array: 1 1 0 0 0 1 0 1 
Array: 0 0 0 0 1 1 1 1
*/