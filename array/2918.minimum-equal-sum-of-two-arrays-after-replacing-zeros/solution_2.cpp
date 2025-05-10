/*
 * @lc app=leetcode id=2918 lang=cpp
 *
 * [2918] Minimum Equal Sum of Two Arrays After Replacing Zeros
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        // Time: O(num1.length + num2.length)), Space: O(1)
        int zeros1 = 0, zeros2 = 0;
        bool flag1 = false, flag2 = false; // if any zero found in nums1/num2
        long long sum1 = 0, sum2 = 0;

        for (int &i : nums1) {
            sum1 += i;
            if (i == 0) {
                sum1++;
                flag1 |= 1;
            }
        }
        for (int &j : nums2) {
            sum2 += j;
            if (j == 0) {
                sum2++;
                flag2 |= 1;
            }
        }

        if (sum1 < sum2 && !flag1 || sum1 > sum2 && !flag2) {
            return -1;
        }

        return max(sum1, sum2);
    }
};
// @lc code=end
