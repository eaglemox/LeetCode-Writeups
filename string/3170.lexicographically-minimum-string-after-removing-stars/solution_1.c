/*
 * @lc app=leetcode id=3170 lang=c
 *
 * [3170] Lexicographically Minimum String After Removing Stars
 */

// @lc code=start
#include <string.h>

char* clearStars(char* s) {
    // Naive iteration -> TLE
    int len = strlen(s), count[26] = {};
    char smallest = 'a';
    for (int i = 0; i < len;) {
        if (s[i] == '*') {
            // Smallest character at the LHS of '*'
            while (smallest < 'z' && !count[smallest-'a']) {smallest++;}
            
            // Find rightmost smallest character
            int j = i - 1;
            while (j > 0 && s[j] != smallest) {j--;}

            // Remove character and '*'
            len -= 2;
            count[smallest-'a']--;
            for (; j < len; j++) {
                s[j] = (j < i - 1) ? s[j+1] : s[j+2];
            }

            s[j] = '\0';
            
            i--; // Move back to previous index -> character after '*'
        } else {
            count[s[i]-'a']++;
            i++;
        }
    }

    return s;
}
// @lc code=end

