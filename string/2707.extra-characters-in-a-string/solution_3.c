/*
 * @lc app=leetcode id=2707 lang=c
 *
 * [2707] Extra Characters in a String
 */

// @lc code=start
#include <stdio.h>
#include <string.h>
#define min(a, b) ((a < b) ? a : b)
int minExtraChar(char * s, char ** dictionary, int dictionarySize){
    // bottom-up
    int dp[51], length = strlen(s);
    dp[length] = 0;
    for (int i = length - 1; i >= 0; i--) {
        dp[i] = 1 + dp[i+1];
        for (int j = 0; j < dictionarySize; j++) {
            int wlength = strlen(dictionary[j]);
            if (!strncmp(s + i, dictionary[j], wlength)) {
                dp[i] = min(dp[i], dp[i+wlength]);
            }
        }
    }
    // display result
    // for (int i = 0; i < length; i++) {
    //     printf("%c ", s[i]);
    // } printf("\n");
    // for (int i = 0; i < length; i++) {
    //     printf("%d ", dp[i]);
    // } printf("\n");

    return dp[0];
}
// @lc code=end

