/*
 * @lc app=leetcode id=2351 lang=c
 *
 * [2351] First Letter to Appear Twice
 */

// @lc code=start
char repeatedCharacter(char* s) {
    // Using a bitmask to track the appearance of each character
    // Time: O(N), Space: O(1)
    int seen = 0; // 32 bits variable
    for (int i = 0; s[i] != '\0'; i++) {
        int bitmask = 1 << (s[i] - 'a');
        if (seen & bitmask) {return s[i];}
        seen |= bitmask;
    }
    return 0;
}
// @lc code=end

