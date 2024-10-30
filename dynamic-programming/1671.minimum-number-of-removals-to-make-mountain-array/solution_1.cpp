/*
 * @lc app=leetcode id=1671 lang=cpp
 *
 * [1671] Minimum Number of Removals to Make Mountain Array
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        // Brute force find LIS, LDS length of each element
        // Time: O(N^2), Space: O(N)
        int len = nums.size();
        int maxMountainLength = 0;
        vector<int> LIS(len, 1), LDS(len, 1);
        for (int i = len - 1; i >= 0; i--) { // O(N^2)
            for (int j = len - 1; j > i; j--) {
                if (nums[i] > nums[j]) {
                    LDS[i] = max(LDS[i], LDS[j] + 1);
                }
            }
        }
        for (int i = 0; i < len; i++) { // O(N^2)
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    LIS[i] = max(LIS[i], LIS[j] + 1);
                }
            }
            if (LIS[i] > 1 && LDS[i] > 1) {
                maxMountainLength = max(maxMountainLength, LIS[i] + LDS[i] - 1);
            }
        }
        return len - maxMountainLength;
    }
};
// @lc code=end

