/*
 * @lc app=leetcode id=494 lang=c
 *
 * [494] Target Sum
 */

// @lc code=start
void backTracking(int* nums, int numsSize, int target, int index, int sum, int* expressions) {
    if (index < numsSize) {
        sum += nums[index];
        backTracking(nums, numsSize, target, index + 1, sum, expressions);
        sum -= 2 * nums[index];
        backTracking(nums, numsSize, target, index + 1, sum, expressions);
    } else if (sum == target) { // at the end of array and sum eqauls to the target
        (*expressions)++;
    }
}

int findTargetSumWays(int* nums, int numsSize, int target) {
    // Back tracking to enumerate all possible combinations, count the expressions that sum eqauls to the target
    // Time: O(2^N), Space: O(1), N: numsSize
    int result = 0;
    backTracking(nums, numsSize, target, 0, 0, &result);
    return result;
}
// @lc code=end

