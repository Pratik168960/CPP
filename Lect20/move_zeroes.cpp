/*

        LECTURE 20: MOVE ZEROES (LEETCODE 283)


GOAL:
- Shift all zeros in an array to right end
- Preserve relative order of all non-zero elements

APPROACH (Two-Pointer):
- Instead of worrying about moving zeros, focus on shifting non-zero elements to left
- Maintain a 'nonZero' pointer that tracks index where next non-zero element belongs (starting at index 0)
- Traverse array with a loop pointer 'j'
- If arr[j] is NOT zero, swap it with arr[nonZero], then increment 'nonZero'
- If arr[j] IS zero, simply ignore it and let 'j' move forward

COMPLEXITY:
- Time Complexity: O(N) because we traverse array exactly once.
- Space Complexity: O(1) as swaps are done in-place.
*/


#include <iostream>
#include <vector>
#include <algorithm> // for standard swap()

using namespace std;

// Function to move all zeros to right
void moveZeroes(vector<int>& nums) {
    int nonZero = 0; // Tracks index for next non-zero element
    
    for (int j = 0; j < nums.size(); j++) {
        // If we find a non-zero element, swap it to left
        if (nums[j] != 0) {
            swap(nums[j], nums[nonZero]);
            nonZero++;
        }
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

    vector<int> arr = {0, 1, 0, 3, 12};
    
    cout << "Original Array: ";
    printVector(arr);

    // Call function
    moveZeroes(arr);

    cout << "Array after moving zeroes: ";
    printVector(arr);

    return 0;
}


/*
OUTPUT:
Original Array: 0 1 0 3 12 
Array after moving zeroes: 1 3 12 0 0 
*/