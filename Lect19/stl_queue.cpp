/*

        LECTURE 19: C++ STL - QUEUE


GOAL:
- Understand and use STL Queue container

KEY CONCEPTS:
- A Queue operates on First-In-First-Out (FIFO) principle
- Think of it like a line at a ticket counter: first person to enter line is first person to leave it

KEY FUNCTIONS COVERED:
- .push(val): Adds an element to back of queue
- .pop(): Removes element sitting at very front
- .front(): Returns value of front element without removing it
- .size(): Returns total number of elements currently in queue
- .empty(): Returns 1 (true) if queue has no elements, 0 (false) otherwise
 */

#include <iostream>
#include <queue> // Required to use STL Queue

using namespace std;

int main() {
    // Creating a queue of strings
    queue<string> q;

    cout << "--- 1. PUSHING ELEMENTS ---" << endl;
    q.push("alice");   // Goes in first (at front)
    q.push("bob"); // Goes in second (in middle)
    q.push("charlie");  // Goes in last (at back)
    
    cout << "Pushed 3 elements into queue." << endl;

    cout << "\n--- 2. ACCESSING FRONT ---" << endl;
    // front element should be FIRST one inserted ("alice")
    cout << "Front Element: " << q.front() << endl;

    cout << "\n--- 3. POPPING ELEMENTS ---" << endl;
    q.pop(); // This removes front element ("alice")
    cout << "Popped front element." << endl;
    
    // Now next person in line ("bob") becomes new front
    cout << "New Front Element: " << q.front() << endl;

    cout << "\n--- 4. SIZE AND EMPTY CHECKS ---" << endl;
    // We pushed 3 and popped 1, so size should be 2
    cout << "Size of queue: " << q.size() << endl;
    
    // Returns 0 (false) because queue is not empty
    cout << "Is queue empty? " << q.empty() << endl;

    return 0;
}

/*
OUTPUT:
--- 1. PUSHING ELEMENTS ---
Pushed 3 elements into queue.

--- 2. ACCESSING FRONT ---
Front Element: alice

--- 3. POPPING ELEMENTS ---
Popped front element.
New Front Element: bob

--- 4. SIZE AND EMPTY CHECKS ---
Size of queue: 2
Is queue empty? 0
*/