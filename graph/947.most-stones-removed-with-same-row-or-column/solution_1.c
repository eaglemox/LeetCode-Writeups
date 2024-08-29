/*
 * @lc app=leetcode id=947 lang=c
 *
 * [947] Most Stones Removed with Same Row or Column
 */

// @lc code=start
void dfs(int **stones, int stonesSize, int *visited, int stoneIndex) {
    visited[stoneIndex] = 1;
    for (int j = 0; j < stonesSize; j++) {
        if (!visited[j] && (stones[stoneIndex][0] == stones[j][0] || stones[stoneIndex][1] == stones[j][1])) {
            dfs(stones, stonesSize, visited, j);
        }
    }
}
int removeStones(int **stones, int stonesSize, int *stonesColSize) {
    /*  if the stones are connect by N connected components,
        stones can be removed until N stones are left.
        removable = stones - N
    */
    int *visited = (int *)calloc(stonesSize, sizeof(int));
    int component = 0;
    for (int i = 0; i < stonesSize; i++) {
        if (!visited[i]) {
            dfs(stones, stonesSize, visited, i);
            component++;
        }
    }
    free(visited);
    return stonesSize - component;
}
// @lc code=end
