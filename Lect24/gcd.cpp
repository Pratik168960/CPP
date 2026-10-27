/*

LECTURE 24: GREATEST COMMON DIVISOR (EUCLID'S ALGORITHM)


THE GOAL:
- Find the Greatest Common Divisor (GCD) or Highest Common 
  Factor (HCF) of two integer values.

THE APPROACH (Euclid's Algorithm):
- If 'a' becomes 0, the GCD is 'b'. If 'b' becomes 0, the GCD is 'a'.
- Run a loop while both 'a' and 'b' are greater than 0.
- If a > b, update a = a % b (or a = a - b for the subtraction method).
- If b > a, update b = b % a (or b = b - a).
- Return the remaining non-zero number.

COMPLEXITY:
- Time Complexity: O(log(min(a, b))) because the modulo operation 
  reduces the numbers exponentially fast.
- Space Complexity: O(1) auxiliary space.
 */

#include <iostream>

using namespace std;

// Function to calculate GCD using Euclid's Algorithm
int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    
    while (a != b) {
        if (a == 0) return b;
        if (b == 0) return a;
        
        if (a > b) {
            a = a % b; // Modulo is faster than subtraction (a = a - b)
        } else {
            b = b % a; // Modulo is faster than subtraction (b = b - a)
        }
    }
    
    return a;
}

int main() {
    int a = 72;
    int b = 24;
    
    cout << "Target: Find the GCD of " << a << " and " << b << endl;
    
    // Call the GCD function
    int result = gcd(a, b);

    cout << "\n--- RESULTS ---" << endl;
    cout << "The Greatest Common Divisor is: " << result << endl;

    return 0;
}

/*
EXPECTED CONSOLE OUTPUT:
Target: Find the GCD of 72 and 24

--- RESULTS ---
The Greatest Common Divisor is: 24
*/