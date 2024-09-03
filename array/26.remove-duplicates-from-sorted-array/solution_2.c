/*
 * @lc app=leetcode id=26 lang=c
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 1) {return 1;}
    int count = 0; // unique numbers
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[count]) {
            nums[++count] = nums[i];
        }
    }
    return count + 1; // add initial
}
// @lc code=end

