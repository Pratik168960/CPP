/*

        LECTURE 14: SQUARE ROOT USING BINARY SEARCH


GOAL:
- Find the square root of a given integer N.
- If N is not a perfect square, return the decimal value up to a 
specified number of precision places (e.g., square root of 37 is ~6.082).

APPROACH (Two-Part Solution):
    * * PART 1: Find the Integer Part (O(log N))
-  square root of N will always lie between 0 and N
- We can treat 0 to N as our "sorted search space"
- Calculate 'mid'. If mid * mid == N, we found  exact square root
- If mid * mid < N, 'mid' is a potential answer. Store it and move right (start = mid + 1)
- If mid * mid > N, 'mid' is too large. Move left (end = mid - 1)
- IMPORTANT: Use 'long long int' for  square calculation to prevent integer overflow.
    * * PART 2: Add Precision (O(Precision))
- Once we have  integer part (e.g., 6 for N=37), we add a fraction (0.1)
- We keep adding 0.1 as long as  square is less than N
- n we move to  next decimal place (0.01) and repeat, until we 
reach  desired number of decimal places
*/

#include <iostream>
using namespace std;

// Step 1: Find the integer part of the square root using Binary Search
long long int sqrtInteger(int n) {
    int start = 0;
    int end = n;
    long long int ans = -1;

    while (start <= end) {
        long long int mid = start + (end - start) / 2;
        
        // Use long long to avoid overflow when squaring large mid values
        long long int square = mid * mid;

        if (square == n) {
            return mid; // Perfect square found
        }
        
        if (square < n) {
            ans = mid;       // Store potential answer
            start = mid + 1; // Try to find a larger integer
        } 
        else {
            end = mid - 1;   // Number is too large, reduce the search space
        }
    }
    
    return ans;
}

// Step 2: Refine the answer to get the decimal precision
double morePrecision(int n, int precision, int tempSol) {
    double factor = 1;
    double ans = tempSol;

    // Loop for each decimal place (e.g., tenths, hundredths, thousandths)
    for (int i = 0; i < precision; i++) {
        factor = factor / 10; // Becomes 0.1, then 0.01, then 0.001...

        // Increment the answer by the factor as long as its square is <= N
        for (double j = ans; j * j <= n; j = j + factor) {
            ans = j;
        }
    }
    
    return ans;
}

int main() {
    int n;
    cout << "Enter a number to find its square root: ";
    n = 37; 
    cout << n << endl << endl;

    int tempSol = sqrtInteger(n);
    double finalAns = morePrecision(n, 3, tempSol);

    cout << "Integer Part: " << tempSol << endl;
    cout << "Precise Answer (3 decimal places): " << finalAns << endl;

    return 0;
}

/*
OUTPUT:
Enter a number to find its square root: 37

Integer Part: 6
Precise Answer (3 decimal places): 6.082
*/