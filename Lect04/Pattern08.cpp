// output -->
// Enter a value of n : 5
// 1 
// 2 3 
// 4 5 6 
// 7 8 9 10 
// 11 12 13 14 15 

// program 
#include<iostream>
using namespace std;

int main (){
    int n;
    cout << "Enter a value of n : ";
    cin >> n;

    int count = 1;
    int i = 1;
    while(i <= n){
        int j = 1;
        while(j <= i){
            cout << count << " ";
            count++;
            j++;
        }
        cout << endl;
        i++;
    }
}