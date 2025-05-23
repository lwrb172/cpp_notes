#include <iostream>
#include <unordered_set>

using namespace std;

// sliding window algorithm
// unordered_set about 2x faster than set, because ordering
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_set<char> sub;
        int maxLength = 0;
        int left = 0;

        for (int right = 0; right < n; right++) {
            while (sub.find(s[right]) != sub.end()) {
                sub.erase(s[left]);
                left++;
            }
            sub.insert(s[right]);
            maxLength = max(maxLength, right-left+1);
        }
        return maxLength;
    }
};

int main() {
    Solution s;
    string str = "abcabcbb";
    int len = s.lengthOfLongestSubstring(str);
    cout << len << endl;

    return 0;
}
