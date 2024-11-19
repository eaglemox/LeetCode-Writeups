/*
 * @lc app=leetcode id=2461 lang=c
 *
 * [2461] Maximum Sum of Distinct Subarrays With Length K
 */

// @lc code=start
#define max(a, b) ((a > b) ? a : b)
#define MAX_VAL 100000

long long maximumSubarraySum(int* nums, int numsSize, int k) {
    // nums are all positive and with range of [1, 1e5]
    // Using a map and sliding window to track the sum and frequncy of number
    // Time: O(N), Space: O(1)
    int count[MAX_VAL+1] = {0};
    int unique = 0;
    long long sum = 0, maxSum = 0;

    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        int freq = ++count[nums[i]];
        // 0 -> 1: add one, 1 -> 2+ ->: minus one, 2+ -> 3+: ignore
        unique += (freq == 1) ? 1 : (freq == 2) ? -1 : 0;
        if (i >= k) {
            sum -= nums[i-k];
            freq = --count[nums[i-k]];
            // 2+ -> 1: add one, 1 -> 0: minus one, 3+ -> 2+: ignore
            unique += (freq == 1) ? 1 : (freq == 0) ? -1 : 0;
        }
        if (unique == k) {
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum;
}
// @lc code=end

