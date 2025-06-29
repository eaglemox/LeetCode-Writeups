/*
 * @lc app=leetcode id=1498 lang=c
 *
 * [1498] Number of Subsequences That Satisfy the Given Sum Condition
 */

// @lc code=star
#include <stdlib.h>
#define MOD 1000000007

int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int numSubseq(int* nums, int numsSize, int target) {
    // Sort the array then find #subseq that within the range [l, r]
    int count = 0;
    
    // Precompute the possible combinations: 2^N, N is the length of sequence
    int comb[numsSize+1];
    comb[0] = 0, comb[1] = 1;
    for (int i = 2; i <= numsSize; i++) {
        comb[i] = (comb[i-1] << 1) % MOD;
    }

    qsort(nums, numsSize, sizeof(int), cmp);
    int l = 0, r = numsSize - 1;
    while (l <= r) {
        if (nums[l] + nums[r] > target) {
            r--;
        } else {
            count = (count + comb[r-l+1]) % MOD;
            l++;
        }
    }

    return count;
}
// @lc code=end

