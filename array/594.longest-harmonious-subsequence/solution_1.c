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
    for (int i = 1, prevLength = 0, currLength = 1; i < numsSize; i++) {
        if (nums[i] > nums[i-1] + 1) {
            currLength = 1;
            prevLength = 0;
        } else {
            if (nums[i] == nums[i-1]) {
                currLength++;
            } else if (nums[i] == nums[i-1] + 1) {
                prevLength = currLength;
                currLength = 1;
            }
            if (prevLength > 0 && prevLength + currLength > result) {
                result = prevLength + currLength;
            }
        }
    }

    return result;
}
// @lc code=end

