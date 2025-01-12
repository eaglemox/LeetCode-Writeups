/*
 * @lc app=leetcode id=2116 lang=c
 *
 * [2116] Check if a Parentheses String Can Be Valid
 */

// @lc code=start
#include <string.h>
#include <stdbool.h>

bool canBeValid(char* s, char* locked) {
    // Check the number difference of open & closed parentheses from L2R pass and R2L pass
    // to ensure the string can be a valid parentheses expression
    // Time: O(N), Space: O(1)
    int len = strlen(s);
    if (len % 2) {return false;}
    // Left to right: check unlocked chars or locked '(' more than locked ')'
    int balance = 0;
    for (int i = 0; i < len; i++) {
        if (locked[i] == '0' || s[i] == '(') {
            balance++;
        } else {
            balance--;
        }
        if (balance < 0) {return false;}
    }
    // Right to left: check unlocked chars or locked ')' more than locked '('
    balance = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (locked[i] == '0' || s[i] == ')') {
            balance++;
        } else {
            balance--;
        }
        if (balance < 0) {return false;}
    }
    return true;
}
// @lc code=end

