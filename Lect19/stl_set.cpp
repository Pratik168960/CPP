/*

        LECTURE 19: C++ STL - SET


GOAL:
- Understand and use STL Set container.

KEY CONCEPTS:
- Stores UNIQUE elements only (duplicates are ignored)
- Automatically SORTS elements behind scenes
- Implemented using a Binary Search Tree (BST)
- Elements cannot be modified once inserted; only inserted or deleted

TIME COMPLEXITIES:
- O(log N): .insert(), .erase(), .find(), .count()
- O(1): .size(), .begin(), .end(), .empty()
 */

#include <iostream>
#include <set> // Required to use STL Set

using namespace std;

int main() {
    set<int> s;

    cout << "--- 1. INSERTION (UNIQUE & SORTED) ---" << endl;
    s.insert(5);
    s.insert(5); // Duplicate, will be ignored
    s.insert(5); // Duplicate, will be ignored
    s.insert(1);
    s.insert(6);
    s.insert(6); // Duplicate, will be ignored
    s.insert(0);

    cout << "Elements in Set: ";
    for (auto i : s) {
        cout << i << " "; // This will print automatically sorted and unique: 0 1 5 6
    }
    cout << endl;

    cout << "\n--- 2. ERASING ELEMENTS ---" << endl;
    // Erasing very first element using an iterator
    set<int>::iterator it = s.begin();
    it++; // Move iterator to second element (which is '1')
    
    s.erase(it); // Erases '1'
    
    cout << "Elements after erasing 2nd item: ";
    for (auto i : s) {
        cout << i << " ";
    }
    cout << endl;

    cout << "\n--- 3. COUNT (CHECKING PRESENCE) ---" << endl;
    // .count() tells you if an element is present (1) or absent (0)
    cout << "Is 5 present in set? " << s.count(5) << endl; 
    cout << "Is -5 present in set? " << s.count(-5) << endl;

    cout << "\n--- 4. FIND (GETTING AN ITERATOR) ---" << endl;
    // .find() returns an iterator pointing to value if found
    set<int>::iterator itr = s.find(5);
    
    cout << "Value present at iterator returned by find(5): " << *itr << endl;

    // You can iterate from this specific found location to end
    cout << "Printing from find(5) iterator to end: ";
    for (auto it = itr; it != s.end(); it++) {
        cout << *it << " "; 
    }
    cout << endl;

    return 0;
}

/*
OUTPUT:
--- 1. INSERTION (UNIQUE & SORTED) ---
Elements in Set: 0 1 5 6 

--- 2. ERASING ELEMENTS ---
Elements after erasing 2nd item: 0 5 6 

--- 3. COUNT (CHECKING PRESENCE) ---
Is 5 present in set? 1
Is -5 present in set? 0

--- 4. FIND (GETTING AN ITERATOR) ---
Value present at iterator returned by find(5): 5
Printing from find(5) iterator to end: 5 6 
*/