/*
 * @lc app=leetcode id=2859 lang=c
 *
 * [2859] Sum of Values at Indices With K Set Bits
 */

// @lc code=start
#include <stdlib.h>

int sumIndicesWithKSetBits(int* nums, int numsSize, int k) {
    // Checking right shife bits count
    // Time: O(N), Space: O(N)
    int sum = 0;
    int *setBits = malloc(numsSize * sizeof(int));
    setBits[0] = 0;
    for (int i = 0; i < numsSize; i++) { // k == 0 -> only index == 0
        setBits[i] = setBits[(i >> 1)] + (i & 1);
        if (setBits[i] == k) {
            sum += nums[i];
        }
    }
    free(setBits);
    return sum;
}
// @lc code=end

