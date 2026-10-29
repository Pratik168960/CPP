/*

LECTURE 25: POINTERS INTRO & MEMORY ADDRESSES


THE GOAL:
- Understand how to fetch memory addresses and store them in pointers.
- Use the dereference operator (*) to access/modify values.

THE APPROACH:
- Declare an integer 'num' and fetch its address using '&num'.
- Create a pointer 'ptr' to store this address.
- Access the value using '*ptr' and modify it.
- Copy 'ptr' into a new pointer 'q' to prove they both point to 
  the same physical memory block.

COMPLEXITY:
- Time Complexity: O(1) for all pointer creations and accesses.
- Space Complexity: O(1) auxiliary space (usually 8 bytes to store a pointer 
  on a 64-bit architecture, regardless of the data type).
 */

#include <iostream>

using namespace std;

int main() {
    int num = 5;
    
    cout << "--- THE ORIGINAL VARIABLE ---" << endl;
    cout << "Value of num: " << num << endl;
    cout << "Address of num in memory: " << &num << endl; // Prints memory address

    // Create a pointer to store the address of num
    int *ptr = &num; 

    cout << "\n--- THE POINTER ---" << endl;
    cout << "Address stored inside ptr: " << ptr << endl;
    // Dereferencing the pointer to get the value 
    // * is a dereference operator
    cout << "Value at the address ptr is pointing to (*ptr): " << *ptr << endl;

    // Modifying the value using the pointer
    *ptr = *ptr + 1; // Increment the value at the address
    cout << "\n--- AFTER MODIFICATION ---" << endl;
    cout << "New value of num: " << num << endl;

    // Copying a pointer
    int *q = ptr; // 'q' now holds the exact same address as 'ptr'

    cout << "\n--- COPYING A POINTER ---" << endl;
    cout << "Address stored in q: " << q << endl;
    cout << "Value at *q: " << *q << endl;

    // VERY BAD PRACTICE: Uninitialized/Wild Pointer
    // int *badPtr; // Points to random garbage memory
    // *badPtr = 10; // DANGEROUS: Modifies unknown memory
    
    // SAFE PRACTICE: Null Pointer
    int *safePtr = 0; // Initialize to 0 if no address is available

    return 0;
}

/*
OUTPUT (Addresses will vary on your machine):
--- THE ORIGINAL VARIABLE ---
Value of num: 5
Address of num in memory: 0x7ffee4b5c9ac

--- THE POINTER ---
Address stored inside ptr: 0x7ffee4b5c9ac
Value at the address ptr is pointing to (*ptr): 5

--- AFTER MODIFICATION ---
New value of num: 6

--- COPYING A POINTER ---
Address stored in q: 0x7ffee4b5c9ac
Value at *q: 6
*/