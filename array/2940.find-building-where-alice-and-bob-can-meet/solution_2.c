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
#define max(a, b) ((a > b) ? a : b)

int* leftmostBuildingQueries(int* heights, int heightsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    // Binary search and sparse table
    // Time: O(QlogN), Space: O(N), Q: queriesSize, N: heightsSize
    int st[heightsSize][20];
    int log[heightsSize+1];
    log[0] = -1;
    for (int i = 1; i <= heightsSize; i++) {
        log[i] = log[i >> 1] + 1;
    }
    for (int i = 0; i < heightsSize; i++) {
        st[i][0] = heights[i];
    }
    for (int i = 1; i < 20; i++) {
        for (int j = 0; j + (1 << i) <= heightsSize; j++) {
            st[j][i]  = max(st[j][i-1], st[j+(1<<(i-1))][i-1]);
        }
    }

    *returnSize = queriesSize;
    int *result = malloc(*returnSize * sizeof(int));
    for (int i = 0; i < queriesSize; i++) {
        int l = queries[i][0], r = queries[i][1];
        if (l > r) {
            l = queries[i][1];
            r = queries[i][0];
        }
        if (l == r || heights[l] < heights[r]) {
            result[i] = r;
        } else { // move to building t that a, b < t && heights[a], heights[b] < heights[t]
            int maxQueryHeight = max(heights[l], heights[r]);
            int left = r + 1, right = heightsSize, mid;
            while (left < right) {
                mid = (left + right) / 2;
                int range = mid - (r + 1) + 1, k = log[range];
                int maxHeight = max(st[r+1][k], st[mid-(1<<k)+1][k]);
                if (maxHeight > maxQueryHeight) {
                    right = mid; // lowerbound at LHS
                } else {
                    left = mid + 1;
                }
            }
            result[i] = (left == heightsSize) ? -1 : left;
        }
    }

    return result;
}
// @lc code=end

