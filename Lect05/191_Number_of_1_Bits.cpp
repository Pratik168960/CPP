// LeetCode Problem 191_Number_of_1_Bits


// there are two ways to solve this question 
// 1. convert the number into binary and count 1 
// 2. check all 32 bits and calculate the total num of 1
// 3. right shift and check the last bit until the number become zero 
// this is the 3rd approach 

class Solution {
public:
    int hammingWeight(int n) {
        // initializing the count variable
        int count = 0 ;
        // loop as long as number is non zero 
        while(n != 0){
            // AND operator 
            if (n&1){
                count++;
            }
            // right shift 
            n = n >> 1 ;
        }
        return count ;
    }
};