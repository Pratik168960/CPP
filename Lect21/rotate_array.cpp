/*

        LECTURE 21: ROTATE ARRAY (LEETCODE 189)


GOAL:
- Shift every element in array to right by K steps.
- Elements that fall off right edge must wrap around to left

APPROACH (Modulo Operator):
- We cannot simply do 'i + k' because it will cause an out-of-bounds error
- formula (i + k) % n perfectly calculates new wrapped index
- We create a 'temp' vector of same size to hold shifted values
- We place nums[i] into temp[(i + k) % n]
- Finally, we copy all elements from 'temp' back into 'nums'

COMPLEXITY:
- Time Complexity: O(N) because we traverse array exactly once.
- Space Complexity: O(N) because we create a 'temp' vector of size N.
*/

#include <iostream>
#include <vector>

using namespace std;

// Function to rotate array by K steps
void rotateArray(vector<int>& nums, int k) {
    int n = nums.size();
    
    // Create a temporary vector of same size, initialized to 0
    vector<int> temp(n);

    // Place each element in its new rotated position
    for (int i = 0; i < n; i++) {
        temp[(i + k) % n] = nums[i];
    }

    // Copy rotated elements back into original array
    nums = temp;
}

// Helper function to print vector
void printVector(const vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int k = 3; // We want to rotate by 3 steps

    cout << "Original Array: ";
    printVector(arr);

    // Call rotation function
    rotateArray(arr, k);

    cout << "Array after rotating by " << k << " steps: ";
    printVector(arr);

    return 0;
}

/*
OUTPUT:
Original Array: 1 2 3 4 5 6 7 
Array after rotating by 3 steps: 5 6 7 1 2 3 4 
*/