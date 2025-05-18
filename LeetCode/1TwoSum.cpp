#include <iostream>
#include <vector>

using namespace std;

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

	Solution* s = new Solution;
	vector<int> result = s->twoSum(vec, 9);

	for (int i = 0; i < result.size(); i++)
		std::cout << result[i] << std::endl; 

	return 0;
}


	

