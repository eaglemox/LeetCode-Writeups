/*
 * @lc app=leetcode id=983 lang=c
 *
 * [983] Minimum Cost For Tickets
 */

// @lc code=start
#include <stdlib.h>
#include <string.h>
#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)

int min3(int a, int b, int c) {
    return min(a, min(b, c));
}

int mincostTickets(int* days, int daysSize, int* costs, int costsSize) {
    // Find the minimum costs at each travel day and perform DP on it
    // Time: O(N), Space: O(N), N: lastDay
    int lastDay = days[daysSize-1], dp[lastDay+1]; // [0, lastDay]
    memset(dp, 0, sizeof(dp));
    for (int i = 1, j = 0; i <= lastDay; i++) {
        int travelDay = days[j];
        if (i != travelDay) {
            dp[i] = dp[i-1];
        } else {
            dp[i] = min3(dp[i-1] + costs[0], dp[max(0,i-7)] + costs[1], dp[max(0,i-30)] + costs[2]);
            j++;
        }
    }
    return dp[lastDay];
}
// @lc code=end

