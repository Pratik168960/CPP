// output -->
// Enter a number to check prime : 15
// Not Prime

// Enter a number to check prime : 11
// Prime


// Program
#include<iostream>
using namespace std;

int main (){
    int n;
    cout << "Enter a number to check prime : ";
    cin >> n;

    int i = 2;
    while (i < n){
        if (n % i == 0){
            cout << "Not Prime" << endl;
            break;
        }
        i++;
    }
    
    if (i == n) {
        cout << "Prime" << endl;
    }
}