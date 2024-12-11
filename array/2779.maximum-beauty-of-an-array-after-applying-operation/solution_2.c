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
    // Optimize the finding process, utilizing the constraint that the array is sorted
    // If previous nums[i] - nums[left] > 2k, nums[i+1] - nums[left] also > 2k
    // Time: O(NlogN), Space: O(1)
    qsort(nums, numsSize, sizeof(int), cmp);
    int maxLength = 0, left = 0;
    for (int i = 0; i < numsSize; i++) {
        while (nums[i] - nums[left] > 2 * k) {
            left++;
        }
        maxLength = max(maxLength, i - left + 1);
    }
    return maxLength;
}
// @lc code=end

