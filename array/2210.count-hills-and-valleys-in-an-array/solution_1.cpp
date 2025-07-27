/*
 * @lc app=leetcode id=2210 lang=cpp
 *
 * [2210] Count Hills and Valleys in an Array
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int result = 0, n = nums.size();

        for (int l = -1, mid = -1, i = 0; i < n; i++) {
            int r = nums[i];
            if (r == mid) {continue;}
            if (mid > l && mid > r || mid < l && mid < r) {result++;}

            l = mid;
            mid = r;
        }
        return result;
    }
};
// @lc code=end

