/*
 * @lc app=leetcode id=2275 lang=cpp
 *
 * [2275] Largest Combination With Bitwise AND Greater Than Zero
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int bitFrequency, maxFrequency = 0;
        for (int bit = 0; bit < 24; bit++) {
            bitFrequency = 0;
            for (int i = 0; i < candidates.size(); i++) {
                bitFrequency += ((candidates[i] >> bit) & 1);
            }
            maxFrequency = max(maxFrequency, bitFrequency);
        }
        return maxFrequency;
    }
};
// @lc code=end

