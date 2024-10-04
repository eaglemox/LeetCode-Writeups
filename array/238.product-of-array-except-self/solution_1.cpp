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
        // prefix & suffix sum: Time: O(N + N) = O(N), Space: O(N) (suffix vector)
        vector<int> result, suffix;
        int len = nums.size();
        int prevSum = 1;
        for (auto iter = nums.rbegin(); iter != nums.rend(); iter++) {
            prevSum *= *iter;
            suffix.push_back(prevSum);
        }
        
        result.push_back(suffix[(len-1)-1]); // answer[0]
        for (int i = 1; i < len; i++) {
            nums[i] *= nums[i-1]; // prefix sum
            if (i == len - 1) {
                result.push_back(nums[i-1]);
            } else {
                // (len-1) - i -> suffixSum to current num
                result.push_back(nums[i-1] * suffix[(len-1)-i-1]);
            }
        }
        return result;
    }
};
// @lc code=end

