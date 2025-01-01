/*
 * @lc app=leetcode id=1422 lang=c
 *
 * [1422] Maximum Score After Splitting a String
 */

// @lc code=start
#include <stdlib.h>
#include <string.h>
#define max(a, b) ((a > b) ? a : b)

int maxScore(char* s) {
    // Optimize the computation for number of zeros and ones to find result in one pass
    // Time: O(N), Space: O(1)
    int len = strlen(s);
    int leftZeros = 0, rightOnes = 0, leftBest = INT_MIN;
    // Use leftBest to track the best split position to have leftZeros-leftOnes of s[:i] maximized
    for (int i = 0; i < len - 1; i++) {
        if (s[i] == '1') {
            rightOnes++;
        } else {
            leftZeros++;
        }
        leftBest = max(leftBest, leftZeros - rightOnes);
    }
    // the subarray must not be empty
    if (s[len-1] == '1') {rightOnes++;}
    return leftBest + rightOnes;
}
// @lc code=end

