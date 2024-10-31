/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // Compare sum of complete numbers and sun of nums
        // Time: O(N), Space: O(1)
        int len = nums.size();
        int totalSum = len * (len + 1) / 2;
        for (int i = 0; i < len; i++) {
            totalSum -= nums[i];
        }
        return totalSum;
    }
};
// @lc code=end

