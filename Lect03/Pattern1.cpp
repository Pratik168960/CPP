// output -->
// Enter value of n : 4
// ****
// ****
// ****
// ****

// program 
#include<iostream>
using namespace std;

int main (){
    int n;
    cout << "Enter value of n : " ;
    cin >> n;

    int i = 1;
    while(i<=n){
        int j = 1;
        while(j<=n){
            cout << "*";
            j++;
        }
        cout << endl;
        i++;
    }
}