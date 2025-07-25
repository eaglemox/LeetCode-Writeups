/*
 * @lc app=leetcode id=3487 lang=cpp
 *
 * [3487] Maximum Unique Subarray Sum After Deletion
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums) {
        // Using sorting to check if largest number non-positive 
        int result = 0;
        int freq[101] = {0}; // 0 ~ 100

        sort(nums.begin(), nums.end(), greater<int>());

        if (nums[0] <= 0) {return nums[0];}
        for (int& num: nums) {
            if (num <= 0) {continue;}
            freq[num]++;
        }

        for (int i = 1; i <= 100; i++) {
            if (freq[i] > 0) {result += i;}
        }

        return result;
    }
};
// @lc code=end

