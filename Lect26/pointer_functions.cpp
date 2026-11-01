/*

LECTURE 26: POINTERS IN C++ (PART-2) - POINTERS WITH FUNCTIONS

THE GOAL:
- Understand how pointers and memory addresses are passed to functions.
- Learn the difference between updating a local pointer copy vs dereferenced value.
- Prove that arrays passed to functions are implicitly converted to pointers.
- Learn how to pass sub-arrays (partial arrays) to functions.

KEY CONCEPTS:
1. Pass-by-Value of Pointers:
- Passing `int *p` to a function creates a COPY of the pointer variable.
- Modifying `p = p + 1` inside the function changes ONLY the local copy.
2. Dereferenced Modification:
- Modifying `*p = *p + 1` accesses the physical memory address in `main()`.
- Changes made via `*p` permanently update the original variable.
3. Array Parameters as Pointers:
- `int arr[]` in a function signature is converted to `int *arr`.
- `sizeof(arr)` inside the function returns pointer size (8 bytes), NOT array size.
4. Sub-array Passing:
- `getSum(arr + 3, 3)` passes the address of `arr[1]`, allowing functions to
  process a slice/sub-array directly without extra memory.

TIME COMPLEXITY:
- O(1) for address passing and dereferencing operations.
- O(N) for sub-array sum calculation.

SPACE COMPLEXITY:
- O(1) auxiliary space.
 */

#include <iostream>
using namespace std;

// Function 1: Read-only pointer access
void printPointer(int *p) {
    cout << "Value via pointer: " << *p << endl;
    cout << "Address inside printPointer: " << p << endl;
}

// Function 2: Attempting to update pointer address (Fails for main)
void updateAddress(int *p) {
    // This updates ONLY the local copy of pointer 'p' inside this function scope
    p = p + 1;
    cout << "Address inside updateAddress: " << p << endl;
}

// Function 3: Updating value at memory address (Succeeds for main)
void updateValue(int *p) {
    // Dereferencing directly modifies the value stored at memory location in main()
    *p = *p + 1;
}

// Function 4: Arrays passed as pointers
int getSum(int *arr, int n) {
    // Equivalent to: int getSum(int arr[], int n)
    // Proof that 'arr' is treated as a pointer inside function:
    cout << "sizeof(arr) inside function: " << sizeof(arr) << " bytes (Pointer size!)" << endl;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i]; // Equivalent to: sum += *(arr + i);
    }
    return sum;
}

int main() {
    // ---------------------------------------------------------------------
    // SECTION 1: DEREFERENCING & POINTER PASSING
    // ---------------------------------------------------------------------
    cout << "=== 1. POINTER PASSING ===" << endl;
    int value = 5;
    int *p = &value;
    printPointer(p);
    cout << endl;

    // ---------------------------------------------------------------------
    // SECTION 2: UPDATING ADDRESS VS UPDATING VALUE
    // ---------------------------------------------------------------------
    cout << "=== 2. ADDRESS UPDATE VS VALUE UPDATE ===" << endl;
    cout << "Original Address stored in p: " << p << endl;
    cout << "Original Value of 'value': " << value << endl;

    // Attempting address update
    updateAddress(p);
    cout << "Address in p after updateAddress: " << p << " (Unchanged in main!)" << endl;

    // Performing value update
    updateValue(p);
    cout << "Value of 'value' after updateValue: " << value << " (Successfully updated to 6!)" << endl;
    cout << endl;

    // ---------------------------------------------------------------------
    // SECTION 3: ARRAYS IN FUNCTIONS (PASSED AS POINTERS)
    // ---------------------------------------------------------------------
    cout << "=== 3. ARRAYS IN FUNCTIONS ===" << endl;
    int arr[6] = {1, 2, 3, 4, 5, 8};
    cout << "sizeof(arr) in main(): " << sizeof(arr) << " bytes (Total array size)" << endl;

    // Passing full array to function
    int totalSum = getSum(arr, 6);
    cout << "Total Sum of entire array: " << totalSum << endl;
    cout << endl;

    // ---------------------------------------------------------------------
    // SECTION 4: PASSING SUB-ARRAYS (PARTIAL ARRAYS)
    // ---------------------------------------------------------------------
    cout << "=== 4. PASSING SUB-ARRAYS ===" << endl;
    // Passing array starting from index 3 (element 4): {4, 5, 8}
    int subArraySum = getSum(arr + 3, 3);
    cout << "Sum of sub-array (arr + 3): " << subArraySum << endl; // 4 + 5 + 8 = 17

    return 0;
}

/*  
EXPECTED CONSOLE OUTPUT (Memory addresses will vary):  
=== 1. POINTER PASSING === 
Value via pointer: 5 
Address inside printPointer: 0x7ffeefbff500 

=== 2. ADDRESS UPDATE VS VALUE UPDATE === 
Original Address stored in p: 0x7ffeefbff500 
Original Value of 'value': 5 
Address inside updateAddress: 0x7ffeefbff504 
Address in p after updateAddress: 0x7ffeefbff500 (Unchanged in main!) 
Value of 'value' after updateValue: 6 (Successfully updated to 6!) 

=== 3. ARRAYS IN FUNCTIONS === 
sizeof(arr) in main(): 24 bytes (Total array size) 
sizeof(arr) inside function: 8 bytes (Pointer size!) 
Total Sum of entire array: 23 

=== 4. PASSING SUB-ARRAYS === 
sizeof(arr) inside function: 8 bytes (Pointer size!) 
Sum of sub-array (arr + 3): 17  
*/