/*
    LECTURE 9: REVERSE AN ARRAY

GOAL:
- Reverse elements of an array in-place (without creating a new array)

TWO-POINTER APPROACH:
- We use two variables: 'start' (pointing 0th index) and 
'end' (pointing last index, which is size - 1)

- swap elements at 'start' and 'end' positions.

- then, we move 'start' forward (start++) and 'end' backward (end--).

- repeat this loop until 'start' crosses 'end' (start <= end).
*/


#include <iostream>
using namespace std;



// Function to reverse array
void reverse(int arr[], int n) {
    int start = 0;
    int end = n - 1;
    
    // Loop until two pointers meet in middle
    while (start <= end) {

        // Built-in C++ swap function exchanges values
        swap(arr[start], arr[end]);
        
        // Move pointers inward
        start++;
        end--;
    }
}



// function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}



int main() {
    // Test Case 1: Array with an EVEN number of elements
    int arr[6] = {1, 4, 0, 5, -2, 15}; 
    
    // Test Case 2: Array with an ODD number of elements
    int brr[5] = {2, 6, 3, 9, 4};      
    

    // Reverse both arrays
    reverse(arr, 6);
    reverse(brr, 5);
    

    
    cout << "Reversed Even Array: ";
    printArray(arr, 6);
    
    cout << "Reversed Odd Array:  ";
    printArray(brr, 5);
    


    return 0;
}


/*
OUTPUT:
Reversed Even Array: 15 -2 5 0 4 1 
Reversed Odd Array:  4 9 3 6 2 
*/