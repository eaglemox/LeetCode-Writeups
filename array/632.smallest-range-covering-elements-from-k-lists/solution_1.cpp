/*
 * @lc app=leetcode id=632 lang=cpp
 *
 * [632] Smallest Range Covering Elements from K Lists
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // Brute force, Time: O(k*N), Space: O(k)
        int k = nums.size();
        vector<int> result = {-100000, 100000}; // max range
        vector<int> indices(k, 0);
        
        while (true) {
            int currMin = INT_MAX, currMax = INT_MIN;
            int minList = 0;
            for (int i = 0; i < k; i++) {
                int num = nums[i][indices[i]];
                if (num < currMin) {
                    currMin = num;
                    minList = i;
                }
                if (num > currMax) {
                    currMax = num;
                }
            }
            // if curr min > new min -> overwrite result only when range is smaller
            if (currMax - currMin < result[1] - result[0]) {
                result[0] = currMin;
                result[1] = currMax;
            }
            // a list reach to end -> impossible to have smaller range (min: same, max: increase)
            if (++indices[minList] == nums[minList].size()) {break;}
        }
        return result;
    }
};
// @lc code=end

