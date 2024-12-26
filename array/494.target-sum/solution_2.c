/*
 * @lc app=leetcode id=494 lang=c
 *
 * [494] Target Sum
 */

// @lc code=start
int findTargetSumWays(int* nums, int numsSize, int target) {
    // Back tracking to enumerate all possible combinations, count the expressions that sum eqauls to the target
    // Time: O(N*P), Space: O(P), N: numsSize, P: positiveValue to reach target
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }
    // Impossible to find expression that sum of nums equals to target
    // The target can be split into positiveValue P and negativeValue N
    // P - N = target, P + N = sum
    if (sum < target || (sum + target) % 2) {
        return 0;
    }
    int P = (target + sum) / 2;
    if (P < 0) { // Negative value means all negative expressions cannot reach target
        return 0;
    }
    // Backpack problem: methods of selecting nums to sum up to P
    int dp[P+1]; // [0, P]
    dp[0] = 1; // select no numbers to reach sum = 0
    for (int i = 1; i < P + 1; i++) {
        dp[i] = 0; // initialization
    }
    for (int i = 0; i < numsSize; i++) { // pick nums[i]
        for (int j = P; j >= nums[i]; j--) {
            dp[j] += dp[j - nums[i]];
        }
    }
    return dp[P];
}
// @lc code=end

