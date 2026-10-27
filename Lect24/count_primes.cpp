/*
 *
 * LECTURE 24: COUNT PRIMES (SIEVE OF ERATOSTHENES)
 *
 *
 * THE GOAL:
 * - Count the total number of prime numbers strictly less than 'n'.
 *
 * THE APPROACH (Sieve of Eratosthenes):
 * - Create a boolean vector of size n+1, initialized entirely to 'true'.
 * - Explicitly mark index 0 and 1 as 'false' (not prime).
 * - Loop from 2 up to n. If the current number is 'true' (prime), increment 
 *   your count.
 * - Run a nested loop to mark all multiples of that prime number as 'false' 
 *   so they are skipped in future iterations.
 *
 * COMPLEXITY:
 * - Time Complexity: O(N * log(log N)) - One of the most optimal math algorithms.
 * - Space Complexity: O(N) to store the boolean sieve array.
 */

#include <iostream>
#include <vector>

using namespace std;

// Function to count primes strictly less than n
int countPrimes(int n) {
    int count = 0;
    
    // Create a boolean array of size n+1, all marked as true initially
    vector<bool> prime(n + 1, true); 

    // 0 and 1 are not prime numbers
    prime[0] = prime[1] = false; 

    for (int i = 2; i < n; i++) {
        if (prime[i]) {
            count++; // We found a prime number!
            
            // Mark all multiples of this prime as false
            for (int j = 2 * i; j < n; j += i) {
                prime[j] = false;
            }
        }
    }
    return count;
}

int main() {
    int n = 40;
    
    cout << "Target: Count all primes strictly less than " << n << endl;
    
    // Call the Sieve of Eratosthenes function
    int result = countPrimes(n);

    cout << "\n--- RESULTS ---" << endl;
    cout << "Total prime numbers found: " << result << endl;

    return 0;
}

/*
OUTPUT:
Target: Count all primes strictly less than 40

--- RESULTS ---
Total prime numbers found: 12
*/