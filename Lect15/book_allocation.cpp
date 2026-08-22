/*

        LECTURE 15: BOOK ALLOCATION PROBLEM


GOAL:
- Given an array representing pages in N books and M students.
- Allocate books contiguously such that  maximum number of pages 
  assigned to a student is MINIMIZED.

APPROACH (Binary Search on Search Space):
- answer (maximum pages a student reads) must lie between 0 and 
total sum of all pages.
- We set start = 0, end = sum of all pages.
- We calculate 'mid'. 'mid' represents  proposed maximum limit 
of pages any student can be assigned.
- We run an 'isPossible' check:
    - If we can successfully allocate all books without exceeding 'mid' 
    pages per student, and without exceeding 'M' students, it's a valid answer!
    - We store  answer, but since we want  MINIMUM possible maximum, 
    we move left: end = mid - 1.
    - If it's not possible, our limit ('mid') is too strict. We move 
    right: start = mid + 1.
 */

#include <iostream>
#include <vector>
using namespace std;

// Helper function to check if a proposed 'mid' max-page limit is valid
bool isPossible(vector<int>& arr, int n, int m, int mid) {
    int studentCount = 1;
    int pageSum = 0;

    for (int i = 0; i < n; i++) {
        // If adding the current book exceeds the 'mid' limit, assign to next student
        if (pageSum + arr[i] <= mid) {
            pageSum += arr[i];
        } else {
            studentCount++;
            
            // If students exceed M, or a single book has more pages than 'mid'
            if (studentCount > m || arr[i] > mid) {
                return false;
            }
            // Assign the current book to the new student
            pageSum = arr[i];
        }
    }
    return true;
}

int allocateBooks(vector<int>& arr, int n, int m) {
    // If there are more students than books, allocation is impossible
    if (m > n) {
        return -1;
    }

    int start = 0;
    int sum = 0;
    
    // Calculate the search space's upper bound (sum of all pages)
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    
    int end = sum;
    int ans = -1;

    // Apply Binary Search on the answer space
    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (isPossible(arr, n, m, mid)) {
            ans = mid;        // Store potential answer
            end = mid - 1;    // Try to minimize it by searching left
        } else {
            start = mid + 1;  // 'mid' is too small, search right
        }
    }
    
    return ans;
}

int main() {

    vector<int> books = {10, 20, 30, 40};
    int n = books.size();
    int m = 2; // Number of students

    cout << "Books Array: 10 20 30 40" << endl;
    cout << "Number of Students: " << m << endl << endl;

    int result = allocateBooks(books, n, m);

    cout << "The minimum possible maximum pages allocated to a student is: " << result << endl;

    return 0;
}

/*
OUTPUT:
Books Array: 10 20 30 40
Number of Students: 2

The minimum possible maximum pages allocated to a student is: 60
*/