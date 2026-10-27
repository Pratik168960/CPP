// PRINT COUNTING (Void Function Example)

#include <iostream>
using namespace std;

// We use 'void' because this function does not return any data to main()
// function signature 
void printCounting(int n) {
    
    // function body 
    for (int i = 1; i <= n; i++) {
        cout << i << " ";
    }
    
    cout << endl;
}

int main() {
    int n;
    
    cout << "Enter a number to count up to: ";
    cin >> n;

    // Calling the function
    printCounting(n);

    return 0; 
}