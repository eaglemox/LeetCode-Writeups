/*
 * @lc app=leetcode id=2616 lang=c
 *
 * [2616] Minimize the Maximum Difference of Pairs
 */

// @lc code=start
#include <stdlib.h>
#define max(a, b) (((a) > (b)) ? (a) : (b))

int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int minimizeMax(int* nums, int numsSize, int p) {
    // Sort the nums and using binary search to find minimal value that only p pairs meet the value
    qsort(nums, numsSize, sizeof(int), cmp);

    int l = 0, r = nums[numsSize-1] - nums[0]; // Max difference

    while (l < r) {
        int mid = (l + r) / 2, pairs = 0;
        for (int i = 1; i < numsSize; i++) {
            // We can greedily pair the two smallest numbers, as the sorted array guarantees the minimal difference
            if (mid >= nums[i] - nums[i-1]) {
                pairs++;
                i++;
            }
        }

        if (pairs >= p) { // Lower the threshold
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    return l;
}
// @lc code=end

