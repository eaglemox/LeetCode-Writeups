/*
 * @lc app=leetcode id=689 lang=c
 *
 * [689] Maximum Sum of 3 Non-Overlapping Subarrays
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <limits.h>

int* maxSumOfThreeSubarrays(int* nums, int numsSize, int k, int* returnSize) {
    // Compute the subarray sums, then DP to pick 3 non-overlapping intervals with max sum
    // Time: O(N), Space: O(N)
    // Compute sum of each subarray
    int subarraysSize = numsSize - (k - 1);
    int subarraySum[subarraysSize];
    for (int i = 0, sum = 0; i < numsSize; i++) {
        sum = (i < k) ? (sum + nums[i]) : (sum - nums[i-k] + nums[i]);
        if (i >= k - 1) {
            subarraySum[i-k+1] = sum;
        }
    }
    
    // maxSum and index for 3 subarrays up to index subarraysSize
    int index[3][subarraysSize], dp[3][subarraysSize];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < subarraysSize; j++) {
            dp[i][j] = INT_MIN; // Initialize to MIN_VAL to mitiage invalid comparisons
        }
    }
    // Max subarraySum for single subarray up to index i
    index[0][0] = 0;
    dp[0][0] = subarraySum[0];
    for (int i = 1; i < subarraysSize; i++) {
        if (subarraySum[i] > dp[0][i-1]) {
            dp[0][i] = subarraySum[i];
            index[0][i] = i;
        } else {
            dp[0][i] = dp[0][i-1];
            index[0][i] = index[0][i-1];
        }
    }
    // Possible maxSum for subarray 2 and 3..
    for (int j = 1; j < 3; j++) {
        // skip first j intervals
        for (int i = k * j; i < subarraysSize; i++) {
            int sum1 = dp[j][i-1];
            int sum2 = dp[j-1][i-k] + subarraySum[i];
            if (sum1 < sum2) {
                dp[j][i] = sum2;
                index[j][i] = i;
            } else { // keep the lesser index when values are equal
                dp[j][i] = sum1;
                index[j][i] = index[j][i-1];
            }
        }
    }

    *returnSize = 3;
    int *result = malloc(3 * sizeof(int));
    result[2] = index[2][subarraysSize-1];
    result[1] = index[1][result[2]-k];
    result[0] = index[0][result[1]-k];
    return result;
}
// @lc code=end

