/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
#include <vector>
#include <set>

using namespace std;
class Solution {
   public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> unique(nums.begin(), nums.end());
        return nums.size() > unique.size();
    }
};
// @lc code=end
