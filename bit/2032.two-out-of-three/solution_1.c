/*
 * @lc app=leetcode id=2032 lang=c
 *
 * [2032] Two Out of Three
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#define MAX_VAL 100
#define max(a, b) ((a > b) ? a : b)

int* twoOutOfThree(int* nums1, int nums1Size, int* nums2, int nums2Size, int* nums3, int nums3Size, int* returnSize) {
    // Record each value's appearance in each nums
    // Time: O(M+N), Space: O(M), M: range of num's value, N: max size of nums
    int map[MAX_VAL+1] = {0};
    int *result = malloc(MAX_VAL * sizeof(int));
    int maxLength = max(nums1Size, max(nums2Size, nums3Size));
    for (int i = 0; i < maxLength; i++) {
        if (i < nums1Size) {
            map[nums1[i]] |= 1; // 0b001
        }
        if (i < nums2Size) {
            map[nums2[i]] |= 2; // 0b010
        }
        if (i < nums3Size) {
            map[nums3[i]] |= 4; // 0b100
        }
    }

    *returnSize = 0;
    for (int i = 1; i <= MAX_VAL; i++) {
        if (map[i] <= 2 || map[i] == 4) {
            // appeared once: 1, 2, 4
            continue;
        }
        result[(*returnSize)++] = i;
    }
    return result;
}
// @lc code=end

