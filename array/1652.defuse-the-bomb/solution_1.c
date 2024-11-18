/*
 * @lc app=leetcode id=1652 lang=c
 *
 * [1652] Defuse the Bomb
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int* decrypt(int* code, int codeSize, int k, int* returnSize) {
    // Brute force, decrypt each code
    // Time: O(Nk), Space: O(N), N: codeSize, k: value of k
    *returnSize = codeSize;
    int *result = malloc(*returnSize * sizeof(int));
    for (int i = 0; i < *returnSize; i++) {
        result[i] = 0;
    }
    if (k == 0) {return result;} // return 0 array
    for (int i = 0; i < codeSize; i++) {
        int step = (k > 0) ? 1 : -1;
        for (int j = step; (k > 0) ? j <= k : j >= k; j += step) {
            // ensure positive index
            int index = ((i + j) % codeSize + codeSize) % codeSize;
            result[i] += code[index];
        }
    }
    
    return result;
}
// @lc code=end

