/*
 * @lc app=leetcode id=962 lang=cpp
 *
 * [962] Maximum Width Ramp
 */

// @lc code=start
#include <stack>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        // Monotonic stack, Time: O(N), Space: O(N)
        int len = nums.size();
        stack<int> indicesStack;
        int maxWidth = 0;
        for (int i = 0; i < len; i++) {
            // left monotonic descending stack
            // -> smaller the left pair longer the possible maximum width 
            if (indicesStack.empty() || nums[indicesStack.top()] > nums[i]) {
                indicesStack.push(i);
            }
        }

        for (int i = len - 1; i >= 0; i--) {
            while (!indicesStack.empty() && nums[i] >= nums[indicesStack.top()]) {
                maxWidth = max(maxWidth, i - indicesStack.top());
                indicesStack.pop(); // next i won't have greater width and cause O(N^2) TC
            }
        }
        return maxWidth;
    }
};
// @lc code=end

