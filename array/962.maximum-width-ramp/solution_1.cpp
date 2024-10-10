/*
 * @lc app=leetcode id=962 lang=cpp
 *
 * [962] Maximum Width Ramp
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        // Brute force, Time: O(N^2) -> TLE
        int maxWidth = 0;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            for (int j = len - 1; j > i; j--) {
                if (nums[i] > nums[j]) {
                    maxWidth = max(maxWidth, j - i);
                    cout << "max width: " << maxWidth << endl;
                }
            }
        }
        return maxWidth;
    }
};
// @lc code=end

