// Leetcode Problem 1009 

// if n = 5 its binary is 101 taking its compliment 
// it becomes 010 i.e 2 

// n = 5 -> 000...0101
// ans = 2 -> 000...0010

// ~5 --> 111...1010
// as we can see we got the required 10 at last that is 2 but 
// we have to ignore the remaining bits how we will do this 

// here we can use a mask variable what it will do 
// mask = 000...0111 
// we will use (&) operator on mask and ~5 which will work correctly 
// result = (~n & mask)
// result -> 000...0010

// now how mask will form 
// we can use right shift operator as long as n is non zero 

// and after that we will left shift the mask operator 
// mask = 000...0000 and OR operator 

class Solution {
public:
    int bitwiseComplement(int n) {
        // Edge case: if n is 0, its binary is 0, and complement is 1
        if (n == 0) {
            return 1;
        }
        
        int m = n;
        int mask = 0;
        
        // Build a mask of 1s for the length of n's binary representation
        while (m != 0) {
            mask = (mask << 1) | 1;
            m = m >> 1;
        }
        
        // Bitwise NOT on n, then AND with mask to clear leading bits
        int ans = (~n) & mask;
        return ans; 
    }
};