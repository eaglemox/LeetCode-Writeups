/*
 * @lc app=leetcode id=2032 lang=c
 *
 * [2032] Two Out of Three
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdbool.h>
#define MAX_VAL 100

int* twoOutOfThree(int* nums1, int nums1Size, int* nums2, int nums2Size, int* nums3, int nums3Size, int* returnSize) {
    // Record each value's appearance in each nums
    // Time: O(M+N), Space: O(M), M: range of num's value, N: max size of nums
    bool map[3][MAX_VAL+1] = {0};
    int *result = malloc(MAX_VAL * sizeof(int));
    for (int i = 0; i < nums1Size; i++) {
        map[0][nums1[i]] = true;
    }
    for (int i = 0; i < nums2Size; i++) {
        map[1][nums2[i]] = true;
    }
    for (int i = 0; i < nums3Size; i++) {
        map[2][nums3[i]] = true;
    }

    *returnSize = 0;
    for (int i = 1; i <= MAX_VAL; i++) {
        if (map[0][i] + map[1][i] + map[2][i] > 1) {
            result[(*returnSize)++] = i;
        }
    }
    return result;
}
// @lc code=end