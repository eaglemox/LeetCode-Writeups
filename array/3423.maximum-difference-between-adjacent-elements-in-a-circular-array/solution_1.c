/*
 * @lc app=leetcode id=3423 lang=c
 *
 * [3423] Maximum Difference Between Adjacent Elements in a Circular Array
 */

// @lc code=start
#define max(a, b) (((a) > (b)) ? (a) : (b))

int maxAdjacentDistance(int* nums, int numsSize) {
    int result = 0;
    for (int i = 0; i < numsSize; i++) {
        int next = (i + 1) % numsSize;
        result = max(result, ((nums[i] > nums[next]) ? nums[i] - nums[next] : nums[next] - nums[i]));
    }

    return result;
}
// @lc code=end

