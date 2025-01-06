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
    // Sum number of operations required for each step in single pass
    // If the target box is at index i, the min operations to move all
    // balls to the box is the moves of balls at the left/right side,
    // We iterate the index i from 0 to len. at each step update the
    // #balls at the left/right side and add the required moves to the result
    // Time: O(N), Space: O(N), N: #boxes
    int len = strlen(boxes);
    
    *returnSize = len;
    int *result = malloc(*returnSize * sizeof(int));
    memset(result, 0, *returnSize * sizeof(int)); // Initialization
    int leftBalls = 0, rightBalls = 0,
        leftMoves = 0, rightMoves = 0;
    for (int i = 0, j; i < len; i++) {
        // Left to right
        result[i] += leftMoves;
        leftBalls += boxes[i] - '0';
        leftMoves += leftBalls; // Increment 1 for each ball
        // Right to left
        j = len - 1 - i;
        result[j] += rightMoves;
        rightBalls += boxes[j] - '0';
        rightMoves += rightBalls;
    }
    return result;
}
// @lc code=end

