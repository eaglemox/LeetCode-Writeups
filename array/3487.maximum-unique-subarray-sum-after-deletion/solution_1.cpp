/*
 * @lc app=leetcode id=3487 lang=cpp
 *
 * [3487] Maximum Unique Subarray Sum After Deletion
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums) {
        // We can delete arbitrary numbers -> the result subarray can be 
        // any subsequence in original array except for empty array
        int freq[201] = {0};
        int n = nums.size(), neg = 0, pos = 0;
        
        for (int i = 0; i < n; i++) {
            if (freq[nums[i]+100]++ == 0) {
                (nums[i] > 0) ? (pos += nums[i]) : (neg += nums[i]);
            }
        }
        if (pos == 0) {
            // Return largest negative number
            for (int i = -1; i >= -100; i--) {
                if (freq[i+100]) {
                    return i;
                }
            }
        }

        return pos;
    }
};
// @lc code=end

