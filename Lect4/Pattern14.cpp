// output -->
// Enter a value of n : 5
// A B C D E 
// B C D E F 
// C D E F G 
// D E F G H 
// E F G H I 

// Program 
#include<iostream>
using namespace std;

int main (){
    int n;
    cout << "Enter a value of n : ";
    cin >> n;

    int i = 1;
    while(i <= n){
        int j = 1;
        while (j <= n){
            char ch = 'A' + i + j - 2;
            cout << ch << " ";
            j++;
        }
        cout << endl;
        i++;

    }
}