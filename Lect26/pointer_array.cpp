/*

LECTURE 26: POINTERS IN C++ (PART-2) - POINTERS WITH ARRAYS


THE GOAL:
- Master the relationship between Arrays and Pointers in C++.
- Understand base memory addresses, dereferencing, and pointer arithmetic.
- Learn how the compiler resolves array indexing `arr[i]` internally.
- Learn the three major differences between Array names and Pointer variables:
  1. Size difference (`sizeof`)
  2. Address-of operator behavior (`&`)
  3. Symbol Table mapping & reassignment (`arr = arr + 1` vs `ptr = ptr + 1`)

THE APPROACH:
- Declare an integer array `arr` and print `arr`, `&arr`, and `&arr` to
  observe how base addresses are represented in memory.
- Demonstrate dereferencing `*arr`, `*arr + 1`, `*(arr + 1)`, and `*(arr + 2)`
  to show the impact of parentheses on pointer arithmetic vs value arithmetic.
- Implement standard indexing `arr[i]`, pointer arithmetic `*(arr + i)`, and
  reverse indexing `i[arr]` to prove that addition is commutative in C++.
- Compare `sizeof(temp)` (total array size) against `sizeof(ptr)` (pointer size).
- Show that array names cannot be re-assigned (`arr = arr + 1` causes error),
  whereas pointers can be freely incremented (`ptr = ptr + 1`).
 *
TIME COMPLEXITY:
- O(1) for all address calculations, dereferencing, and pointer arithmetic.

SPACE COMPLEXITY:
- O(1) auxiliary space (fixed-size array allocated in stack memory).
 */

#include <iostream>
using namespace std;

int main() {
    // ---------------------------------------------------------------------
    // SECTION 1: BASE ADDRESS & ADDRESS REPRESENTATION
    // ---------------------------------------------------------------------
    int arr[4] = {23, 122, 41, 67};

    cout << "=== 1. BASE ADDRESS OF AN ARRAY ===" << endl;
    cout << "Address of 1st memory block (&arr[0]): " << &arr[0] << endl;
    cout << "Address stored in array name (arr): " << arr << endl;
    cout << "Address of the entire array (&arr): " << &arr << endl;
    cout << endl;

    // ---------------------------------------------------------------------
    // SECTION 2: DEREFERENCING & POINTER ARITHMETIC WITH ARRAYS
    // ---------------------------------------------------------------------
    cout << "=== 2. DEREFERENCING & POINTER ARITHMETIC ===" << endl;
    cout << "Value at *arr (1st element): " << *arr << endl; // 23
    cout << "Value at *arr + 1 (*arr then + 1): " << *arr + 1 << endl; // 23 + 1 = 24
    cout << "Value at *(arr + 1) (2nd element): " << *(arr + 1) << endl; // 122
    cout << "Value at *(arr) + 1 (same as *arr + 1): " << *(arr) + 1 << endl; // 24
    cout << "Value at *(arr + 2) (3rd element): " << *(arr + 2) << endl; // 41
    cout << endl;

    // ---------------------------------------------------------------------
    // SECTION 3: INTERNAL INDEXING FORMULA & REVERSE INDEXING
    // ---------------------------------------------------------------------
    cout << "=== 3. INTERNAL INDEXING FORMULA ===" << endl;
    int i = 2; // Checking 3rd element (index 2)
    
    // Standard way to access an element
    cout << "Standard indexing arr[i]: " << arr[i] << endl; // 41
    
    // How C++ compiler evaluates arr[i] internally: *(arr + i)
    cout << "Internal formula *(arr + i): " << *(arr + i) << endl; // 41
    
    // Reverse indexing: i[arr] evaluates to *(i + arr)
    // Since (arr + i) == (i + arr), i[arr] works perfectly!
    cout << "Reverse indexing i[arr]: " << i[arr] << endl; // 41
    cout << "Internal reverse formula *(i + arr): " << *(i + arr) << endl; // 41
    cout << endl;

    // ---------------------------------------------------------------------
    // SECTION 4: DIFFERENCE #1 - SIZEOF OPERATOR
    // ---------------------------------------------------------------------
    cout << "=== 4. DIFFERENCE #1: SIZEOF OPERATOR ===" << endl;
    int temp[10] = {1, 2, 3, 4, 5};
    int *ptr = temp; 
    
    // sizeof(temp) returns the total memory space allocated for all 10 integers (10 * 4 = 40 bytes)
    cout << "Size of array `sizeof(temp)`: " << sizeof(temp) << " bytes" << endl; // 40 bytes
    
    // sizeof(ptr) returns the size of the pointer variable itself (8 bytes on 64-bit systems)
    cout << "Size of pointer `sizeof(ptr)`: " << sizeof(ptr) << " bytes" << endl; // 8 bytes
    
    // sizeof(*ptr) returns the size of the integer value being pointed to (4 bytes)
    cout << "Size of dereferenced value `sizeof(*ptr)`:" << sizeof(*ptr) << " bytes" << endl; // 4 bytes
    
    // sizeof(&ptr) returns the size of the address of pointer variable (8 bytes)
    cout << "Size of pointer address `sizeof(&ptr)`: " << sizeof(&ptr) << " bytes" << endl; // 8 bytes
    cout << endl;

    // ---------------------------------------------------------------------
    // SECTION 5: DIFFERENCE #2 - ADDRESS-OF OPERATOR (&)
    // ---------------------------------------------------------------------
    cout << "=== 5. DIFFERENCE #2: ADDRESS-OF OPERATOR (&) ===" << endl;
    int a[3] = {10, 20, 30};
    int *p = a;
    
    cout << "Address stored in 'a': " << a << endl;
    cout << "Address of 'a' (&a): " << &a << endl;
    cout << "Address stored in pointer 'p': " << p << endl;
    cout << "Address of pointer variable 'p' (&p): " << &p << endl; // Unique memory address of 'p' itself!
    cout << endl;

    // ---------------------------------------------------------------------
    // SECTION 6: DIFFERENCE #3 - SYMBOL TABLE MAPPING & REASSIGNMENT
    // ---------------------------------------------------------------------
    cout << "=== 6. DIFFERENCE #3: SYMBOL TABLE & REASSIGNMENT ===" << endl;
    
    // ARRAY NAME REASSIGNMENT (ILLEGAL):
    // The array name 'arr' is mapped permanently in the Symbol Table to its base address.
    // Therefore, modifying 'arr' directly causes a compilation error.
    //
    // UNCOMMENTING THE LINE BELOW WILL CAUSE A COMPILATION ERROR:
    // arr = arr + 1; // ERROR: expression must be a modifiable lvalue
    
    // POINTER REASSIGNMENT (LEGAL):
    // A pointer is a separate variable with its own memory location.
    // It can be freely reassigned or incremented.
    int *ptr2 = arr;
    cout << "Original address stored in ptr2: " << ptr2 << endl;
    cout << "Original value at *ptr2: " << *ptr2 << endl; // 23
    
    // Incrementing pointer moves it to the next integer block (adds 4 bytes)
    ptr2 = ptr2 + 1;
    cout << "Address in ptr2 after (ptr2 = ptr2 + 1): " << ptr2 << endl;
    cout << "Value at *ptr2 after increment: " << *ptr2 << endl; // 122
    
    return 0;
}

