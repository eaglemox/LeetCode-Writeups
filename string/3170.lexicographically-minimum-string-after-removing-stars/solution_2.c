/*
 * @lc app=leetcode id=3170 lang=c
 *
 * [3170] Lexicographically Minimum String After Removing Stars
 */

// @lc code=start
#include <string.h>

char* clearStars(char* s) {
    // 2D Array record index of character appearance
    int len = strlen(s), pos[26][len], numLetters[26] = {0};

    for (int i = 0; i < len; i++) {
        if (s[i] == '*') {
            int min = 0;
            while (min < 26 && !numLetters[min]) {min++;}

            // First calculate index of last min character then decrement #letter
            s[pos[min][(numLetters[min]--)-1]] = '*';
        } else {
            int letterIdx = s[i] - 'a';
            pos[letterIdx][numLetters[letterIdx]++] = i;
        }
    }

    int j = 0;
    for (int i = 0; i < len; i++) {
        // Ignore all characters to be removed
        if (s[i] != '*') {s[j++] = s[i];}
    }
    s[j] = '\0';

    return s;
}
// @lc code=end

