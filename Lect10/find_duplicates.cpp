/*

    LECTURE 10: FIND DUPLICATE IN AN ARRAY


GOAL:
- You are given an array of size N containing integers from 1 to N-1 every integer atleast once 
- There is exactly ONE duplicate number in the array
- Find and return that duplicate number
- Example: [4, 2, 1, 3, 1] (Size N=5, elements from 1 to 4)-> Duplicate is 1

THE OPTIMAL APPROACH (Using XOR):
- We know a ^ a = 0 (XORing identical numbers cancels them out)
- Step 1: XOR all elements in the given array together
- Step 2: XOR that result with all numbers from 1 to N-1
- The numbers from 1 to N-1 will cancel out with the unique elements in the array
- The only number left standing will be the duplicate
*/

#include <iostream>
#include <vector>
using namespace std;

// Function to find the duplicate element
int findDuplicate(vector<int>& arr) {
    int ans = 0;
    
    // Step 1: XOR all elements of array
    for (int i = 0; i < arr.size(); i++) {
        ans = ans ^ arr[i];
    }
    
    // Step 2: XOR [1, n-1]
    for (int i = 1; i < arr.size(); i++) {
        ans = ans ^ i;
    }
    
    return ans;
}

int main() {
    vector<int> arr = {4, 2, 1, 3, 1};
    
    cout << "Array elements: ";
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    int duplicateElement = findDuplicate(arr);
    
    cout << "Duplicate element: " << duplicateElement << endl;

    return 0;
}

/*
OUTPUT:
Array elements: 4 2 1 3 1 
Duplicate element: 1
*/