// output -->
// Enter a value of n : 3
// A B C 
// B C D 
// C D E 

// program 
#include<iostream>
using namespace std;

int main (){

    int n;
    cout << "Enter a value of n : ";
    cin >> n;

    int i = 1;
    while (i <= n){
        int j = 1;
        char ch = 'A' + i - 1;
        while (j <= n){
            cout << ch << " ";
            ch++;
            j++;
        }
        cout << endl;
        i++;

    }
}