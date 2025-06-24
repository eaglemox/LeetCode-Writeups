/*
 * @lc app=leetcode id=2200 lang=c
 *
 * [2200] Find All K-Distant Indices in an Array
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#define MAX_SIZE 1001
#define max(a, b) (((a) > (b)) ? (a) : (b))

int* findKDistantIndices(int* nums, int numsSize, int key, int k, int* returnSize) {
    // We iterate the nums to find index i which nums[i] == key, then push index from max(previous i - k, i - k) to min(i + k, numsSize - 1)
    int count = 0;
    int *result = malloc(MAX_SIZE * sizeof(int));
    
    for (int i = 0, j = 0; i < numsSize; i++) {
        if (nums[i] == key) {
            for (j = max(j, i - k); j <= i + k && j < numsSize; j++) {
                result[count++] = j;
            }
        }
    }

    *returnSize = count;

    return result;
}
// @lc code=end

