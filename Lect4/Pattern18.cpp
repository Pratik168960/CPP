// output -->
// Enter a value of n : 5
// E 
// D E 
// C D E 
// B C D E 
// A B C D E

// Program 
#include<iostream>
using namespace std ;

int main (){
    int n;
    cout << "Enter a value of n : ";
    cin >> n;

    int i = 1;
    while (i <= n){
        int j = 1;
        char ch = 'A' + n - i;
        while (j <= i){
            cout << ch << " ";
            ch++;
            j++;
        }
        cout << endl;
        i++;
    }
}