/*

        LECTURE 20: REVERSE AN ARRAY (AFTER POSITION M)


GOAL:
- Given an array and a position 'M', reverse subarray that comes AFTER index 'M'

APPROACH (Two-Pointer):
- Normally, to reverse an array, we start at index 0
- Here, we set our 'start' pointer to M + 1 (element right after M)
- We set our 'end' pointer to last element (size - 1)
- We use a while loop (start <= end) to swap elements and 
  move pointers towards middle

TIME COMPLEXITY: O(N) where N is number of elements to reverse.
SPACE COMPLEXITY: O(1) because we are modifying vector in place.
*/


#include <iostream>
#include <vector>
#include <algorithm> // for standard swap()

using namespace std;


// Function to reverse array after a specific index 'M'
void reverseArray(vector<int>& arr, int m) {

    // Start pointing to element immediately after 'm'
    int s = m + 1;
    // End points to last element of vector
    int e = arr.size() - 1;


    // Loop until two pointers meet or cross
    while (s <= e) {
        swap(arr[s], arr[e]); // Swap elements
        s++;                  // Move start forward
        e--;                  // Move end backward
    }
}


// Helper function to print vector
void printVector(const vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}


int main() {
    // Initializing our vector
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(6);

    int m = 3; // We want to reverse everything AFTER index 3

    cout << "Original Array: ";
    printVector(arr);

    // Call our function
    reverseArray(arr, m);

    cout << "--- RESULTS ---" << endl;
    cout << "Array reversed after index " << m << ": ";
    printVector(arr);

    return 0;
}


/*
OUTPUT:
Original Array: 1 2 3 4 5 6 
--- RESULTS ---
Array reversed after index 3: 1 2 3 4 6 5 
*/