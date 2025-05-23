/*
* Merge Sort
* - follows divide and conquer approach
* - recursively dividing the input array into two halves
* - then sorting the two halves and merging together
*/

#include <iostream>
#include <vector>

using namespace std;

// first subarray = arr[left...mid]
// second subarray = arr[mid+1...right]
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // copy data to vectors
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
         L[i] = arr[left+i];
    for (int j = 0; j < n2; j++)
         R[j] = arr[mid+1+j];

    int i = 0, j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);
    merge(arr, left, mid, right);
}

int main() {
    vector<int> arr = {12, 11, 13, 22, 5, 7, 2, 8, 55};
    int n = arr.size();
    cout << "input: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';\
    cout << endl;

    mergeSort(arr, 0, n-1);

    cout << "output: ";
    for (int i = 0; i < n; i++)
         cout << arr[i] << ' ';
    cout << endl;

    return 0;
}
