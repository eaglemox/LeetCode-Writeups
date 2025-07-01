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
    for (int i = 1; word[i] != '\0'; i++) {
        if (word[i] == word[i-1]) {
            result++;
        }
    }

    return result;
}
// @lc code=end

