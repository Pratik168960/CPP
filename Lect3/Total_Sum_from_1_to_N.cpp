//output -->
// Enter a value for n : 5
// Sum of numbers from 1 to 5 is 15

// program
#include<iostream>
using namespace std;

int main (){
    int n;
    cout << "Enter a value for n : ";
    cin >> n;
    int i = 1;
    int sum = 0;
    while(i<=n){
        sum = sum + i;
        i++;
    }

    cout << "Sum of numbers from 1 to " << n << " is " << sum << endl;
}