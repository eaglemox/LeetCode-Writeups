/*
 * @lc app=leetcode id=3097 lang=c
 *
 * [3097] Shortest Subarray With OR at Least K II
 */

// @lc code=start
int minimumSubarrayLength(int* nums, int numsSize, int k) {
    // Return length of least subarray of nums that its OR is no less than k
    // Brute force -> TLE, Time: O(NL^2), Space: O(1)
    int orSum = 0;
    for (int i = 1; i <= numsSize; i++) {
        for (int j = 0; j < numsSize - i + 1; j++) {
            for (int idx = j, orSum = 0; idx < j + i; idx++) {
                orSum |= nums[idx];
                if (orSum >= k) {return i;}
            }
        }
    }
    return -1;
}
// @lc code=end

