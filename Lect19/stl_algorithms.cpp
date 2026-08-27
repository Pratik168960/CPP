/*

        LECTURE 19: C++ STL - ALGORITHMS


GOAL:
- Utilize pre-built STL Algorithms to save time in competitive programming

KEY FUNCTIONS COVERED:
- binary_search(): Returns 1 (true) if found, 0 (false) if not. Container MUST be sorted
- lower_bound() / upper_bound(): Returns an iterator pointing to bounds
- max() / min() / swap(): Basic utility functions for two variables
- reverse(): Reverses strings or containers
- rotate(): Shifts elements in a container by a specified amount
- sort(): Sorts elements. Uses "IntroSort" (a mix of Quick, Heap, and Insertion Sort)
*/


#include <iostream>
#include <algorithm> // Required for all these functions
#include <vector>
#include <string>

using namespace std;

int main() {

    cout << "--- 1. BINARY SEARCH & BOUNDS ---" << endl;
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(6);
    v.push_back(7);


    // Using Binary Search (Vector is already sorted: 1, 3, 6, 7)
    cout << "Finding 6 -> " << binary_search(v.begin(), v.end(), 6) << endl;


    // Finding exactly which index an element is located at using bounds
    cout << "Lower bound of 6 is at index -> " 
         << lower_bound(v.begin(), v.end(), 6) - v.begin() << endl;
    
    cout << "Upper bound of 4 is at index -> " 
         << upper_bound(v.begin(), v.end(), 4) - v.begin() << endl;


    cout << "\n--- 2. MAX, MIN, AND SWAP ---" << endl;
    int a = 3, b = 5;
    cout << "Max of 3 and 5: " << max(a, b) << endl;
    cout << "Min of 3 and 5: " << min(a, b) << endl;

    swap(a, b);
    cout << "After swapping, 'a' is: " << a << endl;


    cout << "\n--- 3. REVERSING A STRING ---" << endl;
    string s = "abcd";
    reverse(s.begin(), s.end());
    cout << "String after reverse: " << s << endl;

    
    cout << "\n--- 4. ROTATING A VECTOR ---" << endl;
    cout << "Original Vector: 1 3 6 7" << endl;
    
    // Rotate vector such that element at index 1 becomes new start
    rotate(v.begin(), v.begin() + 1, v.end());
    
    cout << "Vector after rotate: ";
    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;

    cout << "\n--- 5. SORTING ---" << endl;
    // vector is currently 3 6 7 1 due to rotate. Let's sort it back!
    sort(v.begin(), v.end());
    
    cout << "Vector after sort (using IntroSort): ";
    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

/*
EXPECTED CONSOLE OUTPUT:
--- 1. BINARY SEARCH & BOUNDS ---
Finding 6 -> 1
Lower bound of 6 is at index -> 2
Upper bound of 4 is at index -> 2

--- 2. MAX, MIN, AND SWAP ---
Max of 3 and 5: 5
Min of 3 and 5: 3
After swapping, 'a' is: 5

--- 3. REVERSING A STRING ---
String after reverse: dcba

--- 4. ROTATING A VECTOR ---
Original Vector: 1 3 6 7
Vector after rotate: 3 6 7 1 

--- 5. SORTING ---
Vector after sort (using IntroSort): 1 3 6 7 
*/