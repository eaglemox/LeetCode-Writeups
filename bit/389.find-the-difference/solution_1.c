/*
 * @lc app=leetcode id=389 lang=c
 *
 * [389] Find the Difference
 */

// @lc code=start
#include <string.h>

char findTheDifference(char* s, char* t) {
    // Count number of characters, only lowercase english letters (26)
    // Time: O(N), Space: O(26)
    unsigned short frequency[26];
    for (int i = 0; s[i] != '\0'; i++) {
        frequency[s[i]-'a']++;
    }
    for (int i = 0; t[i] != '\0'; i++) {
        if (frequency[t[i]-'a'] == 0) {return t[i];}
        frequency[t[i]-'a']--;
    }
    return '#'; // should never reach
}
// @lc code=end

