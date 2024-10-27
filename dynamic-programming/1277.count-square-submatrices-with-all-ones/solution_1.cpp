/*
 * @lc app=leetcode id=1277 lang=cpp
 *
 * [1277] Count Square Submatrices with All Ones
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        // Top-down DP apporach, Time: O(M*N), Space: O(M*N)
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                count += findMaxSqaure(matrix, dp, i, j);
            }
        }
        return count;
    }
private:
    int findMaxSqaure(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j) {
        // base case
        if (i >= matrix.size() || j >= matrix[0].size()) {return 0;}
        if (matrix[i][j] == 0) {return 0;}
        if (dp[i][j] != -1) {return dp[i][j];}

        int right = findMaxSqaure(matrix, dp, i, j + 1);
        int bottom = findMaxSqaure(matrix, dp, i + 1, j);
        int diag = findMaxSqaure(matrix, dp, i + 1, j + 1);

        return dp[i][j] = 1 + min(diag, min(right, bottom));
    }
};
// @lc code=end

