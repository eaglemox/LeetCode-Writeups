/*
 * @lc app=leetcode id=2924 lang=c
 *
 * [2924] Find Champion II
 */

// @lc code=start
#include <stdlib.h>

int findChampion(int n, int** edges, int edgesSize, int* edgesColSize) {
    // The edge (u, v) represent u > v, then the champion is the node with no edges pointed to
    // Time: O(M+N), Space: O(N), M: #edges, N: #nodes
    int *inDegree = calloc(n, sizeof(int)); // node range: [0, n-1]
    for (int i = 0; i < edgesSize; i++) {
        inDegree[edges[i][1]]++;
    }
    int champion = -1;
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            // more than one champion
            if (champion != -1) {return -1;}
            champion = i;
        }
    }
    return champion;
}
// @lc code=end

