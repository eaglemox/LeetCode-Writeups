/*
 * @lc app=leetcode id=2657 lang=c
 *
 * [2657] Find the Prefix Common Array of Two Arrays
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <string.h>

int* findThePrefixCommonArray(int* A, int ASize, int* B, int BSize, int* returnSize) {
    // A and B are permutation of N integers 1~N, counting the prefix frequency of each number
    // Time: O(N), Space: O(N), N: ASize == BSize
    int freq[ASize+1];
    memset(freq, 0, sizeof(freq));
    *returnSize = 0;
    int *result = malloc(ASize * sizeof(int));
    for (int i = 0, count = 0; i < ASize; i++) {
        if (++freq[A[i]] == 2) {
            count++;
        }
        if (++freq[B[i]] == 2) {
            count++;
        }
        result[(*returnSize)++] = count;
    }
    return result;
}
// @lc code=end

