// LeetCode Problem 1281_Subtract_the_Product_and_Sum_of_Digits_of_an_Integer


class Solution {
public:
    int subtractProductAndSum(int n) {
        int prod = 1;
        int sum = 0;

        while(n != 0){
            int digit = n % 10;
            prod = prod * digit ;
            sum = sum + digit ; 
            n = n / 10 ;
        }
        int result = prod - sum ;
        return result ;
    }
};