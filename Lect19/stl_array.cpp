/*

      LECTURE 19: C++ STL - ARRAY
 

GOAL:
- Understand basic STL Array container
- An STL array is static, meaning its size is fixed and cannot change

KEY FUNCTIONS LEARNED:
- .size(): Returns number of elements
- .at(index): Accesses element at a specific index
- .empty(): Returns true (1) if array is empty, false (0) otherwise
- .front(): Returns very first element
- .back(): Returns very last element

COMPLEXITY:
- Accessing elements using an index or at() takes O(1) time complexity
*/

#include <iostream>
#include <array> // You must include this to use STL Arrays

using namespace std;

int main() {
    // Creating a standard basic array (old way)
    int basic[3] = {1, 2, 3};

    // Creating an STL Array of type int and size 4
    array<int, 4> a = {1, 2, 3, 4};

    // Getting size
    int size = a.size();
    cout << "Size of array is: " << size << endl;

    // Accessing elements using a loop
    cout << "Elements in array: ";
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    // Using STL specific functions
    cout << "Element at 2nd index: " << a.at(2) << endl;
    cout << "Is array empty or not? " << a.empty() << endl; // Returns 0 for false
    cout << "First element: " << a.front() << endl;
    cout << "Last element: " << a.back() << endl;

    return 0;
}


/*
OUTPUT:
Size of array is: 4
Elements in array: 1 2 3 4 
Element at 2nd index: 3
Is array empty or not? 0
First element: 1
Last element: 4
*/