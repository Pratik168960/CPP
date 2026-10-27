/*

LECTURE 24: MODULAR EXPONENTIATION (FAST EXPONENTIATION)


THE GOAL:
- Calculate (x^n) % m efficiently without integer overflow.

THE APPROACH (Fast Exponentiation):
- Initialize a 'res' variable to 1.
- Loop while n > 0.
- If n is odd (n & 1), multiply 'res' by 'x' and take modulo 'm'.
- Square 'x' and take modulo 'm' at every step.
- Divide 'n' by 2 using a bitwise right-shift (n = n >> 1).

COMPLEXITY:
- Time Complexity: O(log N) as we divide the power by 2 at each step.
- Space Complexity: O(1) auxiliary space.
 */

#include <iostream>

using namespace std;

// Function to calculate (x^n) % m
int modularExponentiation(int x, int n, int m) {
    int res = 1;
    
    while (n > 0) {
        // If the current power is odd
        if (n & 1) {
            // Typecast to 1LL (long long) to prevent intermediate overflow
            res = (1LL * res * (x) % m) % m;
        }
        
        // Square the base
        x = (1LL * (x) % m * (x) % m) % m;
        
        // Divide power by 2
        n = n >> 1;
    }
    return res;
}

int main() {
    int x = 3;
    int n = 5;
    int m = 1000000007; // Standard modulo value in competitive programming
    
    cout << "Target: Calculate (" << x << "^" << n << ") % " << m << endl;
    
    // Call the modular exponentiation function
    int result = modularExponentiation(x, n, m);

    cout << "\n--- RESULTS ---" << endl;
    cout << "Answer: " << result << endl;

    return 0;
}

/*
EXPECTED CONSOLE OUTPUT:
Target: Calculate (3^5) % 1000000007

--- RESULTS ---
Answer: 243
*/