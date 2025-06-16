/*
 * @lc app=leetcode id=2016 lang=c
 *
 * [2016] Maximum Difference Between Increasing Elements
 */

// @lc code=start
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int maximumDifference(int* nums, int numsSize) {
    int leftMin = nums[0], result = -1;

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > leftMin) {
            result = max(result, nums[i] - leftMin);
        }
        leftMin = min(leftMin, nums[i]);
    }

    return result;
}
// @lc code=end

