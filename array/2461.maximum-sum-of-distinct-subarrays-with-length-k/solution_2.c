/*
 * @lc app=leetcode id=2461 lang=c
 *
 * [2461] Maximum Sum of Distinct Subarrays With Length K
 */

// @lc code=start
#define max(a, b) ((a > b) ? a : b)
#define MAX_VAL 100000

long long maximumSubarraySum(int* nums, int numsSize, int k) {
    // Brute force checking all sliding windows -> TLE
    // Time: O(Nk), Space: O(1)
    int unique;
    long long sum = 0, maxSum = 0;

    for (int i = 0; i <= numsSize - k; i++) {
        int count[MAX_VAL+1] = {0};
        sum = 0;
        unique = 0;
        for (int j = i; j < i + k; j++) {
            sum += nums[j];
            count[nums[j]]++;
            if (count[nums[j]] == 2) {
                break;
            }
            unique++;
        }
        if (unique == k) {
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum;
}
// @lc code=end

