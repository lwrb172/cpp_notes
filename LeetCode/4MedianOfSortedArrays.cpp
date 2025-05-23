#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> l(n1), r(n2);

    for (int i = 0; i < n1; i++)
        l[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        r[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (l[i] <= r[j]) {
            arr[k] = l[i];
            i++;
        } else {
            arr[k] = r[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = l[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = r[j];
        j++;
        k++;
    }
}

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged = nums1;
        merged.insert(merged.end(), nums2.begin(), nums2.end());

        int mid = nums1.size()-1;
        merge(merged, 0, mid, merged.size()-1);

//        for (int x : merged)
//             cout << x << ' ';
//        cout << endl;

        int n = merged.size();
        if (n % 2 == 0)
            return (merged[n/2-1] + merged[n/2])/2.0;

        return merged[n/2];
    }
};

int main() {
    vector<int> arr1 = {1, 3};
    vector<int> arr2 = {2, 4};

    Solution s;
    double result = s.findMedianSortedArrays(arr1, arr2);

    cout << result << endl;

    return 0;
}
