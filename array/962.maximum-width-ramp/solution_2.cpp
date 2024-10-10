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
        // Two pointer, Time: O(N), Space: O(N)
        int len = nums.size();
        vector<int> rightMax(len);
        rightMax[len-1] = nums[len-1];
        for (int i = len - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i+1], nums[i]);
        }

        for (int num : rightMax) {
            printf("%d ", num);
        } cout << endl;

        int left = 0, right = 0;
        int maxWidth = 0;
        while (right < len) {
            // keep ramp condition hold
            while (left < right && nums[left] > rightMax[right]) {
                left++;
            }
            maxWidth = max(maxWidth, right - left);
            right++;
        }
        return maxWidth;
    }
};
// @lc code=end

