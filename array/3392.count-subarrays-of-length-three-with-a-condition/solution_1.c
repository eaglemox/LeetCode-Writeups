/*
 * @lc app=leetcode id=3392 lang=c
 *
 * [3392] Count Subarrays of Length Three With a Condition
 */

// @lc code=start
int countSubarrays(int* nums, int numsSize) {
    // Using sliding window method to check if every subarrays that 
    // Time: O(N), Space: O(1)
    int count = 0;
    for (int i = 2; i < numsSize; i++) {
        if ((nums[i-2] + nums[i]) * 2 == nums[i-1]) {
            count++;
        }
    }
    return count;
}
// @lc code=end

