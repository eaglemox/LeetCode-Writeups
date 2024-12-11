/*
 * @lc app=leetcode id=2779 lang=c
 *
 * [2779] Maximum Beauty of an Array After Applying Operation
 */

// @lc code=start
#include <stdlib.h>
#define max(a, b) ((a > b) ? a : b)

int cmp(const void* a, const void* b) {
    return *(int *)a - *(int *)b;
}

int maximumBeauty(int* nums, int numsSize, int k) {
    // Follow the hint, sort then find max subarray
    // Time: O(NlogN), Space: O(1)
    qsort(nums, numsSize, sizeof(int), cmp);
    int maxLength = 0;
    for (int i = 0; i < numsSize; i++) {
        int left = i, right = numsSize - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] - nums[i] <= 2 * k) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        maxLength = max(maxLength, right - i + 1);
    }
    return maxLength;
}
// @lc code=end

