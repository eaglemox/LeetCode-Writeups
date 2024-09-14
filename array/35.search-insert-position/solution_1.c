/*
 * @lc app=leetcode id=35 lang=c
 *
 * [35] Search Insert Position
 */

// @lc code=start
// #include <stdio.h>
int searchInsert(int* nums, int numsSize, int target) {
    // Performs binary search
    int l = 0, r = numsSize - 1;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        // printf("boundary: [%d-%d-%d]\n", l, mid, r);
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            l = mid + 1;
        } else if (nums[mid] > target) {
            r = mid - 1;
        }
    }
    return l;
}
// @lc code=end

