/*
 * @lc app=leetcode id=2696 lang=c
 *
 * [2696] Minimum String Length After Removing Substrings
 */

// @lc code=start
#include <string.h>

int minLength(char * s){
    int len = strlen(s);
    if (len == 1) {return 1;}
    char *stack = malloc((len+1) * sizeof(char)); // terminator
    int top = -1;
    for (int i = 0; i < len; i++) {
        // &&: left condition -> right condition
        if (top >= 0 && (stack[top] == 'A' && s[i] == 'B' || stack[top] == 'C' && s[i] == 'D')) {
            top--;
        } else {
            stack[++top] = s[i];
        }
    }
    stack[++top] = '\0';
    free(stack);
    return top;
}
// @lc code=end

