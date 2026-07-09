// output -->
// Enter a value of n : 5
// 54321
// 54321
// 54321
// 54321
// 54321

// program 
#include<iostream>
using namespace std;

int main (){
    int n;
    cout << "Enter a value of n : ";
    cin >> n;

    int i = 1;
    while(i <= n){
        int j = n;
        while(j >= 1){
            cout << j;
            j--;
        }
        cout << endl;
        i++;
    }
}