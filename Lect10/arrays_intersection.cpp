/*

    LECTURE 10: INTERSECTION OF TWO SORTED ARRAYS


GOAL:
- given two arrays sorted in non-decreasing order
- Find their intersection (elements that are present in BOTH arrays)
- Return the result as a new array


OPTIMAL APPROACH (Two-Pointer Method):
- Since arrays are SORTED, we can use two pointers i for arr1 and j for arr2.
- We compare arr1[i] and arr2[j]:
1. If they are EQUAL: We found an intersection! Add it to our answer, 
and move both pointers (i++, j++)
2. If arr1[i] < arr2[j]: to find a match for arr2[j] is to look at larger numbers in arr1. 
So, we move 'i' forward (i++)
3. If arr1[i] > arr2[j]: Similarly, we need a larger number in arr2 to 
match arr1[i], so we move 'j' forward (j++)
- This approach is highly efficient, running in O(N+M) time complexity.
 */

#include <iostream>
#include <vector>
using namespace std;

vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m) {

    /*

    APPROACH 1: BRUTE FORCE (Nested Loops)
    Time Complexity: O(N * M) - Very slow for large arrays.

    How it works:
    - Pick the first element from arr1.
    - Scan through all of arr2 to find a match.
    - IMPORTANT: If a match is found, we must "mark" the element in arr2
    so it doesn't get matched again by a duplicate number in arr1.
    We do this by updating arr2[j] to a value outside the valid range (like -1).
    Code:
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        int element = arr1[i];
        for (int j = 0; j < m; j++) {
            if(element < arr2[j]){
                break;
            }
            if (element == arr2[j]) {
                ans.push_back(element);
                arr2[j] = -1; // Mark as visited so it isn't reused
                break;        // Stop searching arr2 for this specific element
            }
        }
    }
    return ans;
    But this will get error for big arrays TIME LIMIT EXCEED
    */

    // 
    // APPROACH 2: OPTIMAL TWO-POINTER
    // Time Complexity: O(N + M) 
    // 
    int i = 0, j = 0;
    vector<int> ans;
    
    // Loop runs until one of the arrays is completely traversed
    while (i < n && j < m) {
        
        if (arr1[i] == arr2[j]) {
            // Match found
            ans.push_back(arr1[i]);
            i++;
            j++;
        } 
        else if (arr1[i] < arr2[j]) {
            // arr1 element is smaller, move i forward to find a larger element
            i++;
        } 
        else {
            // arr2 element is smaller, move j forward to find a larger element
            j++;
        }
    }
    
    return ans;
}

int main() {
    vector<int> arr1 = {1, 2, 2, 2, 3, 4};
    vector<int> arr2 = {2, 2, 3, 3};
    
    cout << "Array 1: ";
    for (int i = 0; i < arr1.size(); i++) cout << arr1[i] << " ";
    cout << endl;
    
    cout << "Array 2: ";
    for (int i = 0; i < arr2.size(); i++) cout << arr2[i] << " ";
    cout << endl;

    vector<int> intersection = findArrayIntersection(arr1, arr1.size(), arr2, arr2.size());
        cout << "Intersection: ";
    if (intersection.empty()) {
        cout << "No common elements.";
    } else {
        for (int i = 0; i < intersection.size(); i++) {
            cout << intersection[i] << " ";
        }
    }
    cout << endl;

    return 0;
}

/*
OUTPUT:
Array 1: 1 2 2 2 3 4 
Array 2: 2 2 3 3 
Intersection: 2 2 3  
*/