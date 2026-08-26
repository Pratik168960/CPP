/*

        LECTURE 19: C++ STL - MAP


GOAL:
- Understand and use STL Map container.

KEY CONCEPTS:
- Stores data in Key-Value pairs
- KEYS must be unique. VALUES can be duplicated
- Standard Maps automatically SORT data by Keys

TIME COMPLEXITIES:
- O(log N) for insertion, deletion, and searching (.find(), .count())
*/


#include <iostream>
#include <map> // Required to use STL Map

using namespace std;



int main() {
    // Creating a map where Key is an Integer, and Value is a String
    map<int, string> m;

    cout << "--- 1. INSERTION ---" << endl;
    // Method 1: Using array-like syntax
    m[1] = "bob";
    m[13] = "tash";
    m[2] = "alice";
    
    // Method 2: Using .insert() function with curly braces
    m.insert({5, "pat"});

    cout << "Printing Map Elements (Automatically Sorted by Keys):" << endl;
    for (auto i : m) {
        // i.first prints Key, i.second prints Value
        cout << i.first << " -> " << i.second << endl;
    }

    cout << "\n--- 2. COUNT (CHECKING PRESENCE) ---" << endl;
    // .count() tells you if a KEY is present (returns 1) or absent (returns 0)
    cout << "Is Key 13 present? " << m.count(13) << endl;
    cout << "Is Key -13 present? " << m.count(-13) << endl;

    cout << "\n--- 3. ERASING ELEMENTS ---" << endl;
    cout << "Erasing Key 13..." << endl;
    m.erase(13); // Provide Key you want to delete
    
    cout << "Map after erase:" << endl;
    for (auto i : m) {
        cout << i.first << " -> " << i.second << endl;
    }

    cout << "\n--- 4. FIND (GETTING AN ITERATOR) ---" << endl;
    // .find() returns an iterator pointing to specific Key-Value pair
    auto it = m.find(5);
    
    if (it != m.end()) {
        cout << "Value at Key 5 is: " << (*it).second << endl;
    }
    
    // You can iterate from this specific found location to end
    cout << "Printing from found iterator to end:" << endl;
    for (auto i = it; i != m.end(); i++) {
        cout << (*i).first << " -> " << (*i).second << endl;
    }

    return 0;
}



/*
OUTPUT:
--- 1. INSERTION ---
Printing Map Elements (Automatically Sorted by Keys):
1 -> bob
2 -> alice
5 -> pat
13 -> tash

--- 2. COUNT (CHECKING PRESENCE) ---
Is Key 13 present? 1
Is Key -13 present? 0

--- 3. ERASING ELEMENTS ---
Erasing Key 13...
Map after erase:
1 -> bob
2 -> alice
5 -> pat

--- 4. FIND (GETTING AN ITERATOR) ---
Value at Key 5 is: pat
Printing from found iterator to end:
5 -> pat
*/