/*

        LECTURE 21: ADD TWO ARRAYS REPRESENTED AS NUMBERS


GOAL:
- Given two arrays representing large integers, add them together
- Return sum as a new array

APPROACH (Primary School Math):
- Start from end of both arrays (right to left)
- Add corresponding digits along with any carry
- Store (sum % 10) in answer array and update carry = (sum / 10)
- Handle cases where one array is longer than other
- Handle case where a carry is left over at very end
- Reverse answer array before returning it

COMPLEXITY:
- Time Complexity: O(max(N, M)) where N and M are array sizes
- Space Complexity: O(max(N, M)) to store final answer
 */

#include <iostream>
#include <vector>
#include <algorithm> // for reverse()

using namespace std;

// Function to add two arrays
vector<int> findArraySum(vector<int>& a, int n, vector<int>& b, int m) {
    
    int i = n - 1;
    int j = m - 1;

    vector<int> ans;
    int carry = 0;

    // Case 1: Both arrays have digits left to add
    while (i >= 0 && j >= 0) {

        int val1 = a[i];
        int val2 = b[j];

        int sum = val1 + val2 + carry;
        carry = sum / 10;
        ans.push_back(sum % 10);
        
        i--;
        j--;
    }

    // Case 2: Array 'a' is longer and still has digits left
    while (i >= 0) {

        int sum = a[i] + carry;
        carry = sum / 10;
        ans.push_back(sum % 10);
        i--;
    }


    // Case 3: Array 'b' is longer and still has digits left
    while (j >= 0) {
        int sum = b[j] + carry;
        carry = sum / 10;
        ans.push_back(sum % 10);
        j--;
    }


    // Case 4: A final carry is left over
    while (carry != 0) {
        int sum = carry;
        carry = sum / 10;
        ans.push_back(sum % 10);
    }


    // Since we appended digits from right to left, reverse result
    reverse(ans.begin(), ans.end());
    
    return ans;
}

// Helper function to print vector
void printVector(const vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    // Representing number 123
    vector<int> arr1 = {1, 2, 3};
    // Representing number 99
    vector<int> arr2 = {9, 9};

    cout << "Array 1: ";
    printVector(arr1);
    
    cout << "Array 2: ";
    printVector(arr2);

    // Call addition function
    vector<int> result = findArraySum(arr1, arr1.size(), arr2, arr2.size());

    cout << "Sum Array: ";
    printVector(result);

    return 0;
}

/*
OUTPUT:
Array 1: 1 2 3 
Array 2: 9 9 
Sum Array: 2 2 2 
*/