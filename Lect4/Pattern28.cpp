// output -->
// Enter a value of n : 5
// 1234554321
// 1234**4321
// 123****321
// 12******21
// 1********1

// program 
#include<iostream>
using namespace std;

int main (){
    int n;
    cout << "Enter a value of n : ";
    cin >> n;

    int i = 1;
    while (i <= n){
        int count = n - i + 1;
        int j = 1;
        while(j <= count){
            cout << j;
            j++;
        }
        int star = (i - 1) * 2;
        int k = 1;
        while(k <= star){
            cout << "*";
            k++;
        }
        int l = count;
        while(l >= 1){
            cout << l;
            l--;
        }
        cout << endl;
        i++;
    }
}