/*
 * @lc app=leetcode id=1931 lang=c
 *
 * [1931] Painting a Grid With Three Different Colors
 */

// @lc code=start
#define MOD 1000000007
int dp[1001][1024] = {};

int dfs(int m, int n, int i, int j, int cur, int prev) {
    // cur : the color bitmask of current column, e.g. 0b Row4 Row3 Row2 Row1 Row0
    // prev: the color bitmask of previous column
    if (j == n) { // find 1 valid way to paint the grid
        return 1;
    }
    if (i == m) {
        return dfs(m, n, 0, j + 1, 0, cur);
    }
    if (i == 0 && dp[j][prev]) { // if visited before
        return dp[j][prev];
    }

    // take the lower 2 bits of the mask
    int res = 0, left = (prev >> (i * 2)) & 3,
        up = (i == 0) ? 0 : (cur >> ((i - 1) * 2)) & 3;
    for (int color = 1; color <= 3; color++) {
        if (color != left && color != up) { // different color from adjacent cells
            res = (res + dfs(m, n, i + 1, j, cur + (color << (i * 2)), prev)) % MOD;
        }
    }
    if (i == 0) { // memo 
        dp[j][prev] = res;
    }
    return res;
}

int colorTheGrid(int m, int n) {
    memset(dp, 0, sizeof(dp));
    return dfs(m, n, 0, 0, 0, 0);
}
// @lc code=end

