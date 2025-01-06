/*
 * @lc app=leetcode id=1769 lang=c
 *
 * [1769] Minimum Number of Operations to Move All Balls to Each Box
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <string.h>

int* minOperations(char* boxes, int* returnSize) {
    // Min operations: sum of index differences of each balls to the i-th box
    // Time: O(N^2), Space: O(N), N: #boxes
    int len = strlen(boxes);
    *returnSize = len;
    int *result = malloc(*returnSize * sizeof(int));
    
    for (int i = 0; i < len; i++) {
        int operations = 0;
        for (int j = 0; j < len; j++) {
            if (boxes[j] == '1') {
                operations += (i < j) ? j - i : i - j; // abs(i - j)
            }
        }
        result[i] = operations;
    }
    return result;
}
// @lc code=end

