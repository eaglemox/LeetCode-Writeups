/*
 * @lc app=leetcode id=2595 lang=c
 *
 * [2595] Number of Even and Odd Bits
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* evenOddBit(int n, int* returnSize) {
    // Count number of set bits on odd and even indices respectively
    // Initialize return array
    *returnSize = 2;
    int *result = malloc(*returnSize * sizeof(int));
    memset(result, 0, 2 * sizeof(int));
    
    for (int i = 0; n; i++) {
        if (n & 1) { // if set bit
            result[i&1]++; // add to corresponding count
        }
        n >>= 1;
    }
    
    return result;
}
// @lc code=end

