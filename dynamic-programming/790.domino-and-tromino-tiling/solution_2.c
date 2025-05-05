/*
 * @lc app=leetcode id=790 lang=c
 *
 * [790] Domino and Tromino Tiling
 */

// @lc code=start
#define MOD 1000000007

int tilings[1001] = {1, 1, 2}; // 0~1000

int numTilings(int n) {
    // Optimized from recursive to iterative bottom up DP
    // A[N] = 2 * A[N-1] + A[N-3]
    for (int i = 3; i <= n; i++) {
        tilings[i] = ((2LL * tilings[i-1]) % MOD + tilings[i-3]) % MOD;
    }
    return tilings[n];
}

// @lc code=end

