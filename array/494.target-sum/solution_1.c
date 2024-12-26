/*
 * @lc app=leetcode id=494 lang=c
 *
 * [494] Target Sum
 */

// @lc code=start
int backTracking(int* nums, int numsSize, int target, int index) {
    if (target == 0 && index == numsSize) {return 1;} // reach end and the sum equals to target  
    if (index >= numsSize) {return 0;}
    return backTracking(nums, numsSize, target + nums[index], index + 1) + 
           backTracking(nums, numsSize, target - nums[index], index + 1);
}

int findTargetSumWays(int* nums, int numsSize, int target) {
    // Back tracking to enumerate all possible combinations, count the expressions that sum eqauls to the target
    // Time: O(2^N), Space: O(1), N: numsSize
    return backTracking(nums, numsSize, target, 0);
}
// @lc code=end

