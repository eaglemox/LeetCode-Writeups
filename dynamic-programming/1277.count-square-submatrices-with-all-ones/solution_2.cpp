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
        vector<vector<int>> dp(m, vector<int>(n));
        int count = 0;
        // First row & column 
        for (int i = 0; i < m; i++) {
            count += dp[i][0] = matrix[i][0];;
        }
        for (int j = 1; j < n; j++) {
            count += dp[0][j] = matrix[0][j];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {continue;} // dp[i][j] should be 0, don't count
                dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                count += dp[i][j];
            }
        }
        return count;
    }
};
// @lc code=end

