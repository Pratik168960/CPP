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
    bool isPowerOfTwo(int n) {
        for (int i = 0; i <= 30; i++){
        int ans = pow(2, i);

        if(ans == n){
            return true;
        }
    }
    return false;
    }
};