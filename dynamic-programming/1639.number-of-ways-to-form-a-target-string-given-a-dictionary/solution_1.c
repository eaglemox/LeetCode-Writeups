/*
 * @lc app=leetcode id=1639 lang=c
 *
 * [1639] Number of Ways to Form a Target String Given a Dictionary
 */

// @lc code=start
#include <stdlib.h>
#include <string.h>
#define MOD 1000000007

int numWays(char** words, int wordsSize, char* target) {
    // Time: O(M*N), Space: O(M*N), M: target.legnth, N: words[i].length
    int wordLength = strlen(words[0]), targetLength = strlen(target);
    int **freq = malloc(wordLength * sizeof(int *));
    for (int i = 0; i < wordLength; i++) {
        freq[i] = malloc(26 * sizeof(int));
        for (int j = 0; j < 26; j++) {
            freq[i][j] = 0;
        }
    }
    for (int i = 0; i < wordsSize; i++) {
        for (int j = 0; j < wordLength; j++) {
            freq[j][words[i][j]-'a']++;
        }
    }
    // DP[i][j] to track ways to form target[:i] at word index j
    long long dp[targetLength][wordLength];
    // Base case and first character of the target
    for (int i = 0; i < targetLength; i++) {
        for (int j = 0; j < wordLength; j++) {
            if (i == 0) {
                dp[0][j] = freq[j][target[0]-'a'] % MOD;
                if (j > 0) {dp[0][j] = (dp[0][j] + dp[0][j-1]) % MOD;}
            } else {
                dp[i][j] = 0;
            }
        }
    }
    // Ways to form target[:i] up to index j
    // 1. Ways to form target[:i-1] up to index j-1 * words to choose at current index j 
    //    (frequency of target's i-th character)
    // 2. Sum of ways to form target[:i] of previous word index dp[i][j-1]
    for (int i = 1; i < targetLength; i++) {
        for (int j = i; j < wordLength; j++) {
            dp[i][j] = (dp[i-1][j-1] * freq[j][target[i]-'a']) % MOD;
            if (j > i) {dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;}
        }
    }
    return dp[targetLength-1][wordLength-1];
}
// @lc code=end

