/*

        LECTURE 19: C++ STL - DEQUE (DOUBLE ENDED QUEUE)


GOAL:
- Understand Deque (Double Ended Queue) container 

KEY CONCEPTS:
- Insertion & Deletion: You can add and remove elements from BOTH front and back
- .push_back(val) / .push_front(val): Adds elements
- .pop_back() / .pop_front(): Removes elements
- .at(index): Access element at a specific position
- .erase(iterator): Deletes a specific range. It reduces size, but not max memory allocated
*/


#include <iostream>
#include <deque> // Required to use STL Deque

using namespace std;

void printDeque(const deque<int>& d) {
    for (int i : d) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    deque<int> d;

    // 1. Insertion from both ends
    d.push_back(1);    // Adds to end: [1]
    d.push_front(2);   // Adds to front: [2, 1]
    d.push_back(3);    // Adds to end: [2, 1, 3]
    d.push_front(4);   // Adds to front: [4, 2, 1, 3]

    cout << "Deque after pushes: ";
    printDeque(d);

    // 2. Accessing elements
    cout << "Element at 1st index: " << d.at(1) << endl;
    cout << "Front element: " << d.front() << endl;
    cout << "Back element: " << d.back() << endl;
    cout << "Is it empty? " << (d.empty() ? "Yes" : "No") << endl; // Returns 0 for False

    // 3. Deletion from both ends
    d.pop_front(); // Removes first element ('4')
    cout << "\nAfter pop_front: ";
    printDeque(d);

    d.pop_back(); // Removes last element ('3')
    cout << "After pop_back: ";
    printDeque(d);

    // 4. Erasing elements
    cout << "\nSize before erase: " << d.size() << endl;
    
    // Erasing very first element (from begin to begin + 1)
    d.erase(d.begin(), d.begin() + 1); 
    
    cout << "Size after erase: " << d.size() << endl;
    cout << "Deque after erase: ";
    printDeque(d);

    return 0;
}

/*
EXPECTED CONSOLE OUTPUT:
Deque after pushes: 4 2 1 3 
Element at 1st index: 2
Front element: 4
Back element: 3
Is it empty? 0

After pop_front: 2 1 3 
After pop_back: 2 1 

Size before erase: 2
Size after erase: 1
Deque after erase: 1 
*/