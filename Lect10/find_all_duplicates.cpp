/*

    LECTURE 10: FIND ALL DUPLICATES IN AN ARRAY (LeetCode 442)


GOAL:
- Given an array of size N where all elements are in the range [1, N]
- Some elements appear twice, others appear once
- Find and return ALL elements that appear twice
- Constraint: Do it in O(N) time and O(1) extra space

OPTIMAL APPROACH (In-Place Marking):
- Since all numbers are between 1 and N, we can use the numbers themselves 
as array indices (Number X corresponds to index X - 1)

- As we iterate, we treat the absolute value of the current element as an index

- We check the number at that index:
1. If it is POSITIVE, we make it NEGATIVE to "mark" that we've seen it.
2. If it is ALREADY NEGATIVE, it means we've marked it before, so 
the current number must be a duplicate
*/

#include <iostream>
#include <vector>
#include <cmath> // Required for abs() function
using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
    vector<int> duplicates;
    
    for (int i = 0; i < nums.size(); i++) {
        
        // index for current number points to
        // abs() because number might have been made negative already
        int index = abs(nums[i]) - 1;
        
        // nums[index] negative means we found duplicate
        if (nums[index] < 0) {
            duplicates.push_back(abs(nums[i]));
        } 
        // Otherwise, marking as visited by making it negative
        else {
            nums[index] = -nums[index];
        }
    }
    
    return duplicates;
}

int main() {

    vector<int> arr = {4, 3, 2, 7, 8, 2, 3, 1};
    
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    vector<int> result = findDuplicates(arr);
    
    cout << "The duplicate elements are: ";
    if (result.empty()) {
        cout << "None";
    } else {
        for(int i = 0; i < result.size(); i++){
            cout << result[i] << " ";
        }
    }
    cout << endl;

    return 0;
}

/*
OUTPUT:
4 3 2 7 8 2 3 1 
The duplicate elements are: 2 3 
*/