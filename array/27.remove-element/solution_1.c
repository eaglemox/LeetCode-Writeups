/*
 * @lc app=leetcode id=27 lang=c
 *
 * [27] Remove Element
 */

// @lc code=start
int removeElement(int* nums, int numsSize, int val) {
    // Use a pointer (index) to search number not equal to val, replace it to the front
    // Time: O(N), Space: O(1)
    int index = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[index] = nums[i];
        }
    }
    return index;
}
// @lc code=end

