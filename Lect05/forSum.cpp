#include<iostream>
using namespace std;

int main (){
    int n;
    cout << "Enter a value of n : ";
    cin >> n;

    int sum = 0;
    for (int i = 1; i <= n; i++){
        sum = sum + i;
    }
    cout << "Sum of numbers from 1 to n is " << sum << endl;
}