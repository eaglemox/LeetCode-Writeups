/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
   public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> hash;
        for (int num : nums) {
            if (hash[num] == 1) {
                return true;
            }
            hash[num]++;
        }
        return false;
    }
};
// @lc code=end
