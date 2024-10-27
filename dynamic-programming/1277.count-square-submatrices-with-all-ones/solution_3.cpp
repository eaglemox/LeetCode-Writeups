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
        // Top-down DP apporach, Optimize DP talbe space
        // Time: O(M*N), Space: O(M*N)
        int m = matrix.size(), n = matrix[0].size();
        vector<int> dp(n); // record squareCount of last and current row (dp[i-1][j:] & dp[i][:j]) 
        int count = 0, diag = 0; // previous diagonal squareCount: dp[i-1][j-1]
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int tmp = dp[j]; // save for next diag
                // dp[j] should be 0, don't count
                if (matrix[i][j] == 0) {
                    dp[j] = 0;
                    continue;
                }
                // element = 1
                if (i == 0 || j == 0) { // first row / column
                    dp[j] = 1;
                } else {
                    dp[j] = 1 + min(diag, min(dp[j], dp[j-1]));
                }
                count += dp[j];
                diag = tmp; // update diag
            }
        }
        return count;
    }
};
// @lc code=end

