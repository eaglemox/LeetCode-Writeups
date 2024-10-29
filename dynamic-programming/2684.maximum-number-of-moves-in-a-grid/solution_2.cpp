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
    int m, n;
    int maxMoves(vector<vector<int>>& grid) {
        // Recursive DP, Time: O(M*N), Space: O(M*N)
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int maxMoves = 0;
        for (int i = 0; i < m; i++) {
            maxMoves = max(maxMoves, findMoves(i, 0, 0, grid, dp));
        } 
        return maxMoves - 1;
    }
private: 
    int findMoves(int i, int j, int prev, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (i < 0 || i >= m || j < 0 || j >= n) {return 0;} // base case
        if (grid[i][j] < prev) {return 0;}
        if (dp[i][j] != -1) {return dp[i][j];} // visited

        return dp[i][j] = 1 + max(findMoves(i, j + 1, grid[i][j], grid, dp),\
                              max(findMoves(i-1, j + 1, grid[i][j], grid, dp),\
                                  findMoves(i+1, j + 1, grid[i][j], grid, dp)));
    }
};
// @lc code=end

