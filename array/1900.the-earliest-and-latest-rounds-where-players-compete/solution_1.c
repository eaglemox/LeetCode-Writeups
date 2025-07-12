/*
 * @lc app=leetcode id=1900 lang=c
 *
 * [1900] The Earliest and Latest Rounds Where Players Compete
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

// Due to n is within range [2, 28], firstPlayer and secondPlayer can compete at upto 5-th round (2^5 = 32)
int minRound, maxRound;
bool dp[6][28][29] = {};

void dfs(int round, int n, int l, int r) {
    if (dp[round][l][r]) {return;}

    // Mark as visited
    dp[round][l][r] = true;

    if (l > r) {
        dfs(round, n, r, l);
        return;
    }

    // Two player compete -> update min and max round possible
    if (l == r) {
        minRound = min(minRound, round);
        maxRound = max(maxRound, round);
        return;
    }

    int half = (n + 1) / 2, iMax = min(l, half);
    // Possible players at left side win this round (contain firstPlayer)
    for (int i = 1; i <= iMax; i++) {
        // Possible players at right side win this round (contain secondPlayer)
        for (int j = min(r, half) - i; j >= l - i + 1; j--) {
            if (l + r - (i + j) <= n / 2) { // Check valid #winner
                dfs(round + 1, half, i, j);
            }
        }
    }
}

int* earliestAndLatest(int n, int firstPlayer, int secondPlayer, int* returnSize) {
    // Tracking the min, max round firstPlayer and secondPlayer competes using DP
    // We can know the result if the state is provided
    // {total players, players before firstPlayer, players after secondPlayer}
    // Initialize global variables
    minRound = 6, maxRound = 1;
    memset(dp, 0, sizeof(dp));
    *returnSize = 2;
    int *result = malloc(2 * sizeof(int));

    dfs(1, n, firstPlayer, n - secondPlayer + 1);
    result[0] = minRound, result[1] = maxRound;
    return result;
}
// @lc code=end

