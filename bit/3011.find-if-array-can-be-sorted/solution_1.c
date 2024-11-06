/*
 * @lc app=leetcode id=3011 lang=c
 *
 * [3011] Find if Array Can Be Sorted
 */

// @lc code=start
#include <stdbool.h>
#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)

bool canSortArray(int* nums, int numsSize) {
    // Only adjacent number of same #setbits can be swap,
    // check if array can be sorted in 'ascending' order
    // Time: O(N), Space: O(1)
    int prevMax = -1; // first same bit part does not count
    for (int i = 0; i < numsSize;) {
        int currMax = nums[i], currMin = nums[i];
        int bits = __builtin_popcount(nums[i++]);
        while (i < numsSize && __builtin_popcount(nums[i]) == bits) {
            currMax = max(currMax, nums[i]);
            currMin = min(currMin, nums[i]);
            i++;
        }
        if (prevMax != -1 && prevMax > currMin) {return false;}
        prevMax = currMax;
    }
    return true;
}
// @lc code=end