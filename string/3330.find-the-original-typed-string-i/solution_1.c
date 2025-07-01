/*
 * @lc app=leetcode id=3330 lang=c
 *
 * [3330] Find the Original Typed String I
 */

// @lc code=start
#include <string.h>

int possibleStringCount(char* word) {
    // Only "one" key press can cause multiple inputs, each letter segment result in length-1 possible strings
    int result = 1; // word is original string
    int len = strlen(word);
    for (int i = 1, start = 0; i < len; i++) {
        if (word[i] != word[start]) {
            result += (i - 1) - start;
            start = i;
        }
        if (i == len - 1) {
            result += i - start;
        }
    }

    return result;
}
// @lc code=end

