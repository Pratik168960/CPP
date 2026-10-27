// output -->
// Enter a value of n : 5
// A 
// B C 
// C D E 
// D E F G 
// E F G H I

// Program 
#include<iostream>
using namespace std;

int main (){
    int n;
    cout << "Enter a value of n : ";
    cin >> n;

    int i = 1;
    while (i <= n){
        int j = 1;
        while (j <= i){
            char ch = 'A' + i +j - 2 ;
            cout << ch << " ";
            j++;
        }
        cout << endl;
        i++;
    }
}