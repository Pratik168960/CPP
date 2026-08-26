/*

        LECTURE 19: C++ STL - STACK


GOAL:
- Understand and use STL Stack container

KEY CONCEPTS:
- A Stack operates on Last-In-First-Out (LIFO) principle
- Think of it like a stack of plates: last plate put on top is first one you pick up

KEY FUNCTIONS COVERED:
- .push(val): Adds an element to very top of stack
- .pop(): Removes element sitting at top
- .top(): Returns value of top element without removing it
- .size(): Returns total number of elements currently in stack
- .empty(): Returns 1 (true) if stack has no elements, 0 (false) otherwise
 */

#include <iostream>
#include <stack> // Required to use STL Stack

using namespace std;

int main() {
    // Creating a stack of strings
    stack<string> s;

    cout << "--- 1. PUSHING ELEMENTS ---" << endl;
    s.push("alice");   // Goes to bottom
    s.push("bob"); // Goes in middle
    s.push("charlie");  // Goes to top
    
    cout << "Pushed 3 elements into stack." << endl;

    cout << "\n--- 2. ACCESSING TOP ---" << endl;
    // top element should be last one inserted ("charlie")
    cout << "Top Element: " << s.top() << endl;

    cout << "\n--- 3. POPPING ELEMENTS ---" << endl;
    s.pop(); // This removes top element ("charlie")
    cout << "Popped top element." << endl;
    
    // Now new top element should be "bob"
    cout << "New Top Element: " << s.top() << endl;

    cout << "\n--- 4. SIZE AND EMPTY CHECKS ---" << endl;
    // We pushed 3 and popped 1, so size should be 2
    cout << "Size of stack: " << s.size() << endl;
    
    // Returns 0 because stack is not empty
    cout << "Is stack empty? " << s.empty() << endl;

    return 0;
}


/*
OUTPUT:
--- 1. PUSHING ELEMENTS ---
Pushed 3 elements into stack.

--- 2. ACCESSING TOP ---
Top Element: charlie

--- 3. POPPING ELEMENTS ---
Popped top element.
New Top Element: bob

--- 4. SIZE AND EMPTY CHECKS ---
Size of stack: 2
Is stack empty? 0
*/