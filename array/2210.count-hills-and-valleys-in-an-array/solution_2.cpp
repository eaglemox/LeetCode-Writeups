/*
 * @lc app=leetcode id=2210 lang=cpp
 *
 * [2210] Count Hills and Valleys in an Array
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int result = 0;
        vector<int> nonRepeat;
        for (const int& num: nums) {
            if (nonRepeat.empty() || num != nonRepeat.back()) {
                nonRepeat.push_back(num);
            }
        }
        int n = nonRepeat.size();
        for (int i = 1; i < n - 1; i++) {
            if ((nonRepeat[i-1] < nonRepeat[i]) == (nonRepeat[i+1] < nonRepeat[i])) {
                result++;
            }
        }
        return result;
    }
};
// @lc code=end

