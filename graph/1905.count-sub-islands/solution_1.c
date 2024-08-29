/*
 * @lc app=leetcode id=1905 lang=c
 *
 * [1905] Count Sub Islands
 */

// @lc code=start
void DFS(int** grid1, int** grid2, int** grid2Labels, bool* isSubIsland, int x, int y, int rows, int cols, int label) {
    if (x < 0 || y < 0 || x >= rows || y >= cols || grid2[x][y] == 0 || grid2Labels[x][y] != 0) {
        return;
    }
    grid2Labels[x][y] = label;
    if (grid1[x][y] == 0) {
        *isSubIsland = false;
    }
    DFS(grid1, grid2, grid2Labels, isSubIsland, x-1, y, rows, cols, label);
    DFS(grid1, grid2, grid2Labels, isSubIsland, x+1, y, rows, cols, label);
    DFS(grid1, grid2, grid2Labels, isSubIsland, x, y-1, rows, cols, label);
    DFS(grid1, grid2, grid2Labels, isSubIsland, x, y+1, rows, cols, label);
}
int countSubIslands(int** grid1, int grid1Size, int* grid1ColSize, int** grid2,
                    int grid2Size, int* grid2ColSize) {
    int label = 1;
    int subIslandCount = 0;
    // malloc matrix for tracking different sub-islands
    int** grid2Labels = malloc(grid2Size * sizeof(int*));
    for (int i = 0; i < grid2Size; i++){
        grid2Labels[i] = malloc(grid2ColSize[i] * sizeof(int));
    }
    for (int i = 0; i < grid2Size; i++){
        for (int j = 0; j < grid2ColSize[i]; j++){
            grid2Labels[i][j] = 0; // initialization
        }
    }
    // search sub-islands
    for (int i = 0; i < grid2Size; i++){
        for (int j = 0; j < grid2ColSize[i]; j++){
            // is '1' and not labeled
            if (grid2[i][j] == 1 && grid2Labels[i][j] == 0){
                printf("entered: %d,%d\n", i, j);
                bool isSubIsland = true;
                DFS(grid1, grid2, grid2Labels, &isSubIsland, i, j, grid2Size, grid2ColSize[i], label);
                if (isSubIsland) {
                    subIslandCount++;
                    label++;
                }
            }
        }
    }
     for (int i = 0; i < grid2Size; i++){
        for (int j = 0; j < grid2ColSize[i]; j++){
            printf("%d ", grid2Labels[i][j]);
        }printf("\n");
    }
    for (int i = 0; i < grid2Size; i++){
        free(grid2Labels[i]);
    }
    free(grid2Labels);
    return subIslandCount;
}
// @lc code=end

