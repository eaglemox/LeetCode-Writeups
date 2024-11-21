/*
 * @lc app=leetcode id=2257 lang=c
 *
 * [2257] Count Unguarded Cells in the Grid
 */

// @lc code=start
#include <stdlib.h>
#include <stdbool.h>

int countUnguarded(int m, int n, int** guards, int guardsSize, int* guardsColSize, int** walls, int wallsSize, int* wallsColSize) {
    // Line scan the guarded cells, sweep two side bc the guarded cells have the OR logic
    // Time: O(M*N), Space: O(M*N)
    int **grid = malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        grid[i] = malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            grid[i][j] = 0; // unguarded
        }
    }
    // Mark walls on the grid as -1
    for (int i = 0; i < wallsSize; i++) {
        grid[walls[i][0]][walls[i][1]] = -1;
    }
    // Mark guards on the grid as -2
    for (int i = 0; i < guardsSize; i++) {
        grid[guards[i][0]][guards[i][1]] = -2;
    }
    // Horizontal scan
    for (int row = 0; row < m; row++) {
        bool isGuarded = grid[row][0] == -2;
        for (int col = 1; col < n; col++) {
            int cell = grid[row][col];
            if (cell == -1) {
                isGuarded = false;
            } else if (cell == -2) {
                isGuarded = true;
            } else if (isGuarded) {
                grid[row][col] = 1;
            }
        }
        isGuarded = grid[row][n-1] == -2;
        for (int col = n - 2; col >= 0; col--) {
            int cell = grid[row][col];
            if (cell == -1) {
                isGuarded = false;
            } else if (cell == -2) {
                isGuarded = true;
            } else if (isGuarded) {
                grid[row][col] = 1;
            }
        }
    }
    for (int col = 0; col < n; col++) {
        bool isGuarded = grid[0][col] == -2;
        for (int row = 0; row < m; row++) {
            int cell = grid[row][col];
            if (cell == -1) {
                isGuarded = false;
            } else if (cell == -2) {
                isGuarded = true;
            } else if (isGuarded) {
                grid[row][col] = 1;
            }
        }
        isGuarded = grid[m-1][col] == -2;
        for (int row = m - 2; row >= 0; row--) {
            int cell = grid[row][col];
            if (cell == -1) {
                isGuarded = false;
            } else if (cell == -2) {
                isGuarded = true;
            } else if (isGuarded) {
                grid[row][col] = 1;
            }
        }
    }
    
    int unguarded = 0;
    for (int row = 0; row < m; row++) {
        for (int col = 0; col < n; col++) {
            unguarded += grid[row][col] == 0;
        }
    }
    return unguarded;
}
// @lc code=end

