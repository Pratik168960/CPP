/*

        LECTURE 19: C++ STL - PRIORITY QUEUE


GOAL:
- Understand and use STL Priority Queue container

KEY CONCEPTS:
- By default, a Priority Queue in C++ is a Max-Heap
- Max-Heap: first element (.top()) is always GREATEST
- Min-Heap: first element (.top()) is always SMALLEST

KEY FUNCTIONS COVERED:
- .push(val): Inserts an element and automatically places it in correct sorted position.
- .pop(): Removes top element (greatest or smallest, depending on heap)
- .top(): Returns top element without removing it
- .empty(): Returns 1 (true) if empty, 0 (false) otherwise
 */

#include <iostream>
#include <queue> // Required for Priority Queue

using namespace std;

int main() {
    cout << "--- 1. MAX-HEAP (DEFAULT PRIORITY QUEUE) ---" << endl;
    
    // Creating a Max-Heap
    priority_queue<int> maxi;

    maxi.push(1);
    maxi.push(3);
    maxi.push(2);
    maxi.push(0);
    
    cout << "Size of Max-Heap: " << maxi.size() << endl;

    // LOOP TRAP FIX: Store size before looping
    int n = maxi.size(); 
    
    cout << "Printing Max-Heap elements (Largest to Smallest): ";
    for (int i = 0; i < n; i++) {
        cout << maxi.top() << " "; // Always prints largest remaining element
        maxi.pop(); // Remove top element so next largest comes up
    }
    cout << endl;


    cout << "\n--- 2. MIN-HEAP ---" << endl;
    
    // Creating a Min-Heap (This is specific syntax required in C++)
    priority_queue<int, vector<int>, greater<int> > mini;

    mini.push(5);
    mini.push(1);
    mini.push(0);
    mini.push(4);
    mini.push(3);

    // Store size before popping
    int m = mini.size();

    cout << "Printing Min-Heap elements (Smallest to Largest): ";
    for (int i = 0; i < m; i++) {
        cout << mini.top() << " "; // Always prints smallest remaining element
        mini.pop(); // Remove it
    }
    cout << endl;

    cout << "\n--- 3. EMPTY CHECK ---" << endl;
    // Both queues should be empty now because we popped everything
    cout << "Is Min-Heap empty? " << mini.empty() << endl; // Returns 1 (true)

    return 0;
}

/*
OUTPUT:
--- 1. MAX-HEAP (DEFAULT PRIORITY QUEUE) ---
Size of Max-Heap: 4
Printing Max-Heap elements (Largest to Smallest): 3 2 1 0 

--- 2. MIN-HEAP ---
Printing Min-Heap elements (Smallest to Largest): 0 1 3 4 5 

--- 3. EMPTY CHECK ---
Is Min-Heap empty? 1
*/