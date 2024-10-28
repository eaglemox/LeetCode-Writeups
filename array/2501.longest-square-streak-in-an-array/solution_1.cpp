/*
 * @lc app=leetcode id=2501 lang=cpp
 *
 * [2501] Longest Square Streak in an Array
 */

// @lc code=start
#include <set>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        // Brute force, the longest streak usually made of smallest base
        // Time: O(NlogN), Space: O(N)
        set<int> unique(nums.begin(), nums.end());

        int prev, maxLength = 0;
        for (auto it = unique.begin(); it != unique.end(); it++) {
            if (*it > 316) {break;} // cannot have lenght > 1
            if (maxLength > 1 && *it > 17) {break;}
            if (maxLength > 2 && *it > 4) {break;}
            if (maxLength > 3 && *it > 2) {break;} // only [2,4,16,256,65536] has length of 5
            int length = 1;
            prev = *it;
            auto itSquare = it;
            while (itSquare != unique.end()) {
                if (*itSquare % prev == 0 && *itSquare / prev == prev) {
                    prev = *itSquare;
                    length++;
                }
                itSquare++;
            }
            maxLength = max(maxLength, length);
        }
        return (maxLength >= 2) ? maxLength : -1;
    }
};
// @lc code=end

