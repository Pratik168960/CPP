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

POINTER ARITHMETIC NOTE:
- If you declare `int i = 3` and its memory address is 100, and you point 
  to it using `int *t = &i`, executing `t = t + 1` will NOT result in address 101. 
  It will jump to address 104 because an integer data type takes exactly 4 bytes 
  of memory. The pointer scales by the size of its data type.

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
    cout << "Address of num in memory: " << &num << endl;

    // Create a pointer to store the address of num
    int *ptr = &num; 

    cout << "\n--- THE POINTER ---" << endl;
    cout << "Address stored inside ptr: " << ptr << endl;
    // Dereferencing the pointer to get the value (* is a dereference operator)
    cout << "Value at the address ptr is pointing to (*ptr): " << *ptr << endl;

    // Modifying the value using the pointer
    *ptr = *ptr + 1; 
    cout << "\n--- AFTER MODIFICATION ---" << endl;
    cout << "New value of num: " << num << endl;

    // Copying a pointer
    int *q = ptr; 

    cout << "\n--- COPYING A POINTER ---" << endl;
    cout << "Address stored in q: " << q << endl;
    cout << "Value at *q: " << *q << endl;
    
    // --- POINTER ARITHMETIC DEMONSTRATION ---
    int i = 3;
    int *t = &i;
    cout << "\n--- POINTER ARITHMETIC ---" << endl;
    cout << "Original address of i stored in t: " << t << endl;
    t = t + 1; 
    cout << "Address after (t = t + 1): " << t << " (Jumped by exactly 4 bytes)" << endl;

    // SAFE PRACTICE: Null Pointer
    int *safePtr = 0; // Initialize to 0 if no address is available

    return 0;
}