/*
 * @lc app=leetcode id=3011 lang=c
 *
 * [3011] Find if Array Can Be Sorted
 */

// @lc code=start
#include <stdbool.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

bool canSortArray(int* nums, int numsSize) {
    // Check if sorting the array is possible
    // Time: O(N^2), Space: O(1)
    // Bubble sort
    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < numsSize - i - 1; j++) {
            if (nums[j] <= nums[j+1]) {continue;}
            // require swap 
            if (__builtin_popcount(nums[j]) \
                != __builtin_popcount(nums[j+1])) {return false;}
            swap(&nums[j], &nums[j+1]);
        }
    }
    return true;
}
// @lc code=end