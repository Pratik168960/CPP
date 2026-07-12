// binary to decimal 

//  1    0    1    0    1
// 2^4  2^3  2^2  2^1  2^0
// ignore the 0 bits 
// 2^4 + 2^2 + 2^0 
// 16 + 4 + 1 => 21 

#include<iostream>
#include<math.h>
using namespace std ;

int main (){

    int n;
    cout << "Enter a binary number : ";
    cin >> n;

    int i = 0;
    int ans = 0;
    while (n != 0){
        int digit = n % 10;
        if (digit == 1){
            ans = ans + pow(2, i);
        }
        n = n / 10;
        i++;
    }
    cout << ans << endl;
}