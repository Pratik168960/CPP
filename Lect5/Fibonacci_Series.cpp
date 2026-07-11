// ******** FIBONACCI SERIES ********
// sequence of numbers where every number is the
// sum of the two numbers that come right before it
// 0 1 1 2 3 5 8 13 21 34 55 89

#include<iostream>
using namespace std;

int main (){
    int n;
    cout << "Enter a value of n : ";
    cin >> n;

    int a = 0;
    int b = 1;
    cout << a << " " << b << " " ;
    for (int i = 1; i <= n; i++){
        int next = a + b;
        cout << next << " ";
        a = b;
        b = next;

    }
}

// output -->
// Enter a value of n : 10
// 0 1 1 2 3 5 8 13 21 34 55 89