/*  
EXPECTED CONSOLE OUTPUT (Memory addresses will vary on your machine):  
=== 1. BASE ADDRESS OF AN ARRAY === 
Address of 1st memory block (&arr): 0x7ffeefbff500 
Address stored in array name (arr): 0x7ffeefbff500 
Address of the entire array (&arr): 0x7ffeefbff500 

=== 2. DEREFERENCING & POINTER ARITHMETIC === 
Value at *arr (1st element): 23 
Value at *arr + 1 (*arr then + 1): 24 
Value at *(arr + 1) (2nd element): 122 
Value at *(arr) + 1 (same as *arr + 1): 24 
Value at *(arr + 2) (3rd element): 41 

=== 3. INTERNAL INDEXING FORMULA === 
Standard indexing arr[i]: 41 
Internal formula *(arr + i): 41 
Reverse indexing i[arr]: 41 
Internal reverse formula *(i + arr): 41 

=== 4. DIFFERENCE #1: SIZEOF OPERATOR === 
Size of array `sizeof(temp)`: 40 bytes 
Size of pointer `sizeof(ptr)`: 8 bytes 
Size of dereferenced value `sizeof(*ptr)`: 4 bytes 
Size of pointer address `sizeof(&ptr)`: 8 bytes 

=== 5. DIFFERENCE #2: ADDRESS-OF OPERATOR (&) === 
Address stored in 'a': 0x7ffeefbff4b0 
Address of 'a' (&a): 0x7ffeefbff4b0 
Address stored in pointer 'p': 0x7ffeefbff4b0 
Address of pointer variable 'p' (&p): 0x7ffeefbff4a8 

=== 6. DIFFERENCE #3: SYMBOL TABLE & REASSIGNMENT === 
Original address stored in ptr2: 0x7ffeefbff500 
Original value at *ptr2: 23 
Address in ptr2 after (ptr2 = ptr2 + 1): 0x7ffeefbff504 
Value at *ptr2 after increment: 122  
*/