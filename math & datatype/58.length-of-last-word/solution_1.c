/*
 * @lc app=leetcode id=58 lang=c
 *
 * [58] Length of Last Word
 */

// @lc code=start
#include <stdio.h>
int lengthOfLastWord(char* s) {
    // forwardly counting each word
    int isStart = 0;
    int count;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != ' ') { 
            if (!isStart) {
                count = 1;
                isStart = 1;
            } else {count++;}
        } else {
            isStart = (isStart) ? 0 : isStart;
        }
        
        // printf("%c", s[i]);
    }
    return count;
}
// @lc code=end

