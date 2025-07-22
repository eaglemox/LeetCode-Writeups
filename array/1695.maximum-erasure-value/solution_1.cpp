/*
 * @lc app=leetcode id=1695 lang=cpp
 *
 * [1695] Maximum Erasure Value
 */

// @lc code=start
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        // Find the largest window with unique elements
        int result = 0, n = nums.size();
        unordered_map<int,int> freq;
        
        int j = 0;
        while (j < n && freq.find(nums[j]) == freq.end()) {
            freq.insert({nums[j], 1});
            result += nums[j++];
        }

        for (int i = 0, curr = result; i < n && j < n; i++) {
            curr -= nums[i];
            freq.erase(nums[i]);
            while (j < n && freq.find(nums[j]) == freq.end()) {
                freq.insert({nums[j], 1});
                curr += nums[j++];
            }
            if (curr > result) {
                result = curr;
            }
        }

        return result;
    }
};
// @lc code=end

