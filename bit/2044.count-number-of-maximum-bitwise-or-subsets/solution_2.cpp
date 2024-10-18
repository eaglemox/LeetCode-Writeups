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
        // bit select, Time: O(N2^N), Space: O(1)
        int maxOR = 0;
        for (int num : nums) {
            maxOR |= num;
        }
        int count = 0; 
        int totalSubsets = 1 << nums.size(); // 2^N
        for (int subsetMask = 1; subsetMask < totalSubsets; subsetMask++) {
            // mask [1,1,0,1,0,0,0,0]
            int bitOR = 0;
            for (int i = 0; i < nums.size(); i++) {
                if ((subsetMask >> i & 1) == 1) { // i bit from right represent, i-th num
                    bitOR |= nums[i];
                }
            }
            if (bitOR == maxOR) {
                count++;
            }
        }
        return count;
    }
};
// @lc code=end

