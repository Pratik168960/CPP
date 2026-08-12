/*

    LECTURE 10: SWAP ALTERNATE ELEMENTS IN AN ARRAY


GOAL:
- Given an array, swap every two adjacent elements.
- Example (Even size): [1, 2, 3, 4, 5, 6] -> [2, 1, 4, 3, 6, 5]
- Example (Odd size):  [1, 2, 7, 8, 5]    -> [2, 1, 8, 7, 5]

HOW IT WORKS:
- We loop through array starting at index 0 

- Instead of incrementing by 1 (i++), we increment by 2 (i += 2) because 
we have swapped the two elements and we do not need to swap those with any other  

- Before swapping, we MUST check if the adjacent element (i + 1) actually 
exists within the array bounds (i + 1 < size) to prevent memory errors
*/


#include <iostream>
using namespace std;


// Function to print  array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}



// Function to swap alternate elements
void swapAlternate(int arr[], int size) {
    for (int i = 0; i < size; i += 2) {
        
        // Check if the next element exists before swapping
        if (i + 1 < size) {
            // Built-in C++ function to swap two values
            swap(arr[i], arr[i + 1]);
        }
    }
}



int main() {
    // Test Case 1: EVEN number of elements
    int even[8] = {5, 2, 9, 4, 7, 6, 1, 0};
    
    // Test Case 2: ODD number of elements
    int odd[5] = {11, 33, 9, 76, 43};

    // Call the function to swap elements
    swapAlternate(even, 8);
    swapAlternate(odd, 5);
    
    cout << "Even Array: ";
    printArray(even, 8);
    cout << "Odd Array:  ";
    printArray(odd, 5);

    return 0;
}

/*
OUTPUT:
Even Array: 2 5 4 9 6 7 0 1 
Odd Array:  33 11 76 9 43  
*/