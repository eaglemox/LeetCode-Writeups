/*
 * @lc app=leetcode id=2351 lang=c
 *
 * [2351] First Letter to Appear Twice
 */

// @lc code=start
#include <stdbool.h>

char repeatedCharacter(char* s) {
    // String only contain lowercase letters, track the count or seen
    // hashmap for each character. Return the first repeated character
    // Time: O(N), Space: O(1)
    bool seen[26] = {false};
    for (int i = 0; s[i] != '\0'; i++) {
        if (seen[s[i]-'a']) {return s[i];}
        seen[s[i]-'a'] = true;
    }
    return 0;
}
// @lc code=end

