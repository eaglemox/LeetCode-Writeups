/*
 * @lc app=leetcode id=75 lang=c
 *
 * [75] Sort Colors
 */

// @lc code=start
void sortColors(int* nums, int numsSize) {
    // Counting the frequency of each color, reconstruct the array
    int count[3] = {0};
    for (int i = 0; i < numsSize; i++) {
        count[nums[i]]++;
    }
    for (int i = 0, j = 0; i < 3; i++) {
        while (count[i]--) {
            nums[j++] = i;
        }
    }
}
// @lc code=end

