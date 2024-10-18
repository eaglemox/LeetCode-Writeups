/*
 * @lc app=leetcode id=2044 lang=cpp
 *
 * [2044] Count Number of Maximum Bitwise-OR Subsets
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        // recursive select number, Time: O(2^N), Space: O(2N)
        int maxOR = 0;
        for (int num : nums) {
            maxOR |= num;
        }
        return countSubsets(nums, 0, 0, maxOR);
    }
    int countSubsets(vector<int>& nums, int index, int currOR, int targetOR) {
        if (index == nums.size()) {
            return (currOR == targetOR) ? 1 : 0;
        }
        int currSelected = countSubsets(nums, index + 1, currOR | nums[index], targetOR);
        int currNotSelected = countSubsets(nums, index + 1, currOR, targetOR);

        return currSelected + currNotSelected;
    }
};
// @lc code=end

