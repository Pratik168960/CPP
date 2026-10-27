//output-->
// Enter a value of n : 10
// Sum of even numbers from 1 to 10 is 30


//program 
#include<iostream>
using namespace std;

int main (){
    int n;
    cout << "Enter a value of n : ";
    cin >> n;

    int sum = 0;
    int i = 2;
    while(i<=n){
        sum = sum + i;
        i = i + 2;
    }
    cout << "Sum of even numbers from 1 to " << n << " is " << sum << endl;
}