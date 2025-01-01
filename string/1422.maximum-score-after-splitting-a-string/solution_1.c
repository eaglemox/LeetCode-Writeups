/*
 * @lc app=leetcode id=1422 lang=c
 *
 * [1422] Maximum Score After Splitting a String
 */

// @lc code=start
#include <string.h>
#define max(a, b) ((a > b) ? a : b)

int maxScore(char* s) {
    // The score is left zeros + right ones. Track the number of left zeros
    // and right ones as start of right subarray move from 1 to size-1
    // Time: O(N), Space: O(1)
    int len = strlen(s);
    int leftZeros = 0, rightOnes = 0, result = 0;
    for (int i = 0; i < len; i++) {
        rightOnes += (s[i] == '1');
    }
    for (int i = 0; i < len - 1; i++) {
        if (s[i] == '1') {
            rightOnes--;
        } else {
            leftZeros++;
        }
        result = max(result, leftZeros + rightOnes);
    }
    return result;
}
// @lc code=end

