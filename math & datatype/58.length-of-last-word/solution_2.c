/*
 * @lc app=leetcode id=58 lang=c
 *
 * [58] Length of Last Word
 */

// @lc code=start
#include <stdio.h>
#include <string.h>
int lengthOfLastWord(char* s) {
    int length = 0, counting = 0;
    for (int i = strlen(s) - 1; i >= 0; i--) {
        if (s[i] != ' ') { 
            length++;
            counting = 1;
        } 
        // if white space appear after we're counting length,
        // the current length is the length of last word
        else if (counting) {break;}
    }
    return length;
}
// @lc code=end

