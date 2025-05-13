/*
 * @lc app=leetcode id=3335 lang=c
 *
 * [3335] Total Characters in String After Transformations I
 */

// @lc code=start
#define MOD 1000000007
#define MAX_SIZE 100050

int lengthAfterTransformations(char* s, int t) {
    // Bottom up DP precompute length of character after transformed t times
    // dp: length table start from 'a'
    // 'z'(25)  -> 'ab'(26) length comes from 'a' (i=0) and 'b' (i=1)
    // 'yz'(50) -> 'zab'(51) length comes from 'z' (i=25) and 'ab' (i=26)
    int length = 0;
    int *dp = malloc(MAX_SIZE * sizeof(int));
    
    for (int i = 0; i < 26; i++) {
        dp[i] = 1;
    }
    for (int i = 26; i < MAX_SIZE; i++) {
        dp[i] = (dp[i-26] + dp[i-26+1]) % MOD;
    }
    
    for (int i = 0; s[i]; i++) {
        length = (length + dp[s[i]-'a'+t]) % MOD;
    }

    return length;
}
// @lc code=end

