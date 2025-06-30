/*
 * @lc app=leetcode id=594 lang=c
 *
 * [594] Longest Harmonious Subsequence
 */

// @lc code=start
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int findLHS(int* nums, int numsSize) {
    // Problem only requires length of the subsequence, the order does not matter
    qsort(nums, numsSize, sizeof(int), cmp);

    int result = 0;
    for (int l = 0, r = 0; r < numsSize; r++) {
        while (nums[r] - nums[l] > 1) {
            l++;
        }
        if (nums[r] - nums[l] == 1) {
            int len = r - l + 1;
            if (len > result) {
                result = len;
            }
        }
    }

    return result;
}
// @lc code=end

