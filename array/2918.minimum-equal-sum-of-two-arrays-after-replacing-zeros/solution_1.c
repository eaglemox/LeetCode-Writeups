/*
 * @lc app=leetcode id=2918 lang=c
 *
 * [2918] Minimum Equal Sum of Two Arrays After Replacing Zeros
 */

// @lc code=start
#define max(a, b) ((a > b) ? a : b)

long long minSum(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    // All '0' must be replace with strictly positive integer [1, INF]
    // minimum sum of each num must at least sum + #zeros
    // Time: O(max(num1.length, num2.length)), Space: O(1)
    int zeros1 = 0, zeros2 = 0;
    long long sum1 = 0, sum2 = 0;
    for (int i = 0; i < max(nums1Size, nums2Size); i++) {
        if (i < nums1Size) {
            zeros1 += (nums1[i] == 0);
            sum1 += nums1[i];
        }
        if (i < nums2Size) {
            zeros2 += (nums2[i] == 0);
            sum1 += nums2[i];
        }
    }

    sum1 += zeros1;
    sum2 += zeros2;

    if (sum1 < sum2 && zeros1 == 0 || sum1 > sum2 && zeros2 == 0) {
        return -1;
    }

    return max(sum1, sum2);
}
// @lc code=end
