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
        // Compute XOR sum of nums and complete numbers
        // Time: O(N), Space: O(1)
        int totalSum = nums.size(); // n
        for (int i = 0; i < nums.size(); i++) {
            totalSum ^= nums[i];
            totalSum ^= i; // 0 ~ n-1
        }
        return totalSum;
    }
};
// @lc code=end

