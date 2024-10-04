/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // prefix & suffix sum: Time: O(N + N) = O(N), Space: O(1) (not extra vector)
        int len = nums.size();
        vector<int> result(len, 1); // fill 1
        
        // save suffix into result
        int suffix = 1;
        for (int i = len-1; i >= 0; i--) {
            result[i] = suffix; // rhs suffix
            suffix *= nums[i];
        }

        // multiplying rhs suffix and lhs prefix
        int prefix = 1; // prefix at -1 idx
        for (int i = 0; i < len; i++) {
            result[i] *= prefix; // rhs suffix * lhs prefix
            prefix *= nums[i];
        }
        return result;
    }
};
// @lc code=end

