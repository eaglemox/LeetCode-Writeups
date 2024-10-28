/*
 * @lc app=leetcode id=2501 lang=cpp
 *
 * [2501] Longest Square Streak in an Array
 */

// @lc code=start
#include <unordered_set>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        // Using set to find the sqaure streak of base
        // Time: O(N), Space: O(N)
        unordered_set<int> unique(nums.begin(), nums.end());

        int prev, maxLength = 0;
        for (int base : nums) { // O(N*log1e5)
            if (base > 316) {continue;}
            if (maxLength > 1 && base > 17) {continue;}
            if (maxLength > 2 && base > 4) {continue;}
            if (maxLength > 3 && base > 2) {continue;}
            long long current = base; // max ~1e10 < LL_MAX
            int length = 0;
            while (unique.find(current) != unique.end()) { // O(log1e5) worst case
                length++;
                if (current * current > 1e5) {break;}
                current *= current;
            }
            maxLength = max(maxLength, length);
        }
        return (maxLength >= 2) ? maxLength : -1;
    }
};
// @lc code=end

