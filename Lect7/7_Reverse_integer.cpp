// Leetcode problem 7. Reverse Integer 

// if the result after reversing is out of range [-2^31, 2^31 -1] then return 0 
// n = 123 
// first we will get single digits by using modulo % 10 and then divide 
// we will get 3, 2, 1 

// initialize a variable ans = 0 
// ans = ans * 10 + digit 

// ans = 0 * 10 + 3 = 3 
// ans = 3 * 10 + 2 = 32 
// ans = 32 * 10 + 1 = 321



// digit (n % 10)                              3     2     1
// ans = ans * 10 + digit(start with zero)     3     32    321
// n = n / 10                                  12    1     0-> stop

// but this solution is not complete as there may occur overflow it may get out of range 
// ans -> [-2^31(INT_MIN), 2^31 - 1(INT_MAX) ]

// if (ans > (INT_MAX/10) || (ans < (INT_MIN/10))


class Solution {
public:
    int reverse(int x) {
        // initialise variable for result 
        int ans = 0;
        
        // loop as long as x is non zero 
        while (x != 0) {
            // digit using modulo 
            int digit = x % 10;
            // then update the number 
            x /= 10;
            
            // Check for overflow BEFORE it happens
            // this is the condition when answer will get out of range 
            if (ans > INT_MAX / 10 || ans < INT_MIN / 10) {
                return 0;
            }
            // result 
            ans = ans * 10 + digit;
        }
        
        return ans;
    }
};