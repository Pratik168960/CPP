/*

        LECTURE 23: 2D ARRAYS INTRO & LINEAR SEARCH


GOAL:
- Understand how to declare, initialize, and traverse a 2D array.
- Implement a Linear Search to find a specific target element.

APPROACH (Nested Loops):
- Use an outer loop 'i' for traversing rows and an inner loop 'j' 
  for traversing columns.
- Compare each element arr[i][j] with target value.
- If a match is found, return true (1). If loops finish without 
  a match, return false (0).

COMPLEXITY:
- Time Complexity: O(R * C) where R is number of rows and C is columns.
- Space Complexity: O(1) auxiliary space.
 */

#include <iostream>
using namespace std;

// Function to perform linear search in a 2D array
bool isPresent(int arr[][4], int target, int rows, int cols) {
    /*
    C++ requires the number of columns because it physically stores 2D arrays in memory 
    as a single, flat 1D array.Memory is strictly linear. When you create a 3x4 matrix, 
    C++ places all 12 elements side-by-side in a continuous block. 
    To retrieve a specific element like arr[i][j], the compiler must translate your 2D coordinates 
    into a 1D memory index using this exact formula:
    Index = (i * C) + j
    (where i is the target row, j is the target column, and C is the total number of counts)
    */
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] == target) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    // Create a 2D array with 3 rows and 4 columns
    int arr[3][4];

    cout << "Enter elements for a 3x4 matrix (12 numbers total):" << endl;
    
    // Taking input row-wise
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> arr[i][j];
        }
    }

    // Printing matrix
    cout << "\nYour Matrix:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
    int target;
    cout << "\nEnter element to search: ";
    cin >> target;


    if (isPresent(arr, target, 3, 4)) {
        cout << "Element " << target << " is FOUND in matrix!" << endl;
    } else {
        cout << "Element " << target << " is NOT FOUND." << endl;
    }

    return 0;
}

/*
OUTPUT:
Enter elements for a 3x4 matrix (12 numbers total):
1 2 3 4 
5 6 7 8 
9 10 11 12

Your Matrix:
1 2 3 4 
5 6 7 8 
9 10 11 12 

Enter element to search: 7
Element 7 is FOUND in matrix!
*/