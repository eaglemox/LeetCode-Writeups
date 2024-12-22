/*
 * @lc app=leetcode id=2940 lang=c
 *
 * [2940] Find Building Where Alice and Bob Can Meet
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int* leftmostBuildingQueries(int* heights, int heightsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    // They can only move to building with greater index and height, fast query for possible buildings to move is essential
    // Brute force: Time: O(Q*N) -> TLE, Space: O(Q), Q: queriesSize, N: heightsSize
    *returnSize = queriesSize;
    int *result = malloc(*returnSize * sizeof(int));
    for (int i = 0; i < queriesSize; i++) {
        int l, r;
        if (queries[i][0] < queries[i][1]) {
            l = queries[i][0], r = queries[i][1];
        } else {
            l = queries[i][1], r = queries[i][0];
        }
        // Possible conditions
        result[i] = -1; // base case
        // same index or l can move to r
        if (l == r || heights[l] < heights[r]) {
            result[i] = r;
        } else { // l and r move to leftmost common higher building
            for (int j = r + 1; j < heightsSize; j++) {
                if (heights[l] < heights[j] && heights[r] < heights[j]) {
                    result[i] = j;
                    break;
                }
            }
        }
    }

    return result;
}
// @lc code=end

