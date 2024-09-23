/*
 * @lc app=leetcode id=2707 lang=c
 *
 * [2707] Extra Characters in a String
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define min(a, b) ((a < b) ? a : b)
int minExtraChar(char * s, char ** dictionary, int dictionarySize){
    // ref: https://tinyurl.com/5m7s3d9j
    // Length of s = N, dictionary = M
    // Time: O(M*N^2) Space: O(N)
    int length = strlen(s);
    int dp[length]; // record the number of extra characters

    for (int i = 0; i < length; i++) {
        // if cannot match any string in the dictionary
        int extraChars = (i == 0) ? 1 : dp[i-1] + 1;

        for (int j = 0; j <= i; j++) {
            // compare s[j:i] and strings in the dictionary
            int subLen = i - j + 1;
            char *substring = malloc((subLen + 1) * sizeof(char));
            strncpy(substring, s + j, subLen);
            substring[subLen] = '\0'; // add terminator
            // printf("%s\n", substring);

            for (int k = 0; k < dictionarySize; k++) {
                if (!strcmp(substring, dictionary[k])) {
                    /* Postfix matched! -> extra characters is the same as the prefix
                     * e.g. s = "leet" dict = ["et", "t"], dp[] = [1,2,3,?]
                     * init extraChars = 4 -> ["leet", "eet"] didn't match, extraChars remains the same
                     * "et" matched -> extraChars = extraChars of prefix "le" = 2
                     * "t" matched -> extraChars min(2, "lee" = 3) = 2, remain the minimum 
                     */ 
                    if (j > 0) {
                        extraChars = min(extraChars, dp[j-1]);
                    } else { // if first character match
                        extraChars = 0;
                    }
                }
            }
            free(substring); // release space
        }
        dp[i] = extraChars;
    }
    // display result
    // for (int i = 0; i < length; i++) {
    //     printf("%c ", s[i]);
    // } printf("\n");
    // for (int i = 0; i < length; i++) {
    //     printf("%d ", dp[i]);
    // } printf("\n");

    return dp[length-1];
}
// @lc code=end

