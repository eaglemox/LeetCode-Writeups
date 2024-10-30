/*
 * @lc app=leetcode id=1671 lang=cpp
 *
 * [1671] Minimum Number of Removals to Make Mountain Array
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        // Construct LIS, LDS of each index with binary search
        // Time: O(NlogN), Space: O(N)
        int len = nums.size();
        int maxMountainLength = 0;
        vector<int> LIS(len, 1), LDS(len, 1), subSequence;

        subSequence.push_back(nums[0]);
        for (int i = len - 2; i >= 0; i--) {
            if (nums[i] > subSequence.back()) {
                subSequence.push_back(nums[i]);
            } else {
                *lower_bound(subSequence.begin(), subSequence.end(), nums[i]) = nums[i];
            }
            LDS[i] = subSequence.size();
        }
        subSequence.clear(); // clear LDS array
        subSequence.push_back(nums[0]);
        for (int i = 1; i < len; i++) {
            if (nums[i] > subSequence.back()) {
                subSequence.push_back(nums[i]);
            } else {
                *lower_bound(subSequence.begin(), subSequence.end(), nums[i]) = nums[i];
            }
            LIS[i] = subSequence.size();
            if (LIS[i] > 1 && LDS[i] > 1) {
                maxMountainLength = max(maxMountainLength, LIS[i] + LDS[i] - 1);
            }
        }
        return len - maxMountainLength;
    }
};
// @lc code=end

