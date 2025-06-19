/*
 * @lc app=leetcode id=2294 lang=c
 *
 * [2294] Partition Array Such That Maximum Difference Is K
 */

// @lc code=start
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int partitionArray(int* nums, int numsSize, int k) {
    // Sort the array then greedily divide elements into subsequence with difference no more than k
    qsort(nums, numsSize, sizeof(int), cmp);
    int result = 1;
    int min = nums[0];

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] - min > k) {
            min = nums[i];
            result++;
        }
    }

    return result;
}
// @lc code=end

