/*
 * @lc app=leetcode id=2257 lang=c
 *
 * [2257] Count Unguarded Cells in the Grid
 */

// @lc code=start
#include <stdlib.h>

int countUnguarded(int m, int n, int** guards, int guardsSize, int* guardsColSize, int** walls, int wallsSize, int* wallsColSize) {
    // Mark guarded cells by iterate through each guard
    // Time: O(M*N+(M+N)*G), Space: O(M*N), G: guardsSize
    int guarded = 0;
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
    // Mark guarded cells
    for (int i = 0; i < guardsSize; i++) {
        int row, col;
        // North
        for (row = guards[i][0] - 1, col = guards[i][1]; row >= 0; row--) {
            if (grid[row][col] < 0) {break;} // reach wall or guard
            if (grid[row][col] == 0) {guarded++;}
            grid[row][col] = 1;
        }
        // East
        for (row = guards[i][0], col = guards[i][1] + 1; col < n; col++) {
            if (grid[row][col] < 0) {break;} // reach wall or guard
            if (grid[row][col] == 0) {guarded++;}
            grid[row][col] = 1;
        }
        // South
        for (row = guards[i][0] + 1, col = guards[i][1]; row < m; row++) {
            if (grid[row][col] < 0) {break;} // reach wall or guard
            if (grid[row][col] == 0) {guarded++;}
            grid[row][col] = 1;
        }
        // West
        for (row = guards[i][0], col = guards[i][1] - 1; col >= 0; col--) {
            if (grid[row][col] < 0) {break;} // reach wall or guard
            if (grid[row][col] == 0) {guarded++;}
            grid[row][col] = 1;
        }
    }
    
    return m * n - guardsSize - wallsSize - guarded;
}
// @lc code=end

