/*
 * @lc app=leetcode id=20 lang=c
 *
 * [20] Valid Parentheses
 */

// @lc code=start
#include <string.h>
#include <stdbool.h>

bool isValid(char* s) {
    // Simulate the stack, pop parenthesis pair when match
    // Time: O(N), Space: O(N)
    int length = strlen(s), top = -1;
    char *stack = malloc(length * sizeof(char));
    for (int i = 0; i < length; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            stack[++top] = s[i];
        } else {
            if (top < 0) {return false;} // cannot match
            if (s[i] == ')') {
                if (top >= 0 && stack[top] != '(') {return false;}
                else {top--;}
            } else if (s[i] == ']') {
                if (top >= 0 && stack[top] != '[') {return false;}
                else {top--;}
            } else if (s[i] == '}') {
                if (top >= 0 && stack[top] != '{') {return false;}
                else {top--;}
            }
        }
    }
    return top == -1;
}
// @lc code=end

