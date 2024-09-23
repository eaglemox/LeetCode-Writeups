/*
 * @lc app=leetcode id=2707 lang=c
 *
 * [2707] Extra Characters in a String
 */

// @lc code=start
#include <stdio.h>
#include <string.h>
#define min(a, b) ((a < b) ? a : b)

int dp[51];
int minExtra(char* s, char** dict, int dictSize, int idx) {
    if (idx == strlen(s)) {return 0;} // end
    if (dp[idx] == -1) { // not assigned
        //  l,e,e,t,s,c,o,d,e
        // [9,8,7,6,5,4,3,2,1,0]
        dp[idx] = 1 + minExtra(s, dict, dictSize, idx + 1);
        printf("compare string: %s\n", s+idx);
        for (int i = 0; i < dictSize; i++) {
            int wlength = strlen(dict[i]);
            // printf("%s, %d\n", dict[i], wlength);
            if (!strncmp(s + idx, dict[i], wlength)) {
                dp[idx] = min(dp[idx], minExtra(s, dict, dictSize, idx + wlength));
            }
        }
    }
    return dp[idx];
}
int minExtraChar(char * s, char ** dictionary, int dictionarySize){
    // top-down
    for (int i = 0; i < 51; i++) {dp[i] = -1;}
    int result = minExtra(s, dictionary, dictionarySize, 0);
    int length = strlen(s);

    // display result
    for (int i = 0; i < length; i++) {
        printf("%c ", s[i]);
    } printf("\n");
    for (int i = 0; i < length; i++) {
        printf("%d ", dp[i]);
    } printf("\n");

    return result;
}
// @lc code=end

