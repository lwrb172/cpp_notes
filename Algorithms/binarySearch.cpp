/*
* Binary Search Algorithm
* - follows divide and conquer standards
* - searching algorithm used in a sorted array
* - repeatedly divides the search interval in half
* - returns the index, otherwise can return -1
* - Time Complexity: O(log N)
*/

#include <iostream>

using namespace std;

// iterative
int binarySearch(int arr[], int low, int high, int x) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] < x)
            low = mid+1;
        else
            high = mid-1;
    }
    return -1;
}

int binarySearchRecursive(int arr[], int low, int high, int x) {
    if (high >= low) {
        int mid = low + (high - low) / 2;

        if (arr[mid == x])
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, low, mid-1, x);

        return binarySearch(arr, mid+1, high, x);
    }
    return -1;
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int x = 23;
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = binarySearch(arr, 0, n-1, x);
    cout << "x found at index: " << result << endl;

    return 0;
}
