/*

        LECTURE 13: PEAK INDEX IN A MOUNTAIN ARRAY


GOAL:
- Find the index of the peak element in a "mountain array"
- A mountain array is an array that strictly increases to a peak element 
and then strictly decreases
- Example: [0, 2, 5, 10, 8, 3, 1] -> Peak is 10 at index 3

APPROACH (Binary Search):
- Because the array has a predictable monotonic property (increasing then decreasing),
we can use Binary Search to achieve O(log N) time complexity
- We calculate the 'mid' element
- Condition 1: If arr[mid] < arr[mid+1]
We are on the upward slope. The peak must be to the right
Move start = mid + 1
- Condition 2: If arr[mid] >= arr[mid+1]
We are either at the peak or on the downward slope. The peak is at 'mid' or to the left
Move end = mid. (Note: We do NOT use mid - 1, because 'mid' itself could be the peak)
- We loop while (start < end). When start and end converge, they will point to the peak
*/


#include <iostream>
using namespace std;


int peakIndexInMountainArray(int arr[], int size) {
    int start = 0;
    int end = size - 1;

    // Notice we use start < end, NOT start <= end
    // This prevents an infinite loop when start and end converge on the peak
    while (start < end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] < arr[mid + 1]) {
            // We are on the rising slope, peak is to the right
            start = mid + 1;
        } else {
            // We are on the falling slope or exactly at the peak
            end = mid;
        }
    }
    
    // Both start and end will converge to the exact peak index
    return start;
}

int main() {
    // Initialize an example mountain array
    int mountain[7] = {0, 2, 5, 10, 8, 3, 1};
    int size = 7;

    cout << "Mountain Array: 0 2 5 10 8 3 1" << endl << endl;
    
    // Call the function
    int peakIndex = peakIndexInMountainArray(mountain, size);
    
    cout << "The peak element is at index: " << peakIndex << endl;
    cout << "The peak element value is: " << mountain[peakIndex] << endl;

    return 0;
}

/*
OUTPUT:
Mountain Array: 0 2 5 10 8 3 1

The peak element is at index: 3
The peak element value is: 10
*/