/*
 * @lc app=leetcode id=2684 lang=cpp
 *
 * [2684] Maximum Number of Moves in a Grid
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        // Only move left to right next cell must bigger, max = #col - 1
        // Backward counting, Time: O(M*N), Space: O(M*N)
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        // last column
        for (int i = 0; i < m; i++) {
            dp[i][n-1] = 0;
        }
        int maxMoves = 0;
        // Compute #move of lefthand side cell
        for (int j = n - 2; j >= 0; j--) {
            for (int i = 0; i < m; i++) {
                // #move of current cell = 1 + #move of possible path
                if (grid[i][j] < grid[i][j+1]) {
                    dp[i][j] = max(dp[i][j], 1 + dp[i][j+1]);
                }
                if (i > 0 && grid[i][j] < grid[i-1][j+1]) {
                    dp[i][j] = max(dp[i][j], 1 + dp[i-1][j+1]);
                }
                if (i < m - 1 && grid[i][j] < grid[i+1][j+1]) {
                    dp[i][j] = max(dp[i][j], 1 + dp[i+1][j+1]);
                }
                if (j == 0) { // must start at first column
                    maxMoves = max(maxMoves, dp[i][0]);
                }
            }
        }
        return maxMoves;
    }
};
// @lc code=end

