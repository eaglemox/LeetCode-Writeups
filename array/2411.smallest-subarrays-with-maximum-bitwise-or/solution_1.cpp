/*
 * @lc app=leetcode id=2411 lang=cpp
 *
 * [2411] Smallest Subarrays With Maximum Bitwise OR
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        // The problem ask finding the shortest subarray length to max ORsum starting from each index
        int n = nums.size();
        int leftmost[32] = {-1}; // leftmost number's index with certain bit set
        vector<int> result(n);
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < 32; j++) {
                if (nums[i] & (1 << j)) {leftmost[j] = i;}
            }
            
            int farthestBit = i;
            for (int j = 0; j < 32; j++) {
                // Find largest index among set bits -> max out bitwise OR
                farthestBit = max(farthestBit, leftmost[j]);
            }

            result[i] = farthestBit - i + 1;
        }

        return result;
    }
};
// @lc code=end

