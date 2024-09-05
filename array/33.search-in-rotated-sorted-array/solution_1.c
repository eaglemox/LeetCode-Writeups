/*
 * @lc app=leetcode id=33 lang=c
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
#include <stdio.h>
int search(int* nums, int numsSize, int target) {
    int l = 0, r = numsSize - 1;
    int mid;
    // binary search to find pivot location
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (l == r) {break;} // found
        if (nums[mid] < nums[0]) { // decreased (after pivot)
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    int pivot = mid;
    printf("pivot: %d\n", pivot);
    // extreme condition: [1], [1, 0]
    if (target >= nums[mid] && target <= nums[numsSize-1]) { // subarray after pivot 
        l = pivot;
        r = numsSize - 1;
    } else {
        l = 0;
        r = pivot - 1;
    }
    printf("left: %d, right: %d\n", l, r);
    // binary search to find target location
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (target == nums[mid]) {return mid;}
        else if (target > nums[mid]) {
            l = mid + 1;
        } else if (target < nums[mid]) {
            r = mid - 1;
        }
    }
    // not in nums
    return -1;
}
// @lc code=end

