/*

        LECTURE 11: TIME AND SPACE COMPLEXITY


WHAT IS TIME COMPLEXITY?
- It is not the actual execution time in seconds.
- It is a mathematical function that describes how the number of operations 
grows as the input size (N) increases.
- We use Big-O Notation to represent the worst-case scenario.

WHAT IS SPACE COMPLEXITY?
- The amount of extra memory an algorithm takes to execute as a function of 
the input size (N).

HOW TO AVOID TLE (Time Limit Exceeded):
- Most modern online judges (LeetCode, CodeStudio) allow ~10^8 operations per second.
- If N = 10^5, an O(N) solution takes 10^5 ops (Passes instantly).
- If N = 10^5, an O(N^2) solution takes 10^10 ops (Takes ~100s -> TLE!).
* COMMON BIG-O COMPLEXITIES (From Best to Worst):
1. O(1)         - Constant Time
2. O(log N)  - Logarithmic Time (Binary Search)
3. O(N)       - Linear Time (Single Loop)
4. O(N log N)- Linearithmic Time (Merge/Quick Sort)
5. O(N^2)    - Quadratic Time (Nested Loops)
6. O(2^N)    - Exponential Time (Recursion/Subsets)
7. O(N!)     - Factorial Time (Permutations)
 */

#include <iostream>
using namespace std;

// 1. CONSTANT TIME: O(1)
// Doesn't matter if the array has 10 elements or 10 million, it takes 1 step.
int getFirstElement(int arr[]) {
    return arr[0]; 
}

// 2. LINEAR TIME: O(N)
// The loop runs exactly 'N' times. If N doubles, the time doubles.
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// 3. QUADRATIC TIME: O(N^2)
// For every 1 element in the outer loop, the inner loop runs N times.
// Used in Brute Force solutions (like finding pairs).
void printPairs(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i] << "," << arr[j] << " ";
        }
        cout << endl; 
    }
}

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int n = 5;


    cout << "1. O(1) Constant Time Example:" << endl;
    cout << "First Element is: " << getFirstElement(arr) << endl << endl;

    cout << "2. O(N) Linear Time Example:" << endl;
    cout << "Printing Array: ";
    printArray(arr, n);
    cout << endl;

    cout << "3. O(N^2) Quadratic Time Example:" << endl;
    cout << "Printing All Possible Pairs:" << endl;
    printPairs(arr, n);

    return 0;
}

/*
OUTPUT:
1. O(1) Constant Time Example:
First Element is: 10

2. O(N) Linear Time Example:
Printing Array: 10 20 30 40 50 

3. O(N^2) Quadratic Time Example:
Printing All Possible Pairs:
10,10 10,20 10,30 10,40 10,50 
20,10 20,20 20,30 20,40 20,50 
30,10 30,20 30,30 30,40 30,50 
40,10 40,20 40,30 40,40 40,50 
50,10 50,20 50,30 50,40 50,50 

*/