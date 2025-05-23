#include <iostream>
#include <vector>

using namespace std;

// & symbol allows direct access to the original vector
// without copying (Pass by reference) -> saves memory and time.
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 1; j < nums.size(); j++) {
                if (i != j) {
                    sum = nums[i] + nums[j];
                    if (sum == target) {
                        return {i, j};
                    }
                }
            }
        }
        return {};
    }
};

int main() {
    vector<int> vec = {2, 7, 11, 15};

    Solution s;
    vector<int> result = s.twoSum(vec, 9);

    for (int i = 0; i < result.size(); i++)
        cout << result[i] << endl;

    return 0;
}
