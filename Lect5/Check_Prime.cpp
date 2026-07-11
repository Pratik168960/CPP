#include<iostream>
using namespace std;

int main (){
    int n;
    cout << "Enter a value to check : ";
    cin >> n;

    bool isPrime = 1;

    for (int i = 2; i <= n - 1; i++){
        if (n % i == 0){
            isPrime = 0;
            break;
        }
    }
    if (isPrime == 0){
        cout << "Not Prime" << endl;
    } else {
        cout << "Prime" << endl;
    }
}

// output -->
// Enter a value to check : 11
// Prime

// Enter a value to check : 6
// Not Prime