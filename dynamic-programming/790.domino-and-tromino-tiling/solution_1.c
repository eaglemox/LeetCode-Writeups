/*
 * @lc app=leetcode id=790 lang=c
 *
 * [790] Domino and Tromino Tiling
 */

// @lc code=start
#define MOD 1000000007

static int tilings[1001] = {0}; // 0~1000

int numTilings(int n) {
    // Create a list to save previous tiling methods
    // The difficult part is finding the rule
    // A[N] = 2 * A[N-1] + A[N-3]
    if (tilings[n]) {return tilings[n];}
    if (n == 0) {
        tilings[n] = 1;
    } else if (n == 1) {
        tilings[n] = 1;
    } else if (n == 2) {
        tilings[n] = 2;
    } else { // n >= 3
        tilings[n] = 2 * numTilings(n-1) + numTilings(n-3);
    }
    return tilings[n] %= MOD;
}

// @lc code=end

