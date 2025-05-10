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
        // Time: O(max(num1.length, num2.length)), Space: O(1)
        int n = nums1.size(), m = nums2.size();
        int zeros1 = 0, zeros2 = 0;
        long long sum1 = 0, sum2 = 0;

        for (int i = 0; i < max(n, m); i++) {
            if (i < n) {
                sum1 += nums1[i];
                zeros1 += nums1[i] == 0;
            }
            if (i < m) {
                sum2 += nums2[i];
                zeros2 += nums2[i] == 0;
            }
        }
        
        sum1 += zeros1;
        sum2 += zeros2;

        if (sum1 < sum2 && zeros1 == 0 || sum1 > sum2 && zeros2 == 0) {
            return -1;
        }
        
        return max(sum1, sum2);
    }
};
// @lc code=end
