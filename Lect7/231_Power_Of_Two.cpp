// Leetcode Problem 231_Power_Of_two

// in this question there will be given a number n 
// which we have to check if it is power of 2 or not 
// if yes then true or else false 
// n = 16 ==> 2^4 

// we can do something like this dividing the number till we get one 
// if we get 1 that means it is power of 2 
// if not then it is not 
// but... this is not correct 
// n = 14 this also get divided by 2 and becomes 1 but this is not power of 2 

// 2^10 = 1024 
// 2^31 - 1 which is approx 2^31 = 2 ^(10 + 10 + 11)
// 2^10 * 2^10 * 2^11
// if we take all the powers of 2 and then find n 
// 2^0 , 2^1, 2^2 ,.... 2^30
#include<math.h> // for using pow 





class Solution {
public:
    // Approach 1: Brute Force using pow()
    // Time Complexity: O(log n) | Space Complexity: O(1)
    // We calculate 2^i for i from 0 to 30 and check if it matches n
    bool isPowerOfTwo_BruteForce(int n) {
        for (int i = 0; i <= 30; i++) {
            int ans = pow(2, i);
            if (ans == n) {
                return true;
            }
        }
        return false;
    }

    // Approach 2: Optimized Iteration
    // Time Complexity: O(log n) | Space Complexity: O(1)
    // Multiply answer by 2 in each step.
    bool isPowerOfTwo_Optimized(int n) {
        int ans = 1;
        for (int i = 0; i <= 30; i++) {
            if (ans == n) {
                return true;
            }
            // Prevent integer overflow before multiplying by 2
            if (ans < INT_MAX / 2) {
                ans = ans * 2;
            }
        }
        return false;
    }

    // Approach 3: Bitwise Operation (Most Optimal)
    // Time Complexity: O(1) | Space Complexity: O(1)
    // A power of two in binary always has exactly one '1' bit (e.g., 4 is 100, 8 is 1000).
    // The expression (n & (n - 1)) flips the lowest set '1' bit to '0'. 
    // If the number was a power of two, doing this will make the whole number 0.
    bool isPowerOfTwo_Bitwise(int n) {
        // n > 0 ensures we handle negative numbers and zero correctly
        return n > 0 && (n & (n - 1)) == 0;
    }
};