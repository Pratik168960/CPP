/*

        LECTURE 19: C++ STL - LIST (COMPLETE)


GOAL:
- Master STL List container, backed by a Doubly Linked List.

KEY CONCEPTS & FUNCTIONS COVERED:
- .push_back(val) / .push_front(val): Add elements to back/front
- .pop_back() / .pop_front(): Remove elements from back/front
- .front() / .back(): View first and last elements
- .empty(): Returns 1 (true) if empty, 0 (false) otherwise
- .size(): Returns number of elements
- .erase(iterator): Deletes an element (O(N) time complexity)

INITIALIZATION TRICKS:
- list<int> l(size, value); -> Creates a list of a specific size filled with a value
- list<int> copyList(l); -> Copies all elements from list 'l' into a new list
 */

#include <iostream>
#include <list> // Required for STL List

using namespace std;

// Helper function to print list
void printList(const list<int>& l) {
    for (int i : l) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    list<int> l;

    cout << "--- 1. INSERTION ---" << endl;
    l.push_back(1);    // Adds to back
    l.push_front(2);   // Adds to front
    
    cout << "List after pushes: ";
    printList(l);

    cout << "\n--- 2. ACCESSING ELEMENTS ---" << endl;
    // Remember: l.at(1) will throw an error! No random access
    cout << "Front element: " << l.front() << endl;
    cout << "Back element: " << l.back() << endl;
    cout << "Is list empty? " << l.empty() << endl;

    cout << "\n--- 3. ERASING & DELETING ---" << endl;
    cout << "Size before erase: " << l.size() << endl;
    
    // Erase very first element
    l.erase(l.begin());
    
    cout << "Size after erase: " << l.size() << endl;
    cout << "List after erase: ";
    printList(l);

    cout << "\n--- 4. SPECIAL INITIALIZATIONS ---" << endl;
    // Create a new list with 5 elements, all initialized to 100
    list<int> n(5, 100); 
    cout << "List 'n' (size 5, default value 100): ";
    printList(n);

    // Copy list 'n' into a brand new list 'm'
    list<int> m(n);
    cout << "List 'm' (copied exactly from 'n'): ";
    printList(m);

    return 0;
}

/*
OUTPUT:
--- 1. INSERTION ---
List after pushes: 2 1 

--- 2. ACCESSING ELEMENTS ---
Front element: 2
Back element: 1
Is list empty? 0

--- 3. ERASING & DELETING ---
Size before erase: 2
Size after erase: 1
List after erase: 1 

--- 4. SPECIAL INITIALIZATIONS ---
List 'n' (size 5, default value 100): 100 100 100 100 100 
List 'm' (copied exactly from 'n'): 100 100 100 100 100 
*/