/*

LECTURE 26: POINTERS IN C++ (PART-2) - POINTERS WITH CHARACTER ARRAYS


THE GOAL:
- Understand how `cout` behaves differently for integer vs character arrays.
- Learn why character pointers (`char*`) print values until the null character (`\0`).
- Identify dangerous memory practices (missing null-terminator and string literals).

KEY CONCEPTS:
1. `cout` Implementation:
- `cout << int_array` prints the starting hexadecimal memory address.
- `cout << char_array` is overloaded to print actual characters until `\0`.
2. Standalone Pointer Printing:
- `char *c = ch; cout << c;` prints the full string, NOT the memory address.
3. Absence of Null Terminator (`\0`):
- `cout << ptr_to_single_char` prints the character and then scans adjacent
  RAM for `\0`, producing garbage output.
4. String Literal Risk:
- `char *c = "abcde";` points to temporary/read-only memory and is unsafe.
- Always use `char ch[6] = "abcde";` to safely allocate memory on the stack.

TIME COMPLEXITY:
- O(N) for string printing up to the null-terminator `\0`.

SPACE COMPLEXITY:
- O(1) auxiliary space.
 */

#include <iostream>
using namespace std;

int main() {
    // ---------------------------------------------------------------------
    // SECTION 1: COUT BEHAVIOR (INT ARRAY VS CHAR ARRAY)
    // ---------------------------------------------------------------------
    int arr[5] = {1, 2, 3, 4, 5};
    char ch[6] = "abcde"; // 5 letters + 1 null character '\0'

    cout << "=== 1. COUT BEHAVIOR (INT VS CHAR) ===" << endl;
    // For integer arrays, cout prints the base memory address
    cout << "Printing int array (arr): " << arr << endl;
    
    // For character arrays, cout prints the string content until '\0'
    cout << "Printing char array (ch): " << ch << endl;
    cout << endl;

    // ---------------------------------------------------------------------
    // SECTION 2: STANDALONE POINTERS (INT* VS CHAR*)
    // ---------------------------------------------------------------------
    cout << "=== 2. STANDALONE POINTERS ===" << endl;
    int *ptr = arr;
    cout << "Printing int pointer (ptr): " << ptr << endl; // Prints memory address

    char *c = ch;
    cout << "Printing char pointer (c): " << c << endl; // Prints entire string "abcde"
    cout << "First character via (*c): " << *c << endl; // 'a'
    cout << endl;

    // ---------------------------------------------------------------------
    // SECTION 3: THE DANGEROUS TRAP (MISSING NULL-TERMINATOR '\0')
    // ---------------------------------------------------------------------
    cout << "=== 3. ABSENCE OF NULL TERMINATOR '\\0' ===" << endl;
    char temp = 'z';
    char *p = &temp;
    
    // cout starts at address of 'z' and keeps printing memory until it encounters '\0'
    cout << "Printing char pointer without '\\0' (p): " << p << endl; // Prints 'z' + garbage
    cout << endl;

    // ---------------------------------------------------------------------
    // SECTION 4: RISKY PRACTICE (STRING LITERALS WITH POINTERS)
    // ---------------------------------------------------------------------
    cout << "=== 4. STRING LITERAL POINTER RISK ===" << endl;
    /*
     * RISKY / BAD PRACTICE:
     * char *str = "abcde";
     * "abcde" is stored in temporary, read-only memory. Pointing a `char*` directly
     * to it is extremely dangerous because modifying *str causes undefined behavior.
     */

    // SAFE & CORRECT PRACTICE:
    // Character array allocates stack memory and safely copies "abcde" into it.
    char safeStr[6] = "abcde";
    char *strPtr = safeStr;
    cout << "Safe string via pointer: " << strPtr << endl;
    
    return 0;
}

/*  
EXPECTED CONSOLE OUTPUT (Memory addresses will vary):  
=== 1. COUT BEHAVIOR (INT VS CHAR) === 
Printing int array (arr): 0x7ffeefbff500 
Printing char array (ch): abcde 

=== 2. STANDALONE POINTERS === 
Printing int pointer (ptr): 0x7ffeefbff500 
Printing char pointer (c): abcde 
First character via (*c): a 

=== 3. ABSENCE OF NULL TERMINATOR '\0' === 
Printing char pointer without '\0' (p): z@#%& (garbage until '\0') 

=== 4. STRING LITERAL POINTER RISK === 
Safe string via pointer: abcde  
*/