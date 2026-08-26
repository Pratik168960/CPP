/*

        LECTURE 19: C++ STL - VECTOR


GOAL:
- Master Vector, most heavily used STL container
- Vectors are dynamic arrays that resize themselves automatically

KEY CONCEPTS:
- Size vs Capacity: Capacity doubles when vector runs out of space
- .push_back(val): Inserts an element at end
- .pop_back(): Removes last element
- .clear(): Deletes all elements. IMPORTANT: This reduces 'size' to 0, 
but 'capacity' remains unchanged
*/

#include <iostream>
#include <vector> // Required for vectors

using namespace std;

void printVector(const vector<int>& v) {
    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<int> v; // Creates an empty vector with 0 capacity

    cout << "Initial Capacity: " << v.capacity() << endl;

    // Adding elements
    v.push_back(1);
    cout << "Capacity after 1st element: " << v.capacity() << endl;

    v.push_back(2);
    cout << "Capacity after 2nd element: " << v.capacity() << endl;

    v.push_back(3);
    // Capacity doubles from 2 to 4 because it ran out of space!
    cout << "Capacity after 3rd element: " << v.capacity() << endl; 
    cout << "Current Size (Actual elements): " << v.size() << endl;

    cout << "Element at 1st index: " << v.at(1) << endl;
    cout << "First element: " << v.front() << endl;
    cout << "Last element: " << v.back() << endl;

    // Removing last element
    cout << "\nBefore pop_back: ";
    printVector(v);
    
    v.pop_back(); // Removes '3'
    
    cout << "After pop_back: ";
    printVector(v);

    // Clearing vector
    cout << "\nBefore clear - Size: " << v.size() << " | Capacity: " << v.capacity() << endl;
    v.clear();
    cout << "After clear - Size: " << v.size() << " | Capacity: " << v.capacity() << endl; // Capacity stays same!

    // Bonus: Initializing a vector with a specific size and default value
    vector<int> a(5, 1); // Size 5, all elements initialized to 1
    cout << "\nVector 'a' initialized with five 1s: ";
    printVector(a);

    // Bonus: Copying one vector into another
    vector<int> last(a); // Copies all elements of 'a' into 'last'
    cout << "Vector 'last' (copy of 'a'): ";
    printVector(last);

    return 0;
}



/*
OUTPUT:
Initial Capacity: 0
Capacity after 1st element: 1
Capacity after 2nd element: 2
Capacity after 3rd element: 4
Current Size (Actual elements): 3
Element at 1st index: 2
First element: 1
Last element: 3

Before pop_back: 1 2 3 
After pop_back: 1 2 

Before clear - Size: 2 | Capacity: 4
After clear - Size: 0 | Capacity: 4

Vector 'a' initialized with five 1s: 1 1 1 1 1 
Vector 'last' (copy of 'a'): 1 1 1 1 1
*